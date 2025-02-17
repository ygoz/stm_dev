#include <string.h>
#include "lwip/api.h" // For netconn functions
#include "http/request_parser/extract_http_header_segment.h"
#include "http/routers/get_router.h"
//const char end_of_http_headers[]= "\r\n\r\n";
//
//const char http_header[] =
//	"HTTP/1.1 200 OK\r\n"
//	"Content-Type: text/plain\r\n"
//	"Content-Length: 18\r\n"
//	"Connection: close\r\n"
//	"\r\n";
//
//const char response_body[] = "hello this is http";
//
//
const char http_post_response[] =
                        "HTTP/1.1 200 OK\r\n"
                        "Content-Type: application/json\r\n"
                        "Content-Length: 15\r\n"
                        "\r\n"
                        "{\"status\":\"OK\"}";
















void GET_requests_router(struct netconn *conn){
	if (strncmp(http_header_buffer, "GET /index.html", 15) == 0) {
		netconn_write(conn, http_post_response, strlen(http_post_response), NETCONN_NOCOPY);
	}
}
