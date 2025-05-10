/*
 * request_handler.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_ROUTERS_MAIN_ROUTER_H_
#define INC_HTTP_ROUTERS_MAIN_ROUTER_H_



#include "http/request_parser/request_type.h"
#include "lwip/api.h"

void handle_request(struct netconn *conn, HttpRequestType request_type);

#endif /* INC_HTTP_MAIN_ROUTER_H_ */
