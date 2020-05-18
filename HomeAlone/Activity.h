/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Activity
{
public:
	Activity(string reason);
	Activity(time_t time, string reason);
	void setDateTime();
	time_t getDateTime() const;
	void setReason(string reason);
	string getReason() const;
	void print() const;
private:
	string reason_;
	time_t date_time_;
};