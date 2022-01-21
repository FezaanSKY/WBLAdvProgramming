#pragma once
#include <iostream>
#include <exception>
using namespace std;

class LoadDDLException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "The Winsock dll not found.";
	}
};

class AttachSocketException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "failed attach to socket.";
	}
};


class SendMessageException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "failed to send message.";
	}
};

class RecieveMassageException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "failed to recieve message";
	}
};

class ConnectionException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "failed to connect.";
	}
};


class BindException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "failed to bind the server.";
	}
};
