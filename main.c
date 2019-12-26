#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h";
#include "stdint.h"

#include "Socket.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library

typedef struct
{
	uint8_t x;
	uint8_t y;
}struct_t;
uint8_t toan_cuc;
int main_1(int argc, char* argv[])
{
	char* ip;
	ip = "52.220.188.34";
	u_short port = 80;
	Socket_Init(ip, port);

	char* data;
	data = "GET /image HTTP/1.1\r\n"\
		"Host: 52.220.188.34\r\n\r\n";
	Socket_Send(data, strlen(data));
	
		
	char src[256];
	memset(src, 0, sizeof(src));
	int res = 0;
	while (1)
	{
		
		res += Socket_Recv(src + res, 1);
		if (strstr(src, "\r\n\r\n") != NULL)
			break;
	}
	printf("%s", src);
	FILE* fx;
	fx = fopen("image.jpeg", "a+b");
	int step = 0;
	char temp = 0;
	while (step != 4)
	{
		Socket_Recv(&temp, 1);
		fputc(temp, fx);
		switch (step)
		{
		case 0:
			if (temp == (char)0xff)
				step = 1;
			break;
		case 1: 
			if (temp == (char)0xd8)
				step = 2;
			else
				step = 1;
			break;
		case 2:
			if (temp == (char)0xff)
				step = 3;
			break;
		case 3:
			if (temp == (char)0xd9)
				step = 4;
			else
				step = 2;
			break;
		}
	}
	fclose(fx);
	return 0;
}

void main()
{
	Socket_Server_Init(3333);
}