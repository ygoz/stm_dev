/*
 * httpserver.c
 *
 *  Created on: Feb 10, 2025
 *      Author: yam
 */



/* Includes ------------------------------------------------------------------*/
#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "string.h"
#include <stdio.h>
#include "httpserver.h"
#include "cmsis_os.h"
#include "main.h"
#include "http/connect_http_body_segments.h"


osThreadId_t httpThreadHandle;
const osThreadAttr_t httpTask_attributes = {
    .name = "http_thread",
    .stack_size = 4096,
    .priority = (osPriority_t) osPriorityNormal,
};

// buffer for incoming segments
static char request_data[1024] = {0}; // WHERE DOS
static int total_len = 0;
const char end_of_http_headers[]= "\r\n\r\n";

const char http_header[] =
	"HTTP/1.1 200 OK\r\n"
	"Content-Type: text/plain\r\n"
	"Content-Length: 18\r\n"
	"Connection: close\r\n"
	"\r\n";

const char response_body[] = "hello this is http";


const char http_post_response[] =
                        "HTTP/1.1 200 OK\r\n"
                        "Content-Type: application/json\r\n"
                        "Content-Length: 17\r\n"
                        "\r\n"
                        "{\"status\":\"OK\"}";

static void http_server(struct netconn *conn)
{
	struct netbuf *network_buffer;
	err_t recv_err;
	char* rx_buffer;
	u16_t rx_buflen;

	int content_length = 0;
	char *body_start = NULL;
	int counter = 0;
	/* Read the data from the port, blocking if nothing yet there */


//	testing -- WORKS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	recv_err = netconn_recv(conn, &network_buffer);
	            netbuf_data(network_buffer, (void**)&rx_buffer, &rx_buflen);

				char *content_length_header = strstr(rx_buffer, "Content-Length:");
				if (content_length_header) {
					content_length = atoi(content_length_header + 15);
				}


(void)receive_http_body(conn, content_length, network_buffer, rx_buffer, rx_buflen);
	//	testing -- WORKS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++










	if (recv_err == ERR_OK)
	{
		if (netconn_err(conn) == ERR_OK)
		{
			/* Get the data pointer and length of the data inside a netbuf */
			netbuf_data(network_buffer, (void**)&rx_buffer, &rx_buflen);

			/* Check if request to get the index.html */
			if (strncmp((char const *)rx_buffer, "GET /index.html", 15) == 0) {


			    netconn_write(conn, http_header, strlen(http_header), NETCONN_NOCOPY);
			    netconn_write(conn, response_body, strlen(response_body), NETCONN_NOCOPY);

			}
			else if (strncmp(rx_buffer, "POST /postTest", 14) == 0) {

				char *body_start = strstr(rx_buffer, "\r\n\r\n");
				if (body_start) {
					body_start += 4;  // Move past "\r\n\r\n"

					// Extract key value (simple parsing)
					int key_value = -1;
					char *key_ptr = strstr(body_start, "\"key\":");
					if (key_ptr) {
						key_value = atoi(key_ptr + 6);  // Convert number to int
						printf("Extracted key value: %d\n", key_value);
					}


					netconn_write(conn, http_post_response, strlen(http_post_response), NETCONN_NOCOPY);
				}
			}

			else
			{
				/* Load Error page */
//				netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
//				fs_close(&file);
			}
		}
	}
	/* Close the connection (server closes in HTTP) */
	netconn_close(conn);

	/* Delete the buffer (netconn_recv gives us ownership,
   so we have to make sure to deallocate the buffer) */
	netbuf_delete(network_buffer);

	//TODO //	netconn_close(newconn);
//	        netconn_delete(newconn);
//	        netbuf_delete(network_buffer);
}


void http_thread(void *arg)
{
  struct netconn *conn, *newconn;
  err_t err, accept_err;

  /* Create a new TCP connection handle */
  conn = netconn_new(NETCONN_TCP);

  if (conn!= NULL)
  {
    /* Bind to port 80 (HTTP) with default IP address */
    err = netconn_bind(conn, IP_ADDR_ANY, 80);

    if (err == ERR_OK)
    {
      /* Put the connection into LISTEN state */
      netconn_listen(conn);

      while(1)
      {
        /* accept any incoming connection */
        accept_err = netconn_accept(conn, &newconn);
        if(accept_err == ERR_OK)
        {
          /* serve connection */
          http_server(newconn);

          /* delete connection */
          netconn_close(newconn);
          netconn_delete(newconn);
        }
      }
    }
  }

}


void http_server_init(void *arg)
{
  osSemaphoreAcquire(startDefaultTaskSemaphore, osWaitForever);
  sys_thread_new("http_thread", http_thread, NULL, 2048, osPriorityNormal);
}

//void http_server_thread_init()
//{
//	http_thread(*arg);
//}
