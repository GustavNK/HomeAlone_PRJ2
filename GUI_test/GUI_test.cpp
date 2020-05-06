#include "../HomeAlone/GUIout.h"
#include <iostream>
#include <list>


int main() {
	GUIout g = GUIout();
	std::cout << "njgisndgjis<";

	string header = "MAIN Menu22";

	list<string> main;
	main.push_back("Log 2: xx.xx - xx:xx:xx");
	main.push_back("-Eh?");
	main.push_back("Log 3: xx.xx - xx:xx:xx");
	main.push_back("-yes");

	list<string> choice;
	choice.push_back("1) Valg");
	choice.push_back("2) Et andet valg");
	choice.push_back("3) Enndnu et valg");
	choice.push_back("4) Der er flere");
	choice.push_back("5) Sidste valg");



	g.draw(header, main, choice);
}