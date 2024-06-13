#include <iostream>
#include <cstring>
class BuilderMail
{
private:
    unsigned short startChars;

    unsigned short crcChars;

    unsigned char adrSource;

    unsigned char adrDestination;

    unsigned char* data;

    unsigned short stopChars;

    int amountBytes;

    int lenData;
public:
    BuilderMail();
    ~BuilderMail();
public:
    void AddStart(unsigned short startArray = ((0xFE << 8) + 0xFE));
    void AddAdrSource(unsigned char adrSourceArray);
    void AddAdrDestination(unsigned char adrDestinationArray);
    void AddStop(unsigned short stopArray = ((0xFC << 8) + 0xFC));
    void AddData(unsigned char* dataArray, int lenData);
    unsigned char* Build();
    int GetMailLen();
private:
    unsigned int CountCrc(unsigned char* data, int len);
    unsigned char* StaffBytes(unsigned char* data, int len);
};

