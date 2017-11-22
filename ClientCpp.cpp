#include <iostream>
#include <errno.h>
#include <thread>
#include <string>
#include <cstdlib>
#include "MySocket.h"

using namespace std;

class Client{
	public:	
		Client(string ip, int port);
		MySocket ms;
}

Client::Client(string ip, int port){
	ms(ip, port);
}

int main(int argc, string argv[]){

	if(argc == 0 || argc > 2 || argc < 2){
		cout << "Usage:" << endl << "Client: g++ ClientCpp ipAddress Port" << endl;
	}else{
		cout << "Client" << endl;
		int port = (int)argv[1];
		string ip = argv[0];
		cout << "Trying to connect at IP " << argv[0] << " at port " << argv[1] << endl;
		Client c(ip, port);

	}


}