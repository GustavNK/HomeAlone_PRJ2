#include "TimeInterval.h"

TimeInterval::TimeInterval(int h1, int m1, int h2, int m2) 
			 : _startTime(h1, m1), _endTime(h2,m2)
{

}

TimeInterval::~TimeInterval()
{
}

void TimeInterval::setStartTime(int hr, int min)
{
	_startTime.setHour(hr);
	_startTime.setMin(min);
}

void TimeInterval::setEndTime(int hr, int min)
{
	_endTime.setHour(hr);
	_endTime.setMin(min);
}

void TimeInterval::print() const
{
	cout << "Starttime: ";
	_startTime.print();
	cout << ". Endtime: ";
	_endTime.print();

}
