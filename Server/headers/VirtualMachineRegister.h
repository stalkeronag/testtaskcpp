#include <iostream>
#include <vector>
class VirtualMachineRegister 
{
private:
    int numberRegister;
    unsigned char* bytes;
    int length;
public:
    VirtualMachineRegister(int number, unsigned char* data, int len);
    unsigned char* GetBytes();
    int GetNumber();
    int GetLength();
};