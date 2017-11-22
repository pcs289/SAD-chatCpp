#ifndef MYSOCKET_H
#define MYSOCKET_H
#include <iostream>
#include <stdlib>
#include <cstdio> 
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> 
#include <arpa/inet.h>

class MySocket;
using namespace std;

class MySocket{
	private:
		struct sockaddr_in serverSocket;
		int socket;

	public:
		MySocket(string ip, int port){
			serverSocket.sin_addr.s_addr = inet_addr(ip); 
			serverSocket.sin_port = htons(port);
			serverSocket.sin_family = AF_INET;
			if ((socket = socket(AF_INET , SOCK_STREAM , 0)) < 0 || connect(socket, (struct sockaddr *)&serverSocket, sizeof(serverSocket)) < 0)
				exit(EXIT_FAILURE);
			
		}

		int getSocketFileDescriptor(){
			return socket;
		}

		void close(){
			int n = shutdown(socket,0);
		}

		void printLine(string line){
			if (send(MySocket::socket, line.c_str(), strlen(line.c_str()), 0) < 0)
				exit(EXIT_FAILURE);
		}

		void readLine(string buffer){
			int n = read(this->socket, buffer.c_str(), strlen(buffer.c_str())-1);
			if(n < 0)
				exit(EXIT_FAILURE);
		}


}