//======================================================================== 
// FILENAME  : GUIout.cpp
// CREATED   : 06/05/20
// AUTHOR   : Gustav 
// DESCR.   : Handles the output to the user
//  
//------------------------------------------------------------------------ 
// 
// REV. DATE/AUTHOR CHANGE DESCRIPTION 
// 1.0 <13.05.20> The class seems to work, but needs a lot of comments and refining
//========================================================================

#include "GUIout.h"

using namespace std;

GUIout::GUIout()
{
}
//============================================================= 
// METHOD : draw 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
void GUIout::draw(string& header, list<string>& mainLeft, list<string>& mainRight, list<string>& choice)
{
	size_t lengthOfText;

	//determine lengths of the main body
	size_t mainLeftLen = determineLongestString(mainLeft);
	size_t mainRightLen = determineLongestString(mainRight);
	size_t mainLen = mainLeftLen + mainRightLen + 3;

	lengthOfText = header.length();
	lengthOfText =  mainLen > lengthOfText ?  mainLen : lengthOfText;
	lengthOfText = determineLongestString(choice) > lengthOfText ? determineLongestString(choice) : lengthOfText;
	size_t lengthOfBox = lengthOfText + 2;

	seperator(lt, hPipe, rt, lengthOfBox);

	drawHeader(header, lengthOfBox);

	seperator(rT, hPipe, lT, lengthOfBox);

	//Draw main in right and left
	list<string>::iterator j = mainRight.begin();
	for (std::list<string>::iterator i = mainLeft.begin(); i != mainLeft.end(); i++)
	{
		string text = *j;
		text.append(mainRightLen - (*j).length(), ' ');
		text += " : ";
		text += *i;
		text.append(mainLeftLen - (*i).length(), ' ');
		drawText(text, lengthOfText);
		j++;
	}

	seperator(rT, hPipe, lT, lengthOfBox);

	for (list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawText(*i, lengthOfText);
	}
	seperator(lb, hPipe, rb, lengthOfBox);
}

//============================================================= 
// METHOD : draw 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
void GUIout::draw(string& header, list<string>& main, list<string>& choice)
{
	system("CLS");
	size_t lengthOfText;

	lengthOfText = header.length();
	lengthOfText = determineLongestString(main) > lengthOfText ? determineLongestString(main) : lengthOfText;
	lengthOfText = determineLongestString(choice) > lengthOfText ? determineLongestString(choice) : lengthOfText;

	size_t lengthOfBox = lengthOfText + 2;

	seperator(lt, hPipe, rt, lengthOfBox);

	drawHeader(header, lengthOfBox);

	seperator(rT, hPipe, lT, lengthOfBox);

	for (list<string>::iterator i = main.begin(); i != main.end(); i++)
	{
		drawText(*i, lengthOfText);
	}

	seperator(rT, hPipe, lT, lengthOfBox);

	for (list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawText(*i, lengthOfText);
	}
	seperator(lb, hPipe, rb, lengthOfBox);
}

//============================================================= 
// METHOD : drawText
// DESCR. : Ouputs 1 line of text with pipes and spaces on the sides
//		    with correct seperation
//============================================================= 
void GUIout::drawText(string text, size_t lengthOfText)
{
	cout << vPipe << " " 
		<< text;
	for (size_t i = 0; i <=  lengthOfText - text.length(); i++)
	{
		cout << " ";
	}
	cout << vPipe << endl;
}

//============================================================= 
// METHOD : drawHeader
// DESCR. : Outputs the header with proper spacing af pipes
//============================================================= 
void GUIout::drawHeader(string header, size_t lengthOfBox)
{
	int blankSpace = (lengthOfBox - header.length()) / 2;

	cout << vPipe;
	for (size_t i = 0; i < blankSpace; i++)
	{
		cout << " ";
	}
	if ((lengthOfBox - header.length()) % 2 != 0) cout << " ";
	cout << header;
	for (size_t i = 0; i < blankSpace; i++)
	{
		cout << " ";
	}
	cout << vPipe << endl;
}

//============================================================= 
// METHOD : seperator 
// DESCR. : Ouptut 
//============================================================= 
void GUIout::seperator(char l, char m, char r, size_t len)
{
	cout << l;
	for (size_t i = 0; i < len; i++)
	{
		cout << m;
	}
	cout << r << endl;
}

//============================================================= 
// METHOD : draw 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
size_t GUIout::determineLongestString(list<string>& list)
{
	size_t longest = 0;

	for (list<string>::iterator i = list.begin(); i != list.end(); i++)
	{
		longest = (i->length() > longest) ? i->length() : longest;
	}

	return longest;
}