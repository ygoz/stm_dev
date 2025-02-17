/*
 * extract_http_header_segment.c
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_EXTRACT_HTTP_HEADER_SEGMENT_H_
#define INC_HTTP_EXTRACT_HTTP_HEADER_SEGMENT_H_


#include "http/request_parser/request_type.h"
#include <stdint.h>  // For standard types
#include "lwip/api.h" // For netconn functions

#define HTTP_HEADER_BUFFER_SIZE 512u  // Adjust based on expected body size

// Buffer to store incoming HTTP header data
extern char http_header_buffer[HTTP_HEADER_BUFFER_SIZE];

HttpRequestType receive_http_header(struct netconn *conn, struct netbuf *network_buffer, char *rx_buffer, u16_t rx_buflen, err_t recv_err);

int extract_content_len(void);


#endif /* INC_HTTP_EXTRACT_HTTP_HEADER_SEGMENT_H_ */
