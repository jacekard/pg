#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


DWORD WINAPI input(void* buffer) {
	char *buff = (char*) buffer;

	while (TRUE) {
		gets(buffer);
		if (buff[0] == 'q') break;
	}
	return 0;
}

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(void) {
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	ZeroMemory(&recvbuf, sizeof(recvbuf));
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);

	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);

	// No longer need server socket
	closesocket(ListenSocket);

	char buffer[] = "22123412341234123498123456";
	CreateThread(NULL, NULL, input, buffer, NULL, NULL);
	// Receive until the peer shuts down the connection
	do {
		iResult = recv(ClientSocket, recvbuf, 1, 0);
		if (iResult > 0)
			iResult = send(ClientSocket, buffer, 26, 0);

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}
