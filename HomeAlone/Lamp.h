#pragma once
#include "Module.h"
#include "TimeInterval.h"
#include <string>
#include <stdio.h>
#include <cstring>

class Lamp : public Module
{
public: 
	//Constructor
	Lamp(char house ='X', int unit = 0);

	//Get
	string getTimeInterval();

	//Set
	virtual void setLampTimeInterval(int h1,int m1,int h2,int m2);

	//print
	virtual string getInfo();

private: 
	TimeInterval _timeInterval;

};

