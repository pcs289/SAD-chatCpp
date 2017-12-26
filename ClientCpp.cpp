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
	try{
		MySocket ms(ip, port);
		thread writeThread(&Client::writeToSocket, ms); 
		thread readThread(&Client::readFromSocket, ms);
		writeThread.join();
		readThread.join();
	}catch (int e){
		cout << strerror(e) << endl;
	}
}

void Client::writeToSocket(MySocket ms){
	string ky;
	try{
		while(!std::getline(cin, ky)){
			ms.printLine(ky);
		}
	}catch (int e){
		cout << strerror(e) << endl;
	}
}

void Client::readFromSocket(MySocket ms){
	string received;
	try{
		while(true){

			ms.readLine(received);
			cout << received;
		}
	}catch (int e){
		cout << strerror(e) << endl;
	}
}

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Usage:" << endl << "Client: ./chat ipAddress Port" << endl;
	}else{
		cout << "Client" << endl;
		int port = htons(atoi(argv[2]));
		string ip(argv[1]);
		cout << "Trying to connect at IP " << argv[1] << " at port " << argv[2] << "..." << endl;
		Client c(ip, port);

	}
	return 0;
}