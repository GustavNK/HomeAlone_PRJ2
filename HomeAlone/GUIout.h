//======================================================================== 
// FILENAME  : GUIout.h
// CREATED   : 06/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the output to the user
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20><GustavNK> The class seems to work, but needs a lot of comments and refining
// 1.1 <12.05.20><GustavNK> Addede additional comments and refined the draw() function
// 1.2 <15.05.20><GustavNK>	Names of defined pipes interfered with other lib. Renamed
// 1.3 <18.05.20><GustavNK> Added counting to the printing of choice
//========================================================================

#pragma once
#include <string>
#include <iostream>
#include <list>
#include <math.h>
#include <stdlib.h>

//Define a shortcut for the ASCII-pipes used


using namespace std;

class GUIout
{
public:
	GUIout();
	void draw(string &header, list<string> &mainLeft, list<string>& mainRight, list<string> &choice);
	void draw(string &header, list<string> &main, list<string> &choice);
private:
	//Private methods
	size_t determineLongestString(list<string>& list);
	void drawText(string, size_t length);
	void drawChoice(string, size_t length, int choiceCount);
	void drawHeader(string header, size_t lengthOfBox);
	void seperator(char l, char m, char r, size_t len);

	//Define a shortcut for the ASCII-pipes used
	const char rtPipe = '\xBB';
	const char ltPipe = '\xC9';
	const char rbPipe = '\xBC';
	const char lbPipe = '\xC8';
	const char hPipe = '\xCD';
	const char vPipe = '\xBA';
	const char lTPipe = '\xB9';
	const char rTPipe = '\xCC';
};