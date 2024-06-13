#include "../headers/VirtualMachineRegister.h"

VirtualMachineRegister::VirtualMachineRegister(int number, unsigned char* bytes, int len)
{
    this->bytes = bytes;
    this->numberRegister = number;
    this->length = len;
}

int VirtualMachineRegister::GetNumber()
{
    return numberRegister;
}

unsigned char* VirtualMachineRegister::GetBytes()
{
    return bytes;
}

int VirtualMachineRegister::GetLength()
{
    return length;
}