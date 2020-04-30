/*
Created by:
	ART
Date started:
	29/04/2020
Date finised:
	-- -- --
Project:
	2. Semester : HomeAlone A/S
*/
#pragma once
#include "Time_class.h"

class TimeInterval {


public:
	//Constructor/Destructor
	TimeInterval(int h1 = 0, int m1 = 0, int h2 = 0 , int m2 = 0);
	~TimeInterval();
	
	//Setter
	void setStartTime(int, int);
	void setEndTime(int, int);

	//Getter
	void getTimeInterval(char* start, char* end);

	//others
	void print() const;

private: 
	Time_class _startTime;
	Time_class _endTime;

};


