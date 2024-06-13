#include "RequestToVMHandler.h"
#include <iostream>

class RequestLoggerHandler
{
private:
    RequestToVMHandler handler;
public:
    Response* Handle(unsigned char* data, int dataLen);
    void SetNextHandler(RequestToVMHandler next);
};