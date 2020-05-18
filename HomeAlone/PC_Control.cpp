/*
Created by:
	ART
Date started:
	06/05/2020
Date finised:
	--/--/2020



Project:
	2. Semester : HomeAlone A/S
*/
#pragma once
#include "PC_Control.h"
#include <string.h>
#include <list>
#include <iterator>

using namespace std;

//Constructor (DE2 SKAL RETTES TIL) 
PC_Control::PC_Control(bool systemStatus) : _inputs(Gui_In()), _output(GUIout()), _DE2(DE2_driver()), _x10(X10_driver())
{
	
	_ActiveSystem = systemStatus;
	
	//default input
	_input = 0;
	
	//Set login to false
	_loggedIn = false;

	//Whether a timer is active for a module
	_TimerActive = false;
	
	//Controls while-loop in main. Set true to exit program
	_Shutdown = false; 

	//Initiate 1 lamp to list of modules.
	Lamp l1;
	_modules.push_back(&l1);
	
}


void PC_Control::updateGui() 
{
	string str1, str2, str3, str4;
	
	
	//Handle input
	if (_loggedIn) {
		MainMenu();
		_log.archiveNewActivity("Login");

		switch (_input) 
		{

		//Logout
		case 1: 
			_log.archiveNewActivity("Logout");
			Logout();
			break;

		//Activate/Deactivate system
		case 2:
			activateSystem();
			break;

		//Change code on DE2-Board
		case 3: 
			changeCode();
			break;

		//Show Log
		case 4: 
			showLog();

			break;

		//Set Timer (Can currently only handle one lamp. Not final.)
		case 5:
			setTimer();
			_input = _inputs.readInput();

			switch (_input){
			case 1: 
				int starthr{}, endhr{}, startmin{}, endmin{};
				str1 = "Enter start time (hour between 0 and 23)";
				setTimerMain(str1);
				_input = starthr;
				str2 = "Enter start time (minute value between 0 and 59)";
				setTimerMain(str2);
				_input = startmin;
				str3 = "Enter end time (hour between 0 and 23)";
				setTimerMain(str3);
				_input = endhr;
				str4 = "Enter end time (minute value between 0 and 59)";
				setTimerMain(str4);
				_input = endmin;
				_modules[0]->setLampTimeInterval(starthr, endhr, startmin, endmin);

				_log.archiveNewActivity("Timer set for lamp");
				_TimerActive = true;
				break;
			default: 
				break;
			}
			break;

		default: 
			break;
		}
	}
	else {
		//Front => Login
		Login();

		//Read input
		_input = _inputs.readInput();

		switch (_input) {
		//Login
		case 1:
			
			//read signal from DE2-Board
			_DE2.readDE2();
			if (_DE2.readDE2(1)) {
				_loggedIn = true;
				break;
			}
			else {
				break;
			}
			
		//Exit
		case 2:
			_Shutdown = true;
			exit(1);
			break;

		default: 
			cout << "Try again" << endl;
			break;
		}

	}

}


void PC_Control::standardFront(list<string> &choice)
{
	//Header
	string header = "System Info";

	//Left side
	list<string> left;
	string left1 = "Tilstand";
	string left2 = "DE2 l\x86s";
	string left3 = "Alarm";
	left.push_back(left1);
	left.push_back(left2);
	left.push_back(left3);

	//Right side
	list<string> right;
	string right1;
	if (_ActiveSystem) {
		right1 = "Aktiveret";
	}
	else {
		right1 = "Deaktiveret";
	}
	
	string right2;
	if (_loggedIn) {
		right2 = "L\x86st op";
	}
	else {
		right2 = "L\x86st";
	}

	string right3;
	if (_TimerActive) {
		right3 = "Timer aktiv";
	}
	else {
		right3 = "Timer inaktiv";
	}
	right.push_back(right1);
	right.push_back(right2);
	right.push_back(right3);

	_output.draw(header,left,right,choice);
}



void PC_Control::Login()
{
	list<string> choices;
	string c1 = "Log Ind";
	string c2 = "Exit";
	choices.push_back(c1);
	choices.push_back(c2);

	standardFront(choices);
}

void PC_Control::MainMenu()
{
	list<string> choices;
	string c1 = "Log ud";
	string c2 = "Aktiver system";
	string c3 = "Skift kode";
	string c4 = "Log";
	string c5 = "Indstil timer";
	choices.push_back(c1);
	choices.push_back(c2);
	choices.push_back(c3);
	choices.push_back(c4);
	choices.push_back(c5);

	standardFront(choices);
}

void PC_Control::Logout()
{
	_loggedIn = false;
}

void PC_Control::activateSystem()
{

	list<string> choices;
	string c1 = "Confirm";
	string c2 = "Exit";
	standardFront(choices);
	_input = _inputs.readInput();
	switch (_input) {
	case 1:
		if (_ActiveSystem) {

			//Send shutdown-signal through x10 driver
			_x10.sendMessage((_modules[0]->getHouse()), (_modules[0]->getUnit()), function::All_Units_On,1);
			_ActiveSystem = false;
			_log.archiveNewActivity("System deactivated");
		}
		else {
			//Send turn-on-signal through x10 driver
			_x10.sendMessage((_modules[0]->getHouse()), (_modules[0]->getUnit()), function::All_Units_Off, 1);
			_ActiveSystem = true;
			_log.archiveNewActivity("System activated");
		}
		break;

	default:
		break;
	}
}

void PC_Control::changeCode()
{
	//Header
	string header = "Skift kode på DE2-Board";

	//Main
	string s1 = "For at skifte koden skal man gøre følgende:";
	string s2 = "1. ";

	//Choices
	list<string> choices;
	string s1 = "G\x86 til hovedemenu.";

}

void PC_Control::showLog()
{
	//Header
	string header = "Vis Log";

	//Main
	list<string> mains;
	_log.returnList(mains);

	//Choices
	list<string> choices;
	string s1 = "G\x86 til hovedemenu.";
	_output.draw(header, mains, choices);

}

void PC_Control::setTimer()
{
	//Header
	string header = "S\x91t timer";
	
	//Main
	list<string> mains;

	string main = "V\x91lg hvilket modul du gerne vil s\x91tte timer for. V\x91r opm\x91rksom p\x86 at der kun kan s\x91ttes tidsinterval for lamper.";
	mains.push_back(main);

	//Choices

	list<string> choices;
	
	for (int i = 0 ; i < _modules.size() ; i++) 
	{
		string c1 = _modules[i]->getInfo();
		choices.push_back(c1);
	}

	_output.draw(header,mains,choices);


}

void PC_Control::setTimerMain(string m)
{
	//Header
	string header = "S\x91t Timer";

	//Main

	list<string> mains;
	string main = m;
	mains.push_back(main);

	//Choices
	list<string> choices;

	_output.draw(header, mains, choices);

}
