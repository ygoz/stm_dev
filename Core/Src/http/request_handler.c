/*
 * request_handler.c
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#include "http/request_type.h"


// Function to handle the request based on the type
void handle_request(HttpRequestType request_type) {
	int counter = 0;
    switch (request_type) {
        case HTTP_GET:
            // Add GET-specific logic here
            break;

        case HTTP_POST:
        	counter++;
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
