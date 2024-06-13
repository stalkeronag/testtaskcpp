#include "Client.h"

Client::Client(int port,std::string ipAddress,ResponseLogger logger)
{
    this->port = port;
    this->ipAddress = ipAddress;
    info.sin_family = AF_INET;
    info.sin_port = htons(port);
    info.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    bufferSize = 1024;
    this->logger = logger;
}

void Client::Connect()
{
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket == -1) {
    std::cerr << "Ошибка создания сокета" << std::endl;
    } 

    if (connect(clientSocket, (struct sockaddr *)&info, sizeof(info)) == -1) {
    std::cerr << "Ошибка подключения к серверу" << std::endl;
    }
}

void Client::Send(unsigned char *message, int length)
{
    send(clientSocket, message, length, 0);
}

void Client::Receive()
{
    unsigned char* buffer = new unsigned char[bufferSize];
    int bytes_received = recv(clientSocket, buffer, bufferSize, 0);
    if (bytes_received > 0) 
    {
        logger.Log(buffer, bytes_received);
    }
}

void Client::Close()
{
    close(clientSocket);
}
