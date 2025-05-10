/*
 * request_handler.c
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#include "http/request_parser/request_type.h"
#include "http/routers/get_router.h"
#include "http/routers/post_router.h"

// Function to handle the request based on the type
void handle_request(struct netconn *conn, HttpRequestType request_type) {

    switch (request_type) {
        case HTTP_GET:
        	GET_requests_router(conn);
            break;

        case HTTP_POST:
        	POST_requests_router(conn);
            // Add POST-specific logic here
            break;

        case HTTP_PUT:
            // Add PUT-specific logic here
            break;

        case HTTP_DELETE:
            // Add DELETE-specific logic here
            break;

        default:
            break;
    }
}
