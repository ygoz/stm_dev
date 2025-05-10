/*
 * request_type.h
 *
 *  Created on: Feb 12, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_REQUEST_TYPE_H_
#define INC_HTTP_REQUEST_TYPE_H_


typedef enum {
    HTTP_GET = 0,
    HTTP_POST = 1,
    HTTP_PUT = 2,
    HTTP_DELETE = 3
} HttpRequestType;


HttpRequestType get_request_type(char *request_header);

#endif /* INC_HTTP_REQUEST_TYPE_H_ */
