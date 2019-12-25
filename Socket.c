#include "Socket.h"
#include "stdio.h"



void Socket_Init(char* ip_server, u_short port)
{
	
	struct timeval timeout;
	printf(" \nInitialising Winsock... ");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : % d ", WSAGetLastError());
		return 1;
	}

	printf(" Initialised.\n ");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : % d", WSAGetLastError());
	}

	printf(" Socket created.\n ");
	/*timeout.tv_sec = 100;
	timeout.tv_usec = 0;

	if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout,
		sizeof(timeout)) < 0)
		printf("setsockopt failed\n");

	if (setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout,
		sizeof(timeout)) < 0)
		printf("setsockopt failed\n");*/

	server.sin_addr.s_addr = inet_addr(ip_server);

	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(s, (struct sockaddr*) & server, sizeof(server)), 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("Connected");
}

int Socket_Send(char* data, uint16_t size)
{
	return send(s, data, size, 0);
}

int Socket_Recv(char *src, uint16_t size)
{
	return recv(s, src, size, 0);
}

void task1()
{
	printf("hello\r\n");
	
}