#include "headers/Server.h"
#define PORT 5555
#define IP "127.0.0.1"


int main() {
    ResponseLoggerHandler responsehandler = ResponseLoggerHandler();
    VirtualMachine machine = VirtualMachine();
    machine.Setup();
    RequestToVMHandler requestToVMHandler = RequestToVMHandler();
    requestToVMHandler.SetVM(machine);
    requestToVMHandler.SetNextHandler(responsehandler);
    RequestLoggerHandler loggerRequetHandler = RequestLoggerHandler();
    loggerRequetHandler.SetNextHandler(requestToVMHandler);
    FirstHandler firstHandler = FirstHandler();
    firstHandler.SetNextHandler(loggerRequetHandler);
    Server server = Server(PORT,IP, firstHandler);
    server.Start();
}
