#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma once
#include"stdio.h";
#include "stdint.h"
#include "Winsock2.h";
#include "Ws2tcpip.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library
WSADATA wsa;
SOCKET s;
struct sockaddr_in server;
char* message;

void Socket_Init(char* ip_server, u_short port);
int Socket_Send(char* data, uint16_t size);
int Socket_Recv(char* src, uint16_t size);