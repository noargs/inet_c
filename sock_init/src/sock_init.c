#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>

// pragma ignored except Microsoft Visual C compiler
// for MinGW pass "-lws2_32" during compilation ie. $ gcc socket_init.c -o sock_init.exe -lws2_32
#pragma comment(lib, "ws2_32.lib")

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#include <stdio.h>

int main(void) {

#if defined(_WIN32)
	WSDATA 	d;
	if (WSAStartup(MAKEWORD(2, 2), &d)) { // "MAKWORD" macro allow us to request "Winsock version 2.2"
		fprintf(stderr, "Failed to initialize.\n");
		return 1;
	}
#endif

	printf("Ready to use socket API.\n");

#if defined(_WIN32)
	WSACleanup();
#endif
	return 0;
}
