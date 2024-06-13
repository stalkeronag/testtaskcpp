#include "../headers/ResponseLoggerHandler.h"

Response* ResponseLoggerHandler::Handle(unsigned char* data, int dataLen )
{
    unsigned char command = data[0];

    switch (command)
    {
        case 0x04:
            LogReadWriteResponse(data, dataLen);
            break;
        case 0x06:
            LogReadWriteResponse(data, dataLen);
            break;
        case 0x0A:
            LogErrorResponse(data, dataLen);
            break;
        default:
            break;
    }

    return new Response(data, dataLen);
}

void ResponseLoggerHandler::LogReadWriteResponse(unsigned char* data, int len)
{
    std::string result = "RESPONSE";
    result = result + " Command:" + std::to_string((int)data[0]);
    result = result + " number:" + std::to_string((int)data[1]);
    result = result + " " + std::to_string((int)data[2]);
    result = result + " register data:";
    for (int i = 3; i < len; i++)
    {
        result = result + std::to_string((int)data[i]) + " ";
    }
    std::cout<<result<<std::endl;
}


void ResponseLoggerHandler::LogErrorResponse(unsigned char* data, int len)
{
    std::string result = "RESPONSE";
    result = result + " Command:" + std::to_string((int)data[0]);
    result = result + " code error:" + std::to_string((int)data[1]);
    result = result + " " + std::to_string((int)data[2]);
    std::cout<<result<<std::endl;
}