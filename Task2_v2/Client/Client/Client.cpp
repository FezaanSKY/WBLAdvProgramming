#include "Client.h"

Client::Client(PCWSTR host, int port):Comms(host, port){}


void Client::connection() throw()
{
	sockaddr_in clientService;

	// init sockaddr_in structure
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, host, &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	// connect the client to the server,if an error occurs, throw a ConnectionException
	if (connect(localSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
		throw ConnectionException();
}
