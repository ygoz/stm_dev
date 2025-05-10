#include <string.h>  // For memcpy
#include <stdint.h>  // For standard types
#include "lwip/api.h" // For netconn functions
#include "http/request_parser/connect_http_body_segments.h"



//This global buffer stores the HTTP body as it's received.
//It's cleared before each use to prevent leftover data from previous requests.
char http_body_buffer[HTTP_BODY_BUFFER_SIZE];




int receive_http_body(struct netconn *conn, int content_length,struct netbuf *network_buffer, char *rx_buffer, u16_t rx_buflen, err_t recv_err) {
	/*

	 @args:
	 	 * conn - Pointer to the TCP connection object from LWIP.
	 	 * content_length - The expected size of the HTTP body, extracted from the Content-Length header.
	 	 *

	This function reads the HTTP request body from an LWIP netconn connection.
	It keeps receiving data packets until it has received the full body.
	It stores the received data in http_body_buffer and ensures no buffer overflow.

	MAKE SURE THIS FUNCTION IN NOT USED CONCURRENTLY, CONTROLLED BY SEMAPHORE

	 */

	// create buffers and counters to keep track of incoming tcp segments
//    struct netbuf *network_buffer; // LWIP netbuf structure that stores received TCP data.

    int total_received = 0;

    memset(http_body_buffer, 0, sizeof(http_body_buffer)); // Clear buffer, makes sure the buffer is empty before writing new data

    // Loops until we've received content_length bytes:
    while (recv_err == ERR_OK) {
    	recv_err = netconn_recv(conn, &network_buffer);

        netbuf_data(network_buffer, (void**)&rx_buffer, &rx_buflen); //extracts the data buffer (buf) and its length (buflen) from inbuf

        // Ensure we don't overflow the buffer TODO - raise HTTP EXCEPTION for OVERFLOW INSTEAD

        // rx_buflen bytes from rx_buffer into http_body_buffer at total_received position
        memcpy(http_body_buffer + total_received, rx_buffer, rx_buflen);
        total_received += rx_buflen;

        netbuf_delete(network_buffer); // Free the buffer

        // If we've received everything, exit
        if (total_received >= content_length) {
            break;
        }
    }

    return total_received;  // Return the actual received size
}
