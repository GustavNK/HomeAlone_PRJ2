
#pragma once
#include <string>

using namespace std;

class Module
{
	//To make modules an abstract class. 
	
public:
	Module(char house = 'X', int unit = 0);
	//Getter
	char getHouse()const; 
	int getUnit()const;

	//Setter
	void setHouse(char h);
	void setUnit(int u); 
	
	virtual void setLampTimeInterval(int h1, int h2, int m1, int m2) = 0;
	virtual string getTimeInterval() = 0;

	virtual string getInfo(); 

private: 
	char _house;
	int _unit;

};

