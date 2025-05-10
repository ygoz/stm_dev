/*
 * http_write_response.c
 *
 *  Created on: Feb 18, 2025
 *      Author: yam
 */

#include <string.h>
#include "lwip/api.h" // For netconn functions
#include "http/response_manager/header_manager.h"


void http_write_response(struct netconn *conn, HttpStatusCode status_code, char * message){

	char *http_header = create_http_header(HTTP_OK, strlen(message));

	netconn_write(conn, http_header, strlen(http_header), NETCONN_COPY);
	netconn_write(conn, message, strlen(message), NETCONN_COPY);

	if (http_header) {
	    free(http_header);
	}
//	if (message) {
//		    free(message);
//		}
}
