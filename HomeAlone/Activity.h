#pragma once
#include <iostream>

using namespace std;

class Activity
{
public:
	Activity(string reason);
	void setDateTime();
	string getDateTime();
	void setReason(string reason);
	string getReason();
	void print() const;
private:
	string reason_;
	string date_time_;
};

