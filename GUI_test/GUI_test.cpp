#pragma once
#include "../HomeAlone/GUIout.h"
#include <iostream>
#include <list>
#include "../HomeAlone/DE2_driver.h"


int main() {

	GUIout g = GUIout();

	string header = "MAIN Med2";

	list<string> main;
	main.push_back("Den her");
	main.push_back("En mere");
	main.push_back("Noget tekst");
	main.push_back("Mere tekst");

	list<string> mainR;
	main.push_back("Jaja");
	main.push_back("Tekst");
	main.push_back("Nej nej");
	main.push_back("en teks");

	list<string> choice;
	choice.push_back("Valg");
	choice.push_back("Et andet valg");
	choice.push_back("Enndnu et valg");
	choice.push_back("Der er flere");
	choice.push_back("Sidste valg");

	g.draw(header, main, main, choice);
	return 0;
}