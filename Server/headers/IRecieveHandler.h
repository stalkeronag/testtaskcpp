#include <iostream>
#include <cstring>
#include "RequestLoggerHandler.h"

class FirstHandler 
{
private:
    int amountBytes;
    RequestLoggerHandler handler;
    
public:
    Response* Handle(unsigned char* data, int dataLen);
    unsigned int CountCrc(unsigned char* bytes, int dataLen);
    unsigned char* RemoveStaffBytes(unsigned char* bytes, int dataLen);
    void SetNextHandler(RequestLoggerHandler next);
};

