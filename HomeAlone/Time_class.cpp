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
#include "Time_class.h"

//Constructor 
Time_class::Time_class(int hr, int min, int sec)
{
	setHour(hr);
	setMin(min);
	setSec(sec);
}

//Setter
void Time_class::setHour(int hr)
{
	_hr = ((0 < hr) && ( hr < 24) ? hr : 0);
}

void Time_class::setMin(int min)
{
	_min = ((0 < min) && (min < 60) ? min : 0);
}

void Time_class::setSec(int sec)
{
	_sec = ((0 < sec) && (sec < 60) ? sec : 0);
}

//Getter
void Time_class::getTime_class(int& hours, int& minutes) const
{
	hours = _hr;
	minutes = _min;
}

int Time_class::getHour() const
{
	return _hr;
}

int Time_class::getMin() const
{
	return _min;
}

int Time_class::getSec() const
{
	return _sec;
}

void Time_class::print() const
{
	if (_hr < 10) {
		cout << "0";
	}
	cout << _hr << ":";

	if (_min < 10) {
		cout << "0";
	}
	cout << _min; 
}
