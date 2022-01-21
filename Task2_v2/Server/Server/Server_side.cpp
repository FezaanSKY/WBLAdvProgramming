#include "Server.h"
using namespace std;

int main(int argc, char* argv[]) {

	Server server(_T("127.0.0.1"), 55555);
	try {
		server.attachSocket();

		server.bindServer();
		cout << "bind() is OK!" << endl;

		server.connection();
		cout << "Server: connect() is OK." << endl;

		char buffer[200];
		do {

			server.recvMessage(buffer, 200);

			if (strcmp(buffer, "quit") == 0 || strcmp(buffer, "QUIT") == 0)
				break;

			cout << "Message from the client : " << buffer << endl;

			if (strcmp(buffer, "quit") == 0 || strcmp(buffer, "QUIT") == 0) {
				cout << "send confirmation of message : " << buffer << " recieved";

				strcat_s(buffer, " recieved");
				server.sendMessage(buffer, 200);
				break;
			}

			cout << "send confirmation of message : "<< buffer <<" recieved";

			strcat_s(buffer, " recieved");
			server.sendMessage(buffer,200);

			cout << endl;

		} while (strcmp(buffer, "QUIT") != 0 && strcmp(buffer, "quit") != 0);

	}
	catch (LoadDDLException e) {
		cout << e.what() << endl;
		return 0;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	WSACleanup();
	
	return 0;
}
