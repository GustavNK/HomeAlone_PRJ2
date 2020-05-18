/*
Created by:KA
Date started: 29/04/2020
Date finised:
Project: HomeAlone A/S
*/
#include <list>
#include <vector>
#include "Activity.h"

class Log
{
public:
	Log(bool autoText);
	void archiveNewActivity(string reason); //set-method
	void archiveNewActivity(Activity activity); //set-method
	Activity getActivity(int index) const;
	int getSize() const;
	Log getReason(string reason) const;
	void returnList(list<string>&);
	void showLogList() const; //Log må ikke printe, da det er en domain-klasse
private:
	list<Activity> logList_;
};