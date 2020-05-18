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
	Activity getActivity(int index);
	int getSize();
	Log getReason(string reason);
	void showLogList() const;
private:
	list<Activity> logList_;
};