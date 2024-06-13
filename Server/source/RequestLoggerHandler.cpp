
#include "../headers/RequestLoggerHandler.h"


Response* RequestLoggerHandler::Handle(unsigned char* data, int dataLen)
{
    
    std::string resultString = "";
    resultString = resultString + "REQUEST: ";
    resultString = resultString + "start: ";

    resultString = resultString + std::to_string((unsigned char)data[0]);
    resultString = resultString + " " + std::to_string((unsigned char)data[1]);

    resultString = resultString + " adr1: " + std::to_string((unsigned char)data[2]);
    resultString = resultString + " adr2: " + std::to_string((unsigned char)data[3]);
    resultString = resultString + " data: ";
    for (int i = 4; i < dataLen - 4; i++) 
    {
        resultString = resultString + std::to_string((unsigned char)data[i]) + " ";
    }
    resultString = resultString + "crc: " + std::to_string((unsigned char)data[dataLen - 4]);
    resultString = resultString + " " + std::to_string((unsigned char)data[dataLen - 3]);
    resultString = resultString + " stop: " + std::to_string((unsigned char)data[dataLen - 2]);
    resultString = resultString + " " + std::to_string((unsigned char)data[dataLen - 1]); 
    std::cout<<resultString<<std::endl;


    return handler.Handle(data, dataLen);
}

void RequestLoggerHandler::SetNextHandler(RequestToVMHandler handler)
{
    this->handler = handler;
}