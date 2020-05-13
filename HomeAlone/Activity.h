#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Activity
{
public:
	Activity(string reason);
	void setDateTime();
	time_t getDateTime() const;
	void setReason(string reason);
	string getReason() const;
	void print() const;
private:
	string reason_;
	time_t date_time_;
};

