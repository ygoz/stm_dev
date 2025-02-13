/*
 * request_handler.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_REQUEST_HANDLER_H_
#define INC_HTTP_REQUEST_HANDLER_H_

void handle_request(struct netconn *conn, HttpRequestType request_type);

#endif /* INC_HTTP_REQUEST_HANDLER_H_ */
