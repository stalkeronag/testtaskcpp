#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "IRecieveHandler.h"
class Server
{
private:
	std::string message;
	std::string ipAddress;
	int port;
	int serverSocket;
	struct sockaddr_in info;
	int bufferSize;
	int recSize;
	Response* response;
	FirstHandler handler;
public:
	Server(int, std::string, FirstHandler handler);
	~Server();

public:
	void Start();
private:
	void Setup();
	void Receive(int clientSocket);
	void Send(int clientSocket);
};

