/*
 * http_write_response.h
 *
 *  Created on: Feb 18, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_RESPONSE_MANAGER_HTTP_WRITE_RESPONSE_H_
#define INC_HTTP_RESPONSE_MANAGER_HTTP_WRITE_RESPONSE_H_


#include "http/response_manager/status_codes.h"

void http_write_response(struct netconn *conn, HttpStatusCode status_code, char * message);

#endif /* INC_HTTP_RESPONSE_MANAGER_HTTP_WRITE_RESPONSE_H_ */
