/*
 * connect_http_segments.h
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_CONNECT_HTTP_BODY_SEGMENTS_H_
#define INC_HTTP_CONNECT_HTTP_BODY_SEGMENTS_H_


#define HTTP_BODY_BUFFER_SIZE 32768u  // Adjust based on expected body size

// Buffer to store incoming HTTP body data
extern char http_body_buffer[HTTP_BODY_BUFFER_SIZE];

// Function to receive HTTP body after headers
int receive_http_body(struct netconn *conn, int content_length, struct netbuf *network_buffer, char *rx_buffer, u16_t rx_buflen, err_t recv_err);

#endif /* INC_HTTP_CONNECT_HTTP_BODY_SEGMENTS_H_ */
