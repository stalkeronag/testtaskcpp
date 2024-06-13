#include "../headers/Server.h"

Server::Server(int port, std::string ipAddress, FirstHandler handler) 
{
	this->port = port;
	this->ipAddress = ipAddress;
	this->bufferSize = 1024;
	this->handler = handler;
}

Server::~Server()
{
}

void Server::Setup()
{
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (serverSocket == 1)
	{
		std::cerr << "Ошибка создания сокета" << std::endl;
	}
	info.sin_family = AF_INET;
	info.sin_port = htons(port);

	info.sin_addr.s_addr = inet_addr(ipAddress.c_str());

	int bindResult = bind(serverSocket, (struct sockaddr*) &info, sizeof(info));

	if (bindResult == -1)
	{
		std::cerr << "Ошибка привязки сокета" << std::endl;
	}

	if (listen(serverSocket, 5) == -1) {
    std::cerr << "Ошибка слушания на порту" << std::endl;
  	}

  	std::cout << "Сервер запущен на порту " << port << std::endl;
}

void Server::Receive(int clientSocket)
{
	unsigned char* buffer = new unsigned char[bufferSize];
    int bytes_received = recv(clientSocket, buffer, bufferSize, 0);
    if (bytes_received > 0) {
		response = handler.Handle(buffer, bytes_received);
    }
}

void Server::Send(int clientSocket)
{
	int number = send(clientSocket,response->data, response->len,0);
}



void Server::Start() 
{
	Setup();

	for (;;)
	{
		int client_socket;
		struct sockaddr_in client_address;
		unsigned int size_address_client =  sizeof(client_address);
		client_socket = accept(serverSocket, (struct sockaddr*)&client_address, &size_address_client);
		Receive(client_socket);
		Send(client_socket);
		close(client_socket);
	}
	close(serverSocket);
}



