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
#include <iostream> 

using namespace std; 


class Time_class
{
public:
	Time_class(int h = 0, int min = 0, int sec = 0);
	
	//setter
	void setHour(int);
	void setMin(int);
	void setSec(int);

	//getter
	void getTime_class(int& hours, int& minutes) const;
	int getHour() const;
	int getMin() const;
	int getSec() const;

	//print
	void print() const; 

private:
	//Attributes
	int _hr;
	int _min;
	int _sec;

};
