/*
 * status_codes.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_ROUTERS_STATUS_CODES_H_
#define INC_HTTP_ROUTERS_STATUS_CODES_H_

typedef enum {
    HTTP_OK = 200,          // OK
    HTTP_BAD_REQUEST = 400, // Bad Request
    HTTP_UNPROCESSABLE = 422, // Unprocessable Entity
    HTTP_NOT_FOUND = 404,   // Not Found
    HTTP_INTERNAL_ERROR = 500 // Internal Server Error
} HttpStatusCode;


char* get_status_message(HttpStatusCode code);

#endif /* INC_HTTP_ROUTERS_STATUS_CODES_H_ */
