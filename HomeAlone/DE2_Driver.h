#pragma once

#include "Serial.h"
#include <iostream>

//Char send from DE2 when reporting false or true
#define trueChar  'z';
#define falseChar '0';


class DE2_driver : public CSerial
{
public:
	DE2_driver(int comPort, int baudRate = 9600); //comPort is the USB port used by the UART driver
	char readDe2Char();
	char readDe2Char(int i); //Dummy function
	bool sendDe2Char(const char data) ;
	bool sendDe2Char(char data, int i); //Dummy function
private:
	int comPort_; //COM port for the DE2 board
	int baudRate_; //Baudrate between DE2 and PC
};