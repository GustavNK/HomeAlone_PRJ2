//======================================================================== 
// FILENAME : Module.cpp
// CREATED  : 14/05/20
// AUTHOR   : AnnSo
// DESCR.   : An abstract class, which contain the main functions of a safety module.
//
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <15.05.20> Initial creation and push into branch
// 1.1 <16.05.20> Made into a child of CSerial and better comments
//========================================================================
#include "Module.h"
#include <iostream>

using namespace std;

Module::Module(char house, int unit)
{
	setHouse(house);
	setUnit(unit);
}

char Module::getHouse() const
{
	return _house;
}

int Module::getUnit() const
{
	return _unit;
}

void Module::setHouse(char h)
{
	_house = ((h >= 'A') && (h <= 'P') ? h : 'X');
}

void Module::setUnit(int u)
{
	_unit = ((u > 0) && (u < 17) ? u : 0);
}

string Module::getInfo()
{
	string s = "House: ";
	s += _house;
	s.append(". Unit: ");
	s += to_string(_unit);
	
	return s;
}
