//======================================================================== 
// FILENAME : DE2_Driver.cpp
// CREATED  : 06/05/20
// AUTHOR	: GustavNK
// DESCR.   : Handles the UART output to the DE2 Board
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20><GustavNK> Initial creation and inplemnetet into master
// 1.1 <14.05.20><GustavNK> Made into a child of CSerial and better comments
//							Defined true and false char
// 1.2 <15.05.20><GustavNK> Remade sendDE2 and readDE2 to be more logical with bools
//							Made restictions for comPort and baudRate
// 2.0 <15.05.20><GustavNK>	Made into child og UART, to make comPort and BaudRate
//							the same between DE2_driver and X10_driver
//------------------------------------------------------------------------ 
// TODO
//
//========================================================================

#include "DE2_Driver.h"

//=============================================================
// METHOD : Constructor
// DESCR. : Instatiates the Communications Port and the Baud Rate
//============================================================= 
DE2_driver::DE2_driver(int comPort, int baudRate) : UART(comPort, baudRate)
{
}

//============================================================= 
// METHOD : readDE2 
// DESCR. : Reads what is available at the comPort. char 'z' is
//			read as a true. All others are seen as false
//============================================================= 
bool DE2_driver::readDE2()
{
	char data[1];

	CSerial* s = new CSerial();

	if (Open(getComPort(), getBaudRate()))
	{
		std::cout << ("Could not open COM") << getComPort() << std::endl;
		return false;
	}

	char boolChar = ReadData(data, 1);

	return (boolChar == trueChar_) ? true : false;
}

//============================================================= 
// METHOD : readDE2 --DUMMY--
// DESCR. : Always returns the expected bool, true. Made for testing
//============================================================= 
bool DE2_driver::readDE2(int i)
{
	return true;
}

//============================================================= 
// METHOD : sendDE2 
// DESCR. : Takes a bool, that determines the char to be send to DE2
//			'z' is tue, all else is false
//============================================================= 
bool DE2_driver::sendDE2(bool boolToSend)
{
	if (!Open(getComPort(), getBaudRate())) //checks for connection on comPort
	{
		std::cout << ("Could not open COM") << getComPort() << std::endl;
		return false;
	}
	
	char data = (boolToSend) ? trueChar_ : falseChar_;  //Converts the bool to char for DE2
	
	SendData(&data, 1);

	return true;
}

//============================================================= 
// METHOD : sendDE2 --DUMMY--
// DESCR. : Always returns true. Made for testing
//============================================================= 
bool DE2_driver::sendDE2(bool boolToSend, int i) 
{
	return true;
}
