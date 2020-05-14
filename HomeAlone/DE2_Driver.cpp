//======================================================================== 
// FILENAME : DE2_Driver.cpp
// CREATED  : 06/05/20
// AUTHOR	: GustavNK
// DESCR.   : Handles the UART output to the DE2 Board
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20> Initial creation and inplemnetet into master
// 1.1 <14.05.20> Made into a child of CSerial and better comments
//========================================================================

#include "DE2_Driver.h"

//============================================================= 
// METHOD : Constructor
// DESCR. : Instatiates the Communications Port and the Baud Rate
//============================================================= 
DE2_driver::DE2_driver(int comPort, int baudRate) : CSerial()
{
	comPort_ = comPort;
	baudRate_ = baudRate;
}

//============================================================= 
// METHOD : readDe2Char 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
char DE2_driver::readDe2Char()
{
	char data[1];

	CSerial* s = new CSerial();

	if (Open(comPort_, baudRate_))
	{
		std::cout << ("Could not open COM") << comPort_ << std::endl;
		return falseChar;
	}

	return ReadData(data, 1);
}

//============================================================= 
// METHOD : readDe2Char --DUMMY--
// DESCR. : Always returns the expected char. Made for testing
//============================================================= 
char DE2_driver::readDe2Char(int i)
{
	return trueChar;
}

//============================================================= 
// METHOD : sendDe2Char 
// DESCR. : 
//============================================================= 
bool DE2_driver::sendDe2Char(const char data)
{
	if (!Open(comPort_, baudRate_))
	{
		std::cout << ("Could not open COM") << comPort_ << std::endl;
		return false;
	}

	SendData(&data, 1);

	return true;
}

//============================================================= 
// METHOD : sendDe2Char --DUMMY--
// DESCR. : Always returns true. Made for testing
//============================================================= 
bool DE2_driver::sendDe2Char(char data, int i) 
{
	return true;
}
