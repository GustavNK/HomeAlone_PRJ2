#pragma once
#include "DE2_Driver.h"
#include "X10_driver.h"
#include "Log.h"
#include "TimeInterval.h"
#include "User_Interface.h"
#include "GUIout.h"
#include "Serial.h"
#include "Gui_In.h"
#include "Module.h"
#include "Lamp.h"



class PC_Control
{
public: 
	//Constructor - Able to set Systemstatus, only because it makes it easier for testing right now. 
	PC_Control(bool systemStatus);

	//Update Gui
	void updateGui();

	//Standard menu
	void standardFront(list<string> &choice);

	//Login
	void Login();

	//Menu
	void MainMenu();

	//Logout
	void Logout();

	//Activate system
	void activateSystem();

	//Change code
	void changeCode();

	//Show log
	void showLog();

	//Set Timer
	void setTimer();
	void setTimerMain(string m);

	//Modules
	void addModule(Module* m);


private: 
	//User interface
	GUIout _output;
	Gui_In _inputs;

	//Input
	int _input;

	//Logic bools
	bool _loggedIn;
	bool _ActiveSystem; 
	bool _TimerActive;
	bool _Shutdown;

	//UART
	DE2_driver _DE2;
	X10_driver _x10;

	//Log
	Log _log;

	//Array consisting of modules
	vector<Module*> _modules;


};

