#pragma once
#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include<iostream>

#include "Exceptions.h"

#pragma comment(lib, "Ws2_32.lib")

class Comms {

public:
	Comms(PCWSTR host, int port) {
		this->host = host;
		this->port = port;
		localSocket = INVALID_SOCKET; 
	}

	// method to create a socket and attach the client this to it
	virtual void attachSocket() throw() {
		WSADATA wsaData;
		int wsaerr;
		WORD wVersionRequested = MAKEWORD(2, 2);

		//check if windows ddl for socekt is loaded
		wsaerr = WSAStartup(wVersionRequested, &wsaData);
		if (wsaerr != 0)
			throw LoadDDLException();

		//create the socket
		// the socket function returns a SOCKET discriptor if the socket is created successfully, -1 otherwise
		localSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (localSocket  < 0)
			throw AttachSocketException();
	}

	//connect the client to the server
	virtual void connection() throw() = 0;

	//send a message to the server
	virtual void sendMessage(const char* msg, size_t size) throw()
	{
		// send return the number of bytes sent, SOCKET_ERROR otherwise
		int byteCount = send(localSocket, msg, size, 0);

		if (byteCount == SOCKET_ERROR)
			throw SendMessageException();
	}

	//receive a message from the server
	virtual void recvMessage(char* buffer, size_t bufferSize)throw()
	{
		// recv return the nbr of bytes received, SOCKET_ERROR otherwise
		int byteCount = recv(localSocket, buffer, bufferSize, 0);

		if (byteCount == SOCKET_ERROR)
			throw RecieveMassageException();
	}

protected:

	SOCKET localSocket;


	PCWSTR host;


	int port;

};