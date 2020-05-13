#include <ctime>
#include "Activity.h"

#define MAX_BUF 50

Activity::Activity(string reason)
{
	time_t date_time_ = time(0);

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

void Activity::print() const
{
	//t_time to string
	struct tm buf;
	char date_time_string[MAX_BUF];

	localtime_s(&buf, &date_time_);
	strftime(date_time_string, MAX_BUF, "Date: %B, %d, %Y Time: %T", &buf);

	cout << date_time_string << " Reason: " << reason_ << endl;
}
