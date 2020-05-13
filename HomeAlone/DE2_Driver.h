#pragma once

#include "C:/Users/Gustav/Documents/GitHub/PRJ2/HomeAlone/HomeAlone/Serial.h"
#include <iostream>

class DE2_driver 
{
public:
	DE2_driver(int comPort, int baudRate);
	char readDe2Char() const;
	char sendDe2Char(char *data) const;
private:
	char trueChar_;
	char falseChar_; //Char send from DE2 when reporting false or true
	int comPort_; //COM port for the DE2 board
	int baudRate_; //Baudrate between DE2 and PCe
};