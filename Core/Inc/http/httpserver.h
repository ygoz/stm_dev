/*
 * httpserver.h
 *
 *  Created on: Feb 10, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_HTTPSERVER_H_
#define INC_HTTP_HTTPSERVER_H_

#include "lwip/api.h"

extern osThreadId_t httpThreadHandle;
extern const osThreadAttr_t httpTask_attributes;

void http_server_init(void *arg);
void http_thread(void *arg);

#endif /* INC_HTTPSERVER_H_ */
