//======================================================================== 
// FILENAME  : X10_drriver.h
// CREATED   : 014/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the UART connection to Arduino Transmitter
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <14.05.20><GustavNK> Initial creation
//========================================================================

#pragma once
#include "Serial.h"
#include <string>
#include <iostream>

using namespace std;

//Enumeration of the possible functions in X10 protocol
enum class function {
	All_Units_Off,
	All_Units_On,
	On,
	Off,
	Dim,
	Bright,
	All_Lights_Off,
	Extended_Code,
	Hail_Request,
	Hail_Acknowledge,
	Pre_set_Dim,
	Extended_Code_Analog,
	Status_On,
	Status_Off,
	Status_Request
};

class X10_driver : public CSerial
{
public:
	X10_driver(int comPort_, int baudRate_ = 9600);
	bool sendMessage(char house, int unit, function func);

private:
	int comPort_;
	int baudRate_;
};