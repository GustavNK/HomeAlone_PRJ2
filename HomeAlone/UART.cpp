//======================================================================== 
// FILENAME : UART.cpp
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

#include "UART.h"

UART::UART(int comPort, int baudRate) : CSerial()
{
	setBaudRate(baudRate);
	setComPort(comPort);
}

//============================================================= 
// METHOD : setComPort
// DESCR. : Sets the comPort between 1 and 30. 0 is default
//============================================================= 
void UART::setComPort(int comPort)
{
	comPort_ = (comPort > 0 && comPort < 31) ? comPort_ : 0;
}

//============================================================= 
// METHOD : getCompPort
// DESCR. : Returns the current value for compPort
//============================================================= 
int UART::getComPort()
{
	return comPort_;
}

//============================================================= 
// METHOD : setBaudRate
// DESCR. : Sets the BaudRate. Must be either 9600 or 115200, the commonly only BaudRates
//============================================================= 
void UART::setBaudRate(int baudRate)
{
	baudRate_ = (baudRate == 115200) ? baudRate : 9600;
}

//============================================================= 
// METHOD : getBaudRate
// DESCR. : return the baudRate
//============================================================= 
int UART::getBaudRate()
{
	return baudRate_;
}
