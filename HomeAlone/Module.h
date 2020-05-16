
#pragma once
#include <string>;

using namespace std;

class Module
{
	//To make modules an abstract class. 
protected:
	Module(char house = 'X', int unit = 0);

public:
	//Getter
	char getHouse()const; 
	int getUnit()const;

	//Setter
	void setHouse(char h);
	void setUnit(int u); 

	virtual string getInfo() const; 

private: 
	char _house;
	int _unit;

};

