//======================================================================== 
// FILENAME : DE2_Driver.h
// CREATED  : 06/05/20
// AUTHOR	: GustavNK
// DESCR.   : Handles the UART output and input to/from the DE2 Board
//------------------------------------------------------------------------ 
//
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20><GustavNK> Initial creation and inplemnetet into master
// 1.1 <14.05.20><GustavNK> Made into a child of CSerial and better comments
//							Defined true and false char
// 1.2 <15.05.20><GustavNK> Redefined sendDE2 and readDE2 with bools
//							Made trueChar_ and falseChar into const char
// 2.0 <15.05.20><GustavNK>	Made into child og UART, to make comPort and BaudRate
//							the same between DE2_driver and X10_driver
//------------------------------------------------------------------------ 
// TODO
//
//========================================================================


#pragma once
#pragma message ("World object is defined")
#include "UART.h"
#include <iostream>

//Char send from DE2 when reporting false or true

class DE2_driver : public UART
{
public:
	DE2_driver(int comPort = 2, int baudRate = 9600); //comPort is the USB port used by the UART driver
	bool readDE2();
	bool readDE2(int i); //Dummy function
	bool sendDE2(bool data) ;
	bool sendDE2(bool data, int i); //Dummy function
private:
	const char trueChar_ = 'z'; //char seen as true for the DE2
	const char falseChar_ = '0'; //char seen as false for the DE2
};
