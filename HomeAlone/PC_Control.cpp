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
#include "PC_Control.h"
#include <string.h>
#include <list>
#include <iterator>

using namespace std;

//Constructor (DE2 SKAL RETTES TIL) 
PC_Control::PC_Control(bool systemStatus) : _inputs(Gui_In()), _output(GUIout()), _DE2(DE2_driver(1,1))
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
	
}


void PC_Control::updateGui() 
{
	//Front => Login
	Login();

	//Read input
	_input = _inputs.readInput();

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


			break;

		//Set Timer
		case 5:



			break;

		default: 
			break;
		}
	}
	else {
		switch (_input) {
		//Login
		case 1:
			
			//read signal from DE2-Board
			_loggedIn = true;

			break;
			
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

	switch (_input) {
	case 1:
		if (_ActiveSystem) {
			//Send shutdown-signal through x10 driver
			
			_ActiveSystem = false;
			_log.archiveNewActivity("System deactivated");
		}
		else {
			//Send turn-on-signal through x10 driver
			
			_ActiveSystem = true;
			_log.archiveNewActivity("System activated");
		}
		break;

	default:
		break;
	}
}

void PC_Control::showLog()
{
	//Afhænger af log
	//Måske for-loop 

}

void PC_Control::setTimer()
{
	//Header
	string header = "S\x91t timer";
	
	//Main
	string main = "Vælg hvilket modul du gerne vil s\x91tte timer for: ";

	//Choices

	list<string> choices;
	list<Module*>::iterator it;
	for (it = _modules.begin(); it != _modules.end(); it++) 
	{
		string c1 = (*it)->getInfo();
		choices.push_back(c1);
	}

	
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
