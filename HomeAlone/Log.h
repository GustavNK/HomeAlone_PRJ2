#include <list>
#include <vector>
#include "Activity.h"

//Erkl�re log et sted og s� referer til det med pointers, s� man kun har en liste. Singletons
//archiveNewActivity("Fejl i log")

class Log
{
public:
	Log();
	void archiveNewActivity(string reason);
	void print() const;
private:
	list<Activity> logList_;
};