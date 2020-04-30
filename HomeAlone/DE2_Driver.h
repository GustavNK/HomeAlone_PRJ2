#pragma once
#include "C:/Users/Gustav/Documents/GitHub/PRJ2/HomeAlone/HomeAlone/Serial.h"
#include <iostream>

class DE2_driver 
{
public:
	DE2_driver(int comPort, int baudRate);
	bool readDe2Signal();
private:
	bool de2Signal_;
	int comPort_; //COM port for the DE2 board
	int baudRate_; //Baudrate between DE2 and PC

};