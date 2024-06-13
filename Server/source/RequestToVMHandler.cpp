#include "../headers/RequestToVMHandler.h"


void RequestToVMHandler::SetVM(VirtualMachine machine)
{
    this->machine = machine;
}

Response* RequestToVMHandler::Handle(unsigned char* data, int dataLen)
{
    unsigned char command = data[4];
    int number = (data[5] << 8) + data[6];
    unsigned char* response;
    switch (command)
    {
        case 0x03:
        {
            response = machine.ReadFromRegister(number);
            break;
        }      
        case 0x05:
        {
            unsigned char* dataField = new unsigned char[dataLen - 7];
            for (int i = 0; i < (dataLen - 7); i++)
            {
                dataField[i] = data[i + 7];
            }
            response = machine.WriteToRegister(number, dataField, dataLen - 11);
            break;
        }       
        default:
            break;
    }
    int responseLen = machine.getPrevLenData();

    return handler.Handle(response, responseLen);
}

void RequestToVMHandler::SetNextHandler(ResponseLoggerHandler handler)
{
    this->handler = handler;
}