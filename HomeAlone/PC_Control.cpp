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
PC_Control::PC_Control(bool systemStatus) : _inputs(Gui_In()), _output(GUIout()), _DE2(DE2_driver()), _x10(X10_driver()),_log(Log(true))
{
	
	_ActiveSystem = systemStatus;
	
	//default input
	_input = 0;
	
	//Set login to false
	_loggedIn = false;

	//Whether a timer is active for a module
	_TimerActive = false;	
	
}



void PC_Control::updateGui() 
{
	
	
	
	//Handle input
	if (_loggedIn) {
		mainMenu();
		_input = _inputs.readInput();
		switch (_input) 
		{

		//Logout
		case 1: 
			_log.archiveNewActivity("Logout");
			logout();
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

			break;

		default: 
			break;
		}
	}
	else {
		//Login method
		login();
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

	_output.draw(header,right,left,choice);
}

void PC_Control::login()
{
	list<string> choices;
	string c1 = "Log Ind";
	string c2 = "Exit";
	choices.push_back(c1);
	choices.push_back(c2);

	standardFront(choices);

	//Read input
	_input = _inputs.readInput();

	switch (_input) {
		cout << "2";
		//Login
	case 1:
		//Send ready signal to DE2-board
		_DE2.sendDE2(true, 1);

		//read signal from DE2-Board
		if (_DE2.readDE2(1)) {
			_loggedIn = true;
			_log.archiveNewActivity("Login");
			break;
		}
		else {
			_log.archiveNewActivity("Login mislykkedes");

			break;
		}

		//Exit
	case 2:
		exit(1);
		break;

	default:
		cout << "Try again" << endl;
		break;
	}

}

void PC_Control::mainMenu()
{
	list<string> choices;
	string c1 = "Log ud";
	string c2;
	if (_ActiveSystem) {
		 c2 = "Deaktiver system";
	}
	else {
		c2 = "Aktiver system";
	}
	
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

void PC_Control::logout()
{
	_loggedIn = false;
}

void PC_Control::activateSystem()
{

	list<string> choices;
	string c1 = "Confirm";
	string c2 = "Exit";
	choices.push_back(c1);
	choices.push_back(c2);

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
	_DE2.sendDE2(false,1);

	//Header
	string header = "Skift kode p\x86 DE2-Board";

	//Main
	list<string> main;
	string m1 = "For at skifte koden skal man g\x9Bre f\x9Blgende:";
	string m2 = "1. Indtast den gamle kode og tryk p\x86 key 1.";
	string m3 = "2. Indtast den nye kode og tryk p\x86 key 2.";
	string m4 = "3. Indtast den nye kode igen og tryk p\x86 key 3";
	string m5 = "4. Den nye kode skulle nu v\x91re sat.";
	string m6 = "OBS: For at afbryde skift af kode, tryk p\x86 reset (key 0)";
	main.push_back(m1);
	main.push_back(m2);
	main.push_back(m3);
	main.push_back(m4);
	main.push_back(m5);
	main.push_back(m6);

	//Choices
	list<string> choices;
	string c1 = "G\x86 til hovedemenu.";
	choices.push_back(c1);

	//Draw terminal
	_output.draw(header, main, choices);

	//Læs svar fra DE2-board
	if (_DE2.readDE2()) {
		_log.archiveNewActivity("Kode \x91ndret");
	}
	else {
		_log.archiveNewActivity("Kode fors\x9Bgt \x91ndret uden held.");
	}

	_input = _inputs.readInput();
	switch (_input) {
	case 1: 
		break;
	default: 
		break;
	}

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
	string c1 = "G\x86 til hovedemenu.";
	choices.push_back(c1);
	_output.draw(header, mains, choices);

	_log.archiveNewActivity("Log vist");
	
	_input = _inputs.readInput();
	switch (_input) {
	case 1:

		break;
	}

}

void PC_Control::setTimer()
{
	string str1, str2, str3, str4, message;
	int starthr{}, endhr{}, startmin{}, endmin{};
	//Header
	string header = "S\x91t timer";
	
	//Main
	list<string> mains;

	string m1 = "V\x91lg hvilket modul du gerne vil s\x91tte timer for. V\x91r opm\x91rksom p\x86 at der kun kan s\x91ttes tidsinterval for lamper.";
	string m2 = "Nuværende timer sat til: ";
	m2.append(_modules[0]->getTimeInterval());
	
	mains.push_back(m1);
	mains.push_back(m2);
	

	//Choices

	list<string> choices;
	
	string c1 = _modules[0]->getInfo();
	string c2;

	if (_TimerActive) {
		c2 = "Deaktiver nuv\x91rende timer";
	}
	else {
		c2 = "Aktiver nuv\x91rende timer";
	}
	
	string c3 = "G\x86 til hovedemenu.";
	choices.push_back(c1);
	choices.push_back(c2);
	choices.push_back(c3);

	_output.draw(header,mains,choices);

	_input = _inputs.readInput();


	switch (_input) {
	case 1:

		str1 = "Indtast starttidspunkt (time-v\x91rdi mellem 0 og 23 / default = 0)";
		setTimerMain(str1);
		starthr = _inputs.readInput();
		str2 = "Indtast starttidspunkt (minut-v\x91rdi mellem 0 og 59 / default = 0)";
		setTimerMain(str2);
		startmin = _inputs.readInput();
		str3 = "Indtast sluttidspunkt (time-v\x91rdi mellem 0 og 23  / default = 0)";
		setTimerMain(str3);
		endhr = _inputs.readInput();
		str4 = "Indtast sluttidspunkt (minut-v\x91rdi mellem 0 og 59 / default = 0)";
		setTimerMain(str4);
		endmin = _inputs.readInput();
		_modules[0]->setLampTimeInterval(starthr, startmin, endhr, endmin);

		message = "Timer sat til: (Start: ";
		message += to_string(starthr);
		message.append(":");
		if (startmin < 10) {
			message += to_string(0);
			message += to_string(startmin);
		}
		else {
			message += to_string(startmin);
		}

		message.append(") (Slut:");
		message += to_string(endhr);
		message.append(":");
		if (endmin < 10) {
			message += to_string(0);
			message += to_string(endmin);
		}
		else {
			message += to_string(endmin);
		}
		message.append(")");

		_log.archiveNewActivity(message);
		_TimerActive = true;
		break;

	case 2:
		if (_TimerActive) {
			_TimerActive = false;
			_log.archiveNewActivity("Timer aktiveret");
		}
		else {
			_TimerActive = true;
			_log.archiveNewActivity("Timer deaktiveret");
		}

		break;
	default:
		break;
	}

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

void PC_Control::addModule(Module* m)
{
	_modules.push_back(m);

}
