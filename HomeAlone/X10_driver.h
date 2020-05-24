//======================================================================== 
// FILENAME  : X10_drriver.h
// CREATED   : 14/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the UART connection to Arduino Transmitter
//  
//------------------------------------------------------------------------ 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <14.05.20><GustavNK> Initial creation and writng of class
// 2.0 <15.05.20><GustavNK> Remade into a child of UART
//							Split sendMessage() with a sepearte manchester translator
//
//------------------------------------------------------------------------ 
// TODO
//
//========================================================================

#pragma once
#include "UART.h"
#include <string>
#include <iostream>
#include "function.h"

using namespace std;

class X10_driver : public UART
{
public:
	X10_driver(int comPort_ = 2, int baudRate_ = 9600);
	bool sendMessage(char house, int unit, function func); //func can be int or enum class function (Ex: 2 or function::On)
	bool sendMessage(char house, int unit, function func, int dummy); //Dummy function
private:
	void manchesterMessage(char house, int unit, function func, char* message);
};