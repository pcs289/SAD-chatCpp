#define MYSOCKET_H
class MySocket;

#include <iostream>
#include <stdlib.h>
#include <cstdio> 
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> 
#include <arpa/inet.h>

const int MAX_SIZE = 1024;

using namespace std;

class MySocket{
	private:
		struct sockaddr_in serverSocket;
		int socketFD;

	public:
		MySocket(string ip, int port){
			serverSocket.sin_addr.s_addr = inet_addr(ip.c_str()); 
			serverSocket.sin_port = htons(port);
			serverSocket.sin_family = AF_INET;

			if ((socketFD = socket(AF_INET , SOCK_STREAM , 0)) < 0) 
				exit(EXIT_FAILURE);

			if(connect(socketFD, (struct sockaddr *)&serverSocket, sizeof(serverSocket)) < 0)
				exit(EXIT_FAILURE);
			
		}

		int getSocketFileDescriptor(){
			return socketFD;
		}

		void close(){
			int n = shutdown(socketFD,0);
		}

		void printLine(string line){
			if (send(MySocket::socketFD, line.c_str(), strlen(line.c_str()), 0) < 0)
				exit(EXIT_FAILURE);
		}

		void readLine(string buffer){

			int n = recv(this->socketFD, &buffer[0], MAX_SIZE, 0);
			if(n < 0)
				exit(EXIT_FAILURE);
		}


};