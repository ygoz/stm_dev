///*
// * utils.c
// *
// *  Created on: Feb 13, 2025
// *      Author: yam
// */
//
//
//const char *content = "Hello World";
//char *header = create_http_header(200, "OK", content);
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//// Function to create HTTP header dynamically
//char* create_http_header(int status_code, const char *status_message, const char *content) {
//    // Allocate memory for the header string
//    // Start with some estimated size for the header
//    size_t content_length = strlen(content);
//    size_t header_size = 256 + content_length; // Estimated buffer size
//
//    // Allocate the memory to store the header
//    char *header = (char *)malloc(header_size);
//
//    if (header == NULL) {
//        return NULL; // Memory allocation failure
//    }
//
//    // Prepare the status line and headers
//    snprintf(header, header_size,
//             "HTTP/1.1 %d %s\r\n"         // Status Line
//             "Content-Type: text/plain\r\n" // Content-Type (hardcoded as text/plain)
//             "Content-Length: %zu\r\n"     // Content-Length header based on content size
//             "Connection: close\r\n"       // Connection: close (for this example)
//             "\r\n",                      // Blank line to separate headers from body
//             status_code, status_message, content_length);
//
//    return header;
//}
