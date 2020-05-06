#pragma once
#include <string>
#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class GUIout
{
public:
	GUIout();
	void draw(string &header, list<string> &mainLeft, list<string>& mainRight, list<string> &choice);
	void draw(string &header, list<string> &main, list<string> &choice);
	void draw(list<string> &test);
private:
	size_t determineLongestString(list<string>& list);
	void drawText(string, size_t length);
	void drawHeader(string header, size_t lengthOfBox);
	void seperator(char l, char m, char r, size_t len);
	char rt = '\xBB';
	char lt = '\xC9';
	char rb = '\xBC';
	char lb = '\xC8';
	char hPipe = '\xCD';
	char vPipe = '\xBA';
	char lT = '\xB9';
	char rT = '\xCC';
};