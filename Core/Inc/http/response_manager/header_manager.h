/*
 * utils.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yam
 */

#ifndef INC_HTTP_ROUTERS_UTILS_H_
#define INC_HTTP_ROUTERS_UTILS_H_

#include "http/response_manager/status_codes.h"


static const size_t header_size = 256; // Estimated buffer size


// Function to create HTTP header dynamically
char* create_http_header(HttpStatusCode status_code, size_t content_length);

#endif /* INC_HTTP_ROUTERS_UTILS_H_ */
