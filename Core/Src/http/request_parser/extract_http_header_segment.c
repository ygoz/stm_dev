/*
 * extract_http_header_segment.c
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */

#include <string.h>  // For memcpy
#include <stdint.h>  // For standard types
#include "lwip/api.h" // For netconn functions
#include "http/request_parser/request_type.h"
#include "http/request_parser/extract_http_header_segment.h"


char http_header_buffer[HTTP_HEADER_BUFFER_SIZE];



HttpRequestType receive_http_header(struct netconn *conn,struct netbuf *network_buffer, char *rx_buffer, u16_t rx_buflen, err_t recv_err) {

    memset(http_header_buffer, 0, sizeof(http_header_buffer)); // Clear buffer, makes sure the buffer is empty before writing new data

	// get header
    recv_err = netconn_recv(conn, &network_buffer);
	netbuf_data(network_buffer, (void**)&rx_buffer, &rx_buflen);
	// set header in static buffer
	memcpy(http_header_buffer, rx_buffer, rx_buflen);


	netbuf_delete(network_buffer);

	// return type
	return get_request_type(http_header_buffer);
}

int extract_content_len(void){
	int content_length = 0;
	char *content_length_header = strstr(http_header_buffer, "Content-Length:");
	if (content_length_header) {
		content_length = atoi(content_length_header + 15);
	}
	return content_length;
}
