#pragma once
#include  "Comms.h"

using namespace std;

class Client : public Comms
{
public:
	Client(PCWSTR host, int port);

	void connection() throw();
};

