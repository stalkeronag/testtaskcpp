#include "BuilderMail.h"

BuilderMail::BuilderMail()
{
    this->amountBytes = 0;
}

BuilderMail::~BuilderMail()
{

}

void BuilderMail::AddStart(unsigned short start)
{
    this->startChars = start;
}

void BuilderMail::AddAdrSource(unsigned char adrSource)
{
    this->adrSource = adrSource;
}

void BuilderMail::AddAdrDestination(unsigned char adrDestination)
{
    this->adrDestination = adrDestination;
}

void BuilderMail::AddData(unsigned char* data, int lenData)
{
    this->data = data;
    this->lenData = lenData;
}

void BuilderMail::AddStop(unsigned short stop)
{
    this->stopChars = stop;
}

unsigned char* BuilderMail::Build()
{
    int length = sizeof(startChars) + 
    sizeof(adrSource) + 
    sizeof(adrDestination) + 
    lenData;
    int resultLen = length + sizeof(crcChars) + sizeof(stopChars);
    unsigned char* result = new unsigned char[resultLen];
    result[0] = startChars >> 8;
    result[1] = startChars & 0xFF;
    result[2] = adrSource;
    result[3] = adrDestination;
    for (int i = 4; i < (length); i++)
    {
        result[i] = data[i - 4];
    }
    unsigned int crc = CountCrc(result, resultLen - 4);
    result[length] = crc >> 8;
    result[length + 1] = crc & 0xFF;
    result[length + 2] = stopChars >> 8;
    result[length + 3] = stopChars & 0xFF;
    result = StaffBytes(result,resultLen);
    return result;
}

unsigned int BuilderMail::CountCrc(unsigned char* dataForCrc,int len)
{
    unsigned int reg_crc = 0xFFFF;

    while (len--)
    {
        reg_crc ^= *dataForCrc++;
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

unsigned char* BuilderMail::StaffBytes(unsigned char* dataMail, int len)
{
    int countMatch = 0;
    for (int i = 0; i < (len - 2); i++)
    {
        if (dataMail[i] == 0xFC || dataMail[i] == 0xFE)
        {
            countMatch++;
        }
    }
    int lenWithStaff = len + countMatch;
    unsigned char* staffArray = new unsigned char[len + countMatch];
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if ((dataMail[i] == 0xFC || dataMail[i] == 0xFE) && countMatch > 0)
        {
            staffArray[index] = dataMail[i];
            staffArray[index + 1] = 0x00;
            index += 2;
            countMatch--;
        } else {
            staffArray[index] = dataMail[i];
            index += 1;
        }
    }
    delete[] dataMail;
    amountBytes = lenWithStaff;

    return staffArray;
}

int BuilderMail::GetMailLen()
{
    return amountBytes;
}

