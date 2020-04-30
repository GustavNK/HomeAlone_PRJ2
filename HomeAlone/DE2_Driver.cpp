#include "DE2_Driver.h"

DE2_driver::DE2_driver(int comPort, int baudRate)
{
	de2Signal_ = false;
	comPort_ = comPort;
	baudRate_ = baudRate;
}

bool DE2_driver::readDe2Signal()
{
	char data[1];

	CSerial* s = new CSerial();

	if (!s->Open(comPort_, baudRate_))
	{
		std::cout << ("Could not open COM") << comPort_ << std::endl;
		return false;
	}

	data[0] = s->ReadData(data, 1);

	if (data[0] == 0xff) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
