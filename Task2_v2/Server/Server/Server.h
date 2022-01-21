#pragma once
#include "../../Client/Client/Comms.h"

class Server : public Comms
{
public:
	Server(PCWSTR host, int port);
	void connection()throw();
	void bindServer();
	void sendMessage(const char* msg, size_t size) throw();
	void recvMessage(char* buffer, size_t bufferSize)throw();

private:
	SOCKET acceptSocket;
};

