/*
 * get_router.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#include "lwip/api.h" // For netconn functions


#ifndef INC_HTTP_ROUTERS_GET_ROUTER_H_
#define INC_HTTP_ROUTERS_GET_ROUTER_H_


void GET_requests_router(struct netconn *conn);

#endif /* INC_HTTP_ROUTERS_GET_ROUTER_H_ */
