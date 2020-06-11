/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#include <iterator>
#include <algorithm>
#include "Log.h"

int MAX_SIZE = 10;

Log::Log(bool autoText)
{
	//Create logList and insert "Log begyndt" at the beginning of the list
	if (autoText)
		logList_.push_front(Activity("Log begyndt."));
}

void Log::archiveNewActivity(string reason)
{
	int size = logList_.size();

	if (size == MAX_SIZE)
	{
		list<Activity>::iterator secondPlace = logList_.begin(); //Points to first element in the list
		advance(secondPlace, 1); //Increment secondPlace by 1 position
		logList_.erase(secondPlace);
	}

	//New activity inserted at the back of the list
	logList_.push_back(Activity(reason));
}

void Log::archiveNewActivity(Activity activity)
{
	//New activity inserted at the back of the list
	logList_.push_back(activity);
}

Activity Log::getActivity(int index) const
{
	list<Activity>::const_iterator indexPlace = logList_.begin(); //Points to first element in the list

	if (index <= logList_.size())
	{
		advance(indexPlace, index); //Increment secondPlace by index position
	}

	return *indexPlace;
}

int Log::getSize() const
{
	return logList_.size();
}

//Log Log::searchReason(string reason) const
//{
//	Log reasonLog(false);
//	list<Activity>::const_iterator logListPtr;
//
//	for (logListPtr = logList_.begin(); logListPtr != logList_.end(); logListPtr++)
//	{
//		if (logListPtr->getReason() == reason)
//		{
//			reasonLog.archiveNewActivity(*logListPtr);
//		}
//	}
//	return reasonLog;
//}

void Log::searchReason(string reason, list<string>& stringLogList) const
{
	list<Activity>::const_iterator logListPtr;
	string tmpStr;

	for (logListPtr = logList_.begin(); logListPtr != logList_.end(); logListPtr++)
	{

		transform(reason.begin(), reason.end(), reason.begin(), ::tolower);

		tmpStr = logListPtr->getReason();
		transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), ::tolower);

		//n = tmpStr.find(reason);
		if (tmpStr.find(reason) != -1)
		{
			stringLogList.push_back(logListPtr->getActivityStr());
		}
	}
}

void Log::returnList(list<string>& stringLogList)
{
	list<Activity>::iterator logListPtr;

	for (logListPtr = logList_.begin(); logListPtr != logList_.end(); logListPtr++)
	{
		//Skal ikke printe, men ligge date_time og reason sammen i en list<string>
		stringLogList.push_back(logListPtr->getActivityStr());

	}
}

void Log::showLogList() const //Skal ikke være med i Log
{
	list<Activity>::const_iterator logListPtr;

	for (logListPtr = logList_.begin(); logListPtr != logList_.end(); logListPtr++)
	{
		logListPtr->print();
	}
	cout << endl;
}
