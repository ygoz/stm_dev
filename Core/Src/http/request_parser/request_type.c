/*
 * request_type.c
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */

#include "string.h"
#include "http/request_parser/request_type.h"


HttpRequestType get_request_type(char *request_header) {
    if (strncmp(request_header, "GET", 3u) == 0) {
        return HTTP_GET;
    } else if (strncmp(request_header, "POST", 4u) == 0) {
        return HTTP_POST;
    } else if (strncmp(request_header, "PUT", 3u) == 0) {
        return HTTP_PUT;
    } else if (strncmp(request_header, "DELETE", 6u) == 0) {
        return HTTP_DELETE;
    }
    return -1; // Unknown request type
}


// EXAMPLE: use this when sending each request to its router to handle
// - GET requests: DO NOT SEND Content-len in headers
// - POST, PUT, DELETE? requests: DO SEND Content-len in headers
/*


HttpRequestType requestType = get_request_type(request_data);
if (requestType == HTTP_POST) {
    // Handle POST request
} else if (requestType == HTTP_GET) {
    // Handle GET request
}
......


 */



