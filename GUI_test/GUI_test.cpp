#include "../HomeAlone/GUIout.h"
#include <iostream>
#include <list>


int main() {
	GUIout g = GUIout();

	string header = "MAIN";

	list<string> main;
	main.push_back("as");
	main.push_back("as");
	main.push_back("as");
	main.push_back("as");
	main.push_back("as22sdfdgfdgsfdgsfdgsdf22");

	list<string> choice;
	choice.push_back("1) hgellofs2");
	choice.push_back("2) hgellofs3");
	choice.push_back("3) hgellofs4");
	choice.push_back("4) hgellofs5");
	choice.push_back("4) hgellofs22sdf2");



	g.draw(header, main, choice);
}