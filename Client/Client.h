#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "ResponseLogger.h"

class Client
{
    public: Client(int port, std::string ipAddress, ResponseLogger logger);

    private:
        int port;
        std::string ipAddress;
        struct sockaddr_in info;
        int clientSocket;
        int bufferSize;
        ResponseLogger logger;
    public:
        void Connect();
        void Close();
        void Send(unsigned char* array, int length);
        void Receive();
};
