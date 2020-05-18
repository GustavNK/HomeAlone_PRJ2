/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#include <ctime>
#include "Activity.h"

#define MAX_BUF 100

Activity::Activity(string reason)
{
	date_time_ = time(0);

	reason_ = reason;
}

Activity::Activity(time_t time, string reason)
{
	date_time_ = time;
	reason_ = reason;
}

void Activity::setDateTime()
{
	date_time_ = time(0);
}

time_t Activity::getDateTime() const
{
	return date_time_;
}

void Activity::setReason(string reason)
{
	reason_ = reason;
}

string Activity::getReason() const
{
	return reason_;
}

string Activity::getActivityStr() const
{
	struct tm buf;
	char date_time_string[MAX_BUF];

	localtime_s(&buf, &date_time_);

	strftime(date_time_string, MAX_BUF, "Date: %B, %d, %Y Time: %T ", &buf);
	strcat_s(date_time_string, "Reason: ");
	strcat_s(date_time_string, reason_.c_str());

	return date_time_string;
}

void Activity::print() const
{
	struct tm buf;
	char date_time_string[MAX_BUF];

	localtime_s(&buf, &date_time_);

	strftime(date_time_string, MAX_BUF, "Date: %B, %d, %Y Time: %T ", &buf);

	cout << date_time_string << "Reason: " << reason_ << endl;
}