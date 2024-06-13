#include "VirtualMachine.h"
#include "ResponseLoggerHandler.h"
class RequestToVMHandler
{
private:
    int amountBytes;
    VirtualMachine machine;
    ResponseLoggerHandler handler;
public:
    Response* Handle(unsigned char* data, int len);
    void SetVM(VirtualMachine machine);
    void SetNextHandler(ResponseLoggerHandler next);
};