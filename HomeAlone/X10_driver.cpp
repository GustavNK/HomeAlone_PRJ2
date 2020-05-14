//======================================================================== 
// FILENAME  : X10_drriver.cpp
// CREATED   : 14/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the UART connection to Arduino Transmitter
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <14.05.20><GustavNK> Initial creation
//========================================================================

#include "X10_driver.h"

//============================================================= 
// METHOD : X10_driver
// DESCR. : Constructor
//============================================================= 
X10_driver::X10_driver(int comPort, int baudRate) : CSerial()
{
	comPort_ = comPort;
	baudRate_ = baudRate;
}

//============================================================= 
// METHOD : sendDe2Char --DUMMY--
// DESCR. : Always returns true. Made for testing
//============================================================= 
bool X10_driver::sendMessage(char house, int unit, function func)
{
	char message[3]; //Creates array which is to be send to Transmitter

	switch (house) {
		case 'A': message[0] = 0b01101001;
		case 'B': message[0] = 0b10101001;
		case 'C': message[0] = 0b01011001;
		case 'D': message[0] = 0b10011001;
		case 'E': message[0] = 0b01010110;
		case 'F': message[0] = 0b10010110;
		case 'G': message[0] = 0b01100110;
		case 'H': message[0] = 0b10100110;
		case 'I': message[0] = 0b01101010;
		case 'J': message[0] = 0b10101010;
		case 'K': message[0] = 0b01011010;
		case 'L': message[0] = 0b10011010;
		case 'M': message[0] = 0b01010101;
		case 'N': message[0] = 0b10010101;
		case 'O': message[0] = 0b01100101;
		case 'P': message[0] = 0b10100101;
		default : message[0] = 0b01101001; // Default to case 'A'
	}

	switch (unit) {
		case 1 : message[1] = 0b01101001;
		case 2 : message[1] = 0b10101001;
		case 3 : message[1] = 0b01011001;
		case 4 : message[1] = 0b10011001;
		case 5 : message[1] = 0b01010110;
		case 6 : message[1] = 0b10010110;
		case 7 : message[1] = 0b01100110;
		case 8 : message[1] = 0b10100110;
		case 9 : message[1] = 0b01101010;
		case 10 : message[1] = 0b10101010;
		case 11 : message[1] = 0b01011010;
		case 12 : message[1] = 0b10011010;
		case 13 : message[1] = 0b01010101;
		case 14 : message[1] = 0b10010101;
		case 15 : message[1] = 0b01100101;
		case 16 : message[1] = 0b10100101;
		default : message[1] = 0b01101001; //default to case 1
	}

	switch (func) {
		case function::All_Units_Off: message[2] = 0b01010101;
		case function::All_Units_On: message[2] = 0b01010110;
		case function::On: message[2] = 0b01011001;
		case function::Off: message[2] = 0b01011010;
		case function::Dim: message[2] = 0b01100101;
		case function::Bright: message[2] = 0b01100110;
		case function::All_Lights_Off: message[2] = 0b01101001;
		case function::Extended_Code: message[2] = 0b01101010;
		case function::Hail_Request: message[2] = 0b10010101;
		case function::Hail_Acknowledge: message[2] = 0b10010110;
		case function::Pre_set_Dim: message[2] = 0b10011001;
		case function::Extended_Code_Analog: message[2] = 0b10100101;
		case function::Status_On: message[2] = 0b10100110;
		case function::Status_Off: message[2] = 0b10101001;
		case function::Status_Request: message[2] = 0b10101010;
		default: message[2] = 0b01010101; //default to case 1 
	}
	
	//Sending the created message
	if (!Open(comPort_, this->baudRate_))
	{
		std::cout << ("Could not open COM") << this->comPort_ << std::endl;
		return false;
	}

	SendData(message, 3);

	return true;
}
