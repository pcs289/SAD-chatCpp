#include <iostream>
#include <errno.h>
#include <thread>
#include <string.h>
#include <cstdlib>
#include "MySocket.h"


using namespace std;

class Client{
	public:	
		Client(string ip, int port);
		static void writeToSocket(MySocket ms);
		static void readFromSocket(MySocket ms);
};

Client::Client(string ip, int port){
	cout << "Client" << endl;
	MySocket ms(ip, port);
	cout<<"socket ready"<<endl;
	thread writeThread(&Client::writeToSocket, ms); 
	cout << "writeThread"<<endl;
	thread readThread(&Client::readFromSocket, ms);
	cout << "readThread"<<endl;
	writeThread.join();
	readThread.join();
}

void Client::writeToSocket(MySocket ms){
	string ky;
	while(!std::getline(cin, ky)){
		ms.printLine(ky);
	}
}

void Client::readFromSocket(MySocket ms){
	string received;
	while(true){
		ms.readLine(received);
		cout << received;
	}
}

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Usage:" << endl << "Client: ./chat ipAddress Port" << endl;
	}else{
		cout << "Client" << endl;
		int port = htons(atoi(argv[2]));
		string ip(argv[1]);
		cout << "Trying to connect at IP " << argv[1] << " at port " << argv[2] << endl;
		Client c(ip, port);

	}
	return 0;
}