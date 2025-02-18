/*
 * status_codes.c
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http/response_manager/status_codes.h"

// Enum for HTTP status codes


// Function to get the status message based on the status code
char* get_status_message(HttpStatusCode code) {
    char *message = malloc(64);  // Allocate memory for the message (adjust size as needed)

    if (message == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    switch (code) {
        case HTTP_OK:
            strcpy(message, "OK");
            break;
        case HTTP_BAD_REQUEST:
            strcpy(message, "Bad Request");
            break;
        case HTTP_UNPROCESSABLE:
            strcpy(message, "Unprocessable Entity");
            break;
        case HTTP_NOT_FOUND:
            strcpy(message, "Not Found");
            break;
        case HTTP_INTERNAL_ERROR:
            strcpy(message, "Internal Server Error");
            break;
        default:
            strcpy(message, "Unknown Status");
            break;
    }
    return message; // free this var after use!
}
// Example usage
//int main() {
//    HttpStatusCode code = HTTP_OK;
//    const char* message = get_status_message(code);
//    printf("Status Code: %d, Message: %s\n", code, message);
//
//    return 0;
//}
