#pragma once
#include "Module.h"
#include "TimeInterval.h"

class Lamp : public Module
{
public: 
	//Constructor
	Lamp(char house ='X', int unit = 0);

	//Get
	TimeInterval* getTimeInterval();

	//Set
	virtual void setLampTimeInterval(int h1,int h2,int m1,int m2);

	//print
	virtual string getInfo();

private: 
	TimeInterval _timeInterval;

};

