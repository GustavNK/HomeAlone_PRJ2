#include "DE2_Driver.h"

DE2_driver::DE2_driver(int comPort, int baudRate)
{
	comPort_ = comPort;
	baudRate_ = baudRate;
	trueChar_ = 'z';  
	falseChar_ = '0'; 
}

char DE2_driver::readDe2Char() const
{
	char data[1];

	CSerial* s = new CSerial();

	if (!s->Open(comPort_, baudRate_))
	{
		std::cout << ("Could not open COM") << comPort_ << std::endl;
		return '0';
	}

	return s->ReadData(data, 1);
}

bool DE2_driver::sendDe2Char(char *data) const
{

	CSerial* s = new CSerial();

	if (!s->Open(comPort_, baudRate_))
	{
		std::cout << ("Could not open COM") << comPort_ << std::endl;
		return '0';
	}

	s->SendData(data, 1);

	return true;
}
