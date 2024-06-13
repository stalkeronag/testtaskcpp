#include  "VirtualMachineRegister.h"


class VirtualMachine
{
private:
	std::vector<VirtualMachineRegister> registers;

	int countRegisters;

	int prevDataLen;
public:
	VirtualMachine();

	unsigned char* WriteToRegister(int number, unsigned char* data, int dataLen);

	unsigned char* ReadFromRegister(int number);

	int getPrevLenData();
	void Setup();
};


