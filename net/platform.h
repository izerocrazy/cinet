#ifndef __PLATFORM_SOCKET_H__
#define __PLATFORM_SOCKET_H__

#ifdef WIN32
#else
#include <netinet/in.h> // base struct
#include <sys/socket.h> // base function
#include <arpa/inet.h>
#endif

// windows has,linux no
#ifndef SOCKET
	#define SOCKET unsigned int
#endif

#ifndef INVALID_SOCKET
	#define INVALID_SOCKET (SOCKET)(~0)
#endif

#ifndef SOCKET_ERROR
	#define SOCKET_ERROR -1
#endif

#ifndef SOCKET_STREAM
	#define SOCKET_STREAM SOCK_STREAM
#endif

#ifndef ADDR_ANY
	#define ADDR_ANY INADDR_ANY
#endif

#endif