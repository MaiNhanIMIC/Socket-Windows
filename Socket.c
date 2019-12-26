#include "Socket.h"
#include "stdio.h"

void Socket_Init(char* ip_server, u_short port)
{
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

void Socket_Server_Init(u_short port)
{
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

	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	bind(s, (struct sockaddr*) & server, sizeof(struct sockaddr));

	listen(s, 5);

	struct sockaddr_in dest;
	socklen_t socksize = sizeof(struct sockaddr_in);
	int consocket = accept(s, (struct sockaddr*) & dest, &socksize);
	char* msg = "Hello World !\n";
	while (consocket)
	{
		printf("Incoming connection from %s - sending welcome\n", inet_ntoa(dest.sin_addr));
		send(consocket, msg, strlen(msg), 0);
		close(consocket);
		consocket = accept(s, (struct sockaddr*) & dest, &socksize);
	}
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