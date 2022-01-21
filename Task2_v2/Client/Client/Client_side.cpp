#include "Client.h";
#include <string>

int main()
{
	Client client(_T("127.0.0.1"), 55555);

	try {

		client.attachSocket();

		client.connection();
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;

		char buffer[200];
		do {

			cout << "new message > ";
			cin.getline(buffer, 200);
			client.sendMessage(buffer,200);

			if (strcmp(buffer, "quit") == 0 || strcmp(buffer, "QUIT") == 0)
				break;

			client.recvMessage(buffer, 200);

			if (strcmp(buffer, "quit") == 0 || strcmp(buffer, "QUIT") == 0)
				break;

			cout << "Message from server: " << buffer << endl;

		} while (strcmp(buffer, "QUIT") != 0 && strcmp(buffer, "quit") != 0);
	}
	catch (LoadDDLException e) {
		cout << e.what() << endl;
		return 0;
	}
	catch (exception e){
		cout << e.what() <<endl;
	}

	WSACleanup();

	return 0;

}

