#include "../headers/VirtualMachine.h"
#include <iostream>

VirtualMachine::VirtualMachine()
{
	
}

unsigned char* VirtualMachine::ReadFromRegister(int number) {
	for (int i = 0; i < countRegisters; i++)
	{
		if (registers[i].GetNumber() == number)
		{
			unsigned char* reg =  registers[i].GetBytes();
			int lenResult = registers[i].GetLength();
			unsigned char* result = new unsigned char[lenResult + 3];

			result[0] = 0x06;
			result[1] = number >> 8;
			result[2] = number & 0xFF;

			for (int j = 0; j < registers[i].GetLength();j++)
			{
				result[j + 3] = reg[j];
			}
			prevDataLen = lenResult + 3;
			return result;
		}
	}
	prevDataLen = 3;
	return new unsigned char[3]{0x0A, 0x00, 0x02};
}

unsigned char* VirtualMachine::WriteToRegister(int number, unsigned char* data, int dataLen) 
{
	for (int i = 0; i < countRegisters; i++)
	{
		if (registers[i].GetNumber() == number)
		{
			if (dataLen != registers[i].GetLength())
			{
				prevDataLen = 3;
				return new unsigned char[3]{0x0A, 0x00, 0x06};
			}
			unsigned char* reg = registers[i].GetBytes();
			int lenResult = dataLen + 3;
			unsigned char* result = new unsigned char[lenResult];

			result[0] = 0x04;
			result[1] = number >> 8;
			result[2] = number & 0xFF;

			for (int i = 3; i < lenResult; i++)
			{
				result[i] = data[i - 3];
				reg[i - 3] = data[i - 3];
			}
			prevDataLen = lenResult;
			return result;
		}
	}
	prevDataLen = 3;
	return new unsigned char[3]{0x0A, 0x00, 0x03};
}

int VirtualMachine::getPrevLenData()
{
	return prevDataLen;
}

void VirtualMachine::Setup()
{
	VirtualMachineRegister zeroReg = VirtualMachineRegister(0,new unsigned char[19],19);
	VirtualMachineRegister sixReg = VirtualMachineRegister(6, new unsigned char[4], 4);
	VirtualMachineRegister sevenReg = VirtualMachineRegister(7, new unsigned char[4], 4);
	VirtualMachineRegister eightReg = VirtualMachineRegister(9, new unsigned char[4], 8);
	VirtualMachineRegister elevenReg = VirtualMachineRegister(11, new unsigned char[4], 2);
	VirtualMachineRegister twelveReg = VirtualMachineRegister(12, new unsigned char[4], 2);
	VirtualMachineRegister thirtyReg = VirtualMachineRegister(13, new unsigned char[4], 1);
	registers.push_back(zeroReg);
	registers.push_back(sixReg);
	registers.push_back(sevenReg);
	registers.push_back(eightReg);
	registers.push_back(elevenReg);
	registers.push_back(twelveReg);
	registers.push_back(thirtyReg);
	prevDataLen = 0;
	countRegisters = 7;
}
