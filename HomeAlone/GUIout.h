//======================================================================== 
// FILENAME  : GUIout.h
// CREATED   : 06/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the output to the user
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20> The class seems to work, but needs a lot of comments and refining
// 1.1 <12.05.20> Addede additional comments and refined the drwa() function
//========================================================================

#pragma once
#include <string>
#include <iostream>
#include <list>
#include <math.h>
#include <stdlib.h>

//Define a shortcut for the pipes-ASCII used
#define rt '\xBB'
#define lt '\xC9'
#define rb '\xBC'
#define lb '\xC8'
#define hPipe '\xCD'
#define vPipe '\xBA'
#define lT '\xB9'
#define rT '\xCC'

using namespace std;

class GUIout
{
public:
	GUIout();
	void draw(string &header, list<string> &mainLeft, list<string>& mainRight, list<string> &choice);
	void draw(string &header, list<string> &main, list<string> &choice);
private:
	size_t determineLongestString(list<string>& list);
	void drawText(string, size_t length);
	void drawHeader(string header, size_t lengthOfBox);
	void seperator(char l, char m, char r, size_t len);
};