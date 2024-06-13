#include <iostream>
#include "Response.h"
class ResponseLoggerHandler
{
public:
    Response* Handle(unsigned char* data, int dataLen);
    void LogReadWriteResponse(unsigned char* data, int len);
    void LogErrorResponse(unsigned char* data, int len);
};