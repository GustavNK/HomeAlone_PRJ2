//======================================================================== 
// FILENAME : UART.h
// CREATED  : 06/05/20
// AUTHOR	: GustavNK
// DESCR.   : Base class for the DE2 and X10 drivers. Handles comPort and baudRate
//------------------------------------------------------------------------ 
//
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20><GustavNK> Initial creation and copied methods from DE2
//------------------------------------------------------------------------ 
// TODO
//
//========================================================================

#pragma once
#include "Serial.h"

class UART : public CSerial
{
public:
	UART(int comPort = 2, int baudRate = 9600);
	void setComPort(int comPort);
	int getComPort();
	void setBaudRate(int baudRate);
	int getBaudRate();
private:
	int comPort_; //COM port for the DE2 board
	int baudRate_; //Baudrate between DE2 and PCe
};

