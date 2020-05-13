/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#include <iterator>
#include "Log.h"

int MAX_SIZE = 50;

Log::Log()
{

	//dynamisk hukommelse array med maks plads til 50
	//opret logList og startString skal indsættes på første plads
	
	logList_.push_front(Activity("Log begyndt."));
	
	//move(local.begin(), local.end(), back_inserter(logList_));
}

void Log::archiveNewActivity(string reason)
{
	//int size = logList_.size();
	//list<Activity>::iterator secondPlace = logList_.begin(); //Points to first element in the list
	//advance(secondPlace, 1); //Increment secondPlace by 1 position

	//if(size == MAX_SIZE)
	//{
	//	logList_.erase(secondPlace);
	//}

	//New activity inserted at the back of the list
	logList_.push_back(Activity(reason)); //new før Activity?
}

string Log::getActivity()
{
	//getDateTime time_t to string

	//getReason

	return string();
}

int Log::getSize()
{
	int size = logList_.size();

	cout << "Number of elements in log: " << size << endl;

	return size;
}

void Log::print() const
{
	list<Activity>::const_iterator logListPtr;

	for (logListPtr = logList_.begin(); logListPtr != logList_.end(); logListPtr++)
	{
		logListPtr->print();
	}
	cout << endl;
}
