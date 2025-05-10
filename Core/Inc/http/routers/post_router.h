/*
 * post_router.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_ROUTERS_POST_ROUTER_H_
#define INC_HTTP_ROUTERS_POST_ROUTER_H_

#include "lwip/api.h" // For netconn functions

void POST_requests_router(struct netconn *conn);

#endif /* INC_HTTP_ROUTERS_POST_ROUTER_H_ */
