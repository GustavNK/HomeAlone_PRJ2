#pragma once
#include <ctime>

class TimeInterval {


public:
	TimeInterval();
	TimeInterval(time_t start, time_t end);
	~TimeInterval();
	void setStartTime();
	void setEndTime();


private: 
	time_t startTime;
	time_t endTime;
	// 


};


