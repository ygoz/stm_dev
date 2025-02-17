/*
 * post_router.c
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */


#include <string.h>
#include "lwip/api.h" // For netconn functions
#include "http/request_parser/extract_http_header_segment.h"
#include "http/request_parser/connect_http_body_segments.h"
#include "http/routers/post_router.h"




const char http_header[] =
	"HTTP/1.1 200 OK\r\n"
	"Content-Type: text/plain\r\n"
	"Content-Length: 10\r\n"
	"Connection: close\r\n"
	"\r\n";
//
//const char response_body[] = "hello this is http";

const char message[] = "this is go";


void POST_requests_router(struct netconn *conn){
	if (strncmp(http_header_buffer, "POST /postTest", 14) == 0) {
		netconn_write(conn, http_header, strlen(http_header), NETCONN_NOCOPY);
		netconn_write(conn, message, strlen(message), NETCONN_NOCOPY);
	}
}
