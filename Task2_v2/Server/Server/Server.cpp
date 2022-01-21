#include "Server.h"
#include "../../Client/Client/Exceptions.h"


Server::Server(PCWSTR host, int port) :Comms(host, port) {
	acceptSocket = INVALID_SOCKET;
}

// wait connection from client
void Server::connection() throw()
{
	// set the server in listening mode , (1) the  means that the server can queue up to 1 connection
	// the listen function returns 0 if successful, or SOCKET_ERROR if not
	if (listen(localSocket, 1) == SOCKET_ERROR)
		cout << "listen(): Error listening on socket " << WSAGetLastError() << endl;
	else
		cout << "listen() is OK, I'm waiting for connections..." << endl;

	// the server now is waiting for connections
	// the accept function returns a acceptSocket discriptor for the new connection,
	// or SOCKET_ERROR if there is an error
	acceptSocket = accept(localSocket, NULL, NULL);
	if (acceptSocket == INVALID_SOCKET) {
		throw ConnectionException();
	}
	cout << "Accepted connection" << endl;
}

//register the server on a given host and port
void Server::bindServer() throw()
{
	sockaddr_in service;

	// init in sockaddr_in structure
	service.sin_family = AF_INET;
	InetPton(AF_INET, host, &service.sin_addr.s_addr);
	service.sin_port = htons(port);

	// register the server on the socket
	if (bind(localSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
		cout << "bind() failed: " << WSAGetLastError() << endl;
		closesocket(localSocket);

		throw BindException();
	}
}


 void Server::sendMessage(const char* msg, size_t size) throw()
 {
 	int byteCount = send(acceptSocket, msg, size, 0);

 	if (byteCount <= 0)
 		throw SendMessageException();
 }


 void Server::recvMessage(char* buffer, size_t bufferSize) throw()
 {
 	int byteCount = recv(acceptSocket, buffer, 200, 0);

 	if (byteCount <= 0)
 		throw RecieveMassageException();
 }

