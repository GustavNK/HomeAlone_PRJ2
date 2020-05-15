#pragma once
#include "DE2_Driver.h"
#include "Log.h"
#include "TimeInterval.h"
#include "User_Interface.h"
#include "GUIout.h"
#include "Serial.h"
#include "Gui_In.h"
#include "Module.h"



class PC_Control
{
public: 
	//Constructor
	PC_Control(bool systemStatus);

	//Update Gui
	void updateGui();

	//Set standard menu
	void standardFront(list<string> &choice);

	//Set Login
	void Login();

	//Menu
	void MainMenu();

	//Set Logout
	void Logout();

	//Activate system
	void activateSystem();

	//set Change code
	void changeCode();

	//Show log
	void showLog();

	//Set setTimer
	void setTimerOut();


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
	//Serial _x10;

	//Log
	Log _log;

	//Liste af moduler
	list<Modul> _modules; 

	//Set Timer
	TimeInterval _TI;
	
};

