/*
 * utils.c
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "http/response_manager/status_codes.h"
#include "http/response_manager/header_manager.h"



// Function to create HTTP header dynamically
char* create_http_header(HttpStatusCode status_code, size_t content_length) {
    // Allocate memory for the header string
    char *status_message = get_status_message(status_code);

    // Allocate the memory to store the header
    char *header = (char *)malloc(header_size);
    //char *header = (char *)calloc(header_size, sizeof(char));

    if (header == NULL) {
        return NULL; // Memory allocation failure
    }

    // Prepare the status line and headers
    snprintf(header, header_size,
             "HTTP/1.1 %d %s\r\n"         // Status Line
             "Content-Type: text/plain\r\n" // Content-Type (hardcoded as text/plain)
             "Content-Length: %lu\r\n"     // Content-Length header based on content size
    		 "Connection: keep-alive\r\n"
    		//"Connection: close\r\n"       // Connection: close (for this example)
             "\r\n",                      // Blank line to separate headers from body
             status_code, status_message, (unsigned long)content_length);


    free(status_message);

    return header;
}
