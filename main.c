#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include"stdio.h";
#include "stdint.h"

#include "Socket.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc, char* argv[])
{
	Socket_Init("192.168.0.112", 1234);
	//Send some data
	message = "hello";
	if (Socket_Send(message, strlen(message)) <= 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
	char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	while (1)
	{
		uint16_t result;
		result = Socket_Recv(buffer, 1024);
		if (result > 0)
		{
			printf("data from server: %s\r\n", buffer);
		}
		memset(buffer, 0, sizeof(buffer));
	}
	return 0;
}