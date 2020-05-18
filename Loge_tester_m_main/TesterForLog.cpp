#include <string>
#include "../HomeAlone/Log.h"
#include <Windows.h>

int main(void) {

	Activity ac("");

	Log log1(true);

	log1.archiveNewActivity("Log in");

	for (int i = 0; i < 15; i++)
	{
		log1.archiveNewActivity("Log " + to_string(i));
	}

	log1.archiveNewActivity("Log out");

	log1.showLogList();

	//Antal gemte aktiviteter
	cout << "Number of elements in log: " << log1.getSize() << endl << endl;

	//Test af getActivity()
	ac = log1.getActivity(0);
	ac.print();

	ac = log1.getActivity(2);
	ac.print();

	cout << endl;

	list<string> l1;
	list<string>::const_iterator strListPtr;
	log1.returnList(l1);
	for (strListPtr = l1.begin(); strListPtr != l1.end(); strListPtr++)
	{
		cout << strListPtr->c_str() << endl;
	}
	cout << endl;

	//Test af getReason()
	cout << "Ny test" << endl;
	Log log2(true), log3(false);
	log2.archiveNewActivity("Log in");
	log2.archiveNewActivity("Andet");
	log2.archiveNewActivity("Log out");
	Sleep(1000);
	log2.archiveNewActivity("Log in");
	log2.archiveNewActivity("Andet");
	log2.archiveNewActivity("Log out");
	log2.showLogList();

	cout << "Search for: Log in" << endl;

	log3 = log2.getReason("Log in");  // returnere en ny log
	log3.showLogList();

	return 0;
}