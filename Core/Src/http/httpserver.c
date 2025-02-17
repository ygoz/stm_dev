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
#include "http/httpserver.h"
#include "cmsis_os.h"
#include "main.h"

#include "http/routers/main_router.h"
#include "http/request_parser/connect_http_body_segments.h"
#include "http/request_parser/extract_http_header_segment.h"


osThreadId_t httpThreadHandle;
const osThreadAttr_t httpTask_attributes = {
    .name = "http_thread",
    .stack_size = 4096,
    .priority = (osPriority_t) osPriorityNormal,
};



static void http_server(struct netconn *conn)
{
	/*
	 * Receives the clients connection - conn
	 * receives the first TCP segment of the HTTP request, the header
	 * extracts the request_type from the header - GET, PUT, POST, DELETE
	 * 		HTTP_GET does not have a body, therefore the header does not contain content length property
	 * extracts content length from the header
	 * keep listening to incoming TCP segments until the body is the same size as the content length
	 * handles the request based on it's type
	 * closes + deletes the client connection, conn.
	 */
	struct netbuf *network_buffer; //  = netbuf_new()
	err_t recv_err = ERR_OK;
	char* rx_buffer = NULL;
	u16_t rx_buflen = 0u;
	int content_length = 0u;
	HttpRequestType request_type;

	request_type = receive_http_header(conn, network_buffer, rx_buffer, rx_buflen, recv_err);
	// HTTP_GET should not have a body therefore do not have content len inside the headers
	if (request_type != HTTP_GET){
		content_length = extract_content_len();
		(void)receive_http_body(conn, content_length, network_buffer, rx_buffer, rx_buflen, recv_err);
	}
	// send to router
	handle_request(conn, request_type);
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
