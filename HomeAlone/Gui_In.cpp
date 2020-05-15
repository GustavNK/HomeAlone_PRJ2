#include "Gui_In.h"
#include <iostream>
#include <istream>

using namespace std;

Gui_In::Gui_In()
{
	_input = 0;
}

int Gui_In::readInput()
{
	int input;
	cin >> input;
	_input = ((input > 0) && (input < 60) ? _input : 0);

	return _input;
}
