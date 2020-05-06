#include <ctime>
#include "Activity.h"

Activity::Activity(string reason)
{
	time_t date_time_ = time(0);

	reason_ = reason;
}

void Activity::setDateTime()
{
	time_t date_time_ = time(0);
}

string Activity::getDateTime()
{
	return date_time_;
}

void Activity::setReason(string reason)
{
	reason_ = reason;
}

string Activity::getReason()
{
	return reason_;
}

void Activity::print() const
{
	cout << "Date and time: " << date_time_ << endl;
	cout << "Reason: " << reason_ << endl;
}
