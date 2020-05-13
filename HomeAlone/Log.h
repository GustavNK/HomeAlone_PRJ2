/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#include <list>
#include <vector>
#include "Activity.h"

//Erklære log et sted og så referer til det med pointers, så man kun har en liste. Singletons
//archiveNewActivity("Fejl i log")

class Log
{
public:
	Log();
	void archiveNewActivity(string reason); //set-metode
	string getActivity(); //getReason og getDateTime
	int getSize();
	void print() const;
private:
	list<Activity> logList_;
};