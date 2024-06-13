#include "../headers/IRecieveHandler.h"


Response* FirstHandler::Handle(unsigned char* data, int dataLen)
{
    data = RemoveStaffBytes(data, dataLen);
    unsigned int crc = CountCrc(data, amountBytes - 4);

    return handler.Handle(data, amountBytes);
}

unsigned char* FirstHandler::RemoveStaffBytes(unsigned char* bytes, int dataLen)
{
    int countZeroBytes = 0;

    for (int i = 0; i < dataLen - 3; i++)
    {
        if (bytes[i] == 0xFC || bytes[i] == 0xFE)
        {
            countZeroBytes++;
        }
    }
    amountBytes = dataLen - countZeroBytes;
    int newLen = dataLen - countZeroBytes;
    unsigned char* res = new unsigned char[newLen];
    int index = 1;
    res[0] = bytes[0];
    for (int i = 1; i < dataLen; i++)
    {
        if ((bytes[i - 1] == 0xFC || bytes[i - 1] == 0xFE) && countZeroBytes > 0 && bytes[i] == 0x00)
        {
               countZeroBytes--;
        } else {
            res[index] = bytes[i];
            index++;
        }
    }

    delete[] bytes;
    
    return res;
}

unsigned int FirstHandler::CountCrc(unsigned char* bytes, int dataLen)
{
    int len = dataLen;
    unsigned int reg_crc = 0xFFFF;

    while (len--)
    {
        reg_crc ^= *bytes++;
        for (int j = 0;j<8;j++)
        {
            if (reg_crc & 0x01)
                reg_crc = (reg_crc>>1) ^0xA001;
            else
                reg_crc = reg_crc >>1;
            }
    }

    return reg_crc;
}

void FirstHandler::SetNextHandler(RequestLoggerHandler nexthandler)
{
    this->handler = nexthandler;
}

