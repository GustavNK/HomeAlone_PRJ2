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
// 1.1 <12.05.20><GustavNK> Addede additional comments and refined the draw() function
// 1.2 <15.05.20><GustavNK>	Names of defined pipes interfered with other lib. Renamed
// 1.3 <18.05.20><GustavNK> Added counting to the printing of choice
//------------------------------------------------------------------------ 
// TODO
// Implement a line shift for the draw(string, list<string>, list<string>)
//   to ensure the lines wont b to long
//========================================================================
#include "GUIout.h"

//Empty constructor
GUIout::GUIout()
{
}
//============================================================= 
// METHOD : draw 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
void GUIout::draw(string& header, list<string>& mainLeft, list<string>& mainRight, list<string>& choice) const
{
	system("CLS");
	size_t lengthOfText;

	//determine lengths of the main body
	size_t mainLeftLen = determineLongestString(mainLeft);
	size_t mainRightLen = determineLongestString(mainRight);
	size_t mainLen = mainLeftLen + mainRightLen + 3;

	lengthOfText = header.length();
	lengthOfText =  mainLen > lengthOfText ?  mainLen : lengthOfText;
	lengthOfText = determineLongestString(choice) > lengthOfText ? determineLongestString(choice) : lengthOfText;
	size_t lengthOfBox = lengthOfText + 2;

	seperator(ltPipe, hPipe, rtPipe, lengthOfBox);

	drawHeader(header, lengthOfBox);

	seperator(rTPipe, hPipe, lTPipe, lengthOfBox);

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

	seperator(rTPipe, hPipe, lTPipe, lengthOfBox);

	int choiceCount = 1;

	for (list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawChoice(*i, lengthOfText, choiceCount);
		choiceCount++;
	}
	seperator(lbPipe, hPipe, rbPipe, lengthOfBox);

	cout << endl << endl << "Indtast Kommando: ";
}

//============================================================= 
// METHOD : draw 
// DESCR. : Takes the header, main body and choices, 
//          and outputs the on the screen
//============================================================= 
void GUIout::draw(string& header, list<string>& main, list<string>& choice) const
{
	system("CLS");
	size_t lengthOfText;

	lengthOfText = header.length();
	lengthOfText = determineLongestString(main) > lengthOfText ? determineLongestString(main) : lengthOfText;
	lengthOfText = determineLongestString(choice) + 3 > lengthOfText ? determineLongestString(choice) + 3: lengthOfText;

	size_t lengthOfBox = lengthOfText + 2;

	seperator(ltPipe, hPipe, rtPipe, lengthOfBox);

	drawHeader(header, lengthOfBox);

	seperator(rTPipe, hPipe, lTPipe, lengthOfBox);

	for (list<string>::iterator i = main.begin(); i != main.end(); i++)
	{
		drawText(*i, lengthOfText);
	}

	seperator(rTPipe, hPipe, lTPipe, lengthOfBox);
	
	int choiceCount = 1;

	for (list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawChoice(*i, lengthOfText, choiceCount);
		choiceCount++;
	}
	seperator(lbPipe, hPipe, rbPipe, lengthOfBox);

	cout << endl << endl << "Indtast Kommando: ";
}

//============================================================= 
// METHOD : drawText
// DESCR. : Ouputs 1 line of text with pipes and spaces on the sides
//		    with correct seperation
//============================================================= 
void GUIout::drawText(string text, size_t lengthOfText) const
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
// METHOD : drawChoice
// DESCR. : Ouputs 1 line of text with pipes and spaces on the sides
//		    with correct seperation. Adds the choice number first
//============================================================= 
void GUIout::drawChoice(string text, size_t lengthOfText, int choiceCount) const
{
	lengthOfText -= 3;

	cout << vPipe << " " << choiceCount << ") "<< text;

	for (size_t i = 0; i <= lengthOfText - text.length(); i++)
	{
		cout << " ";
	}
		cout << vPipe << endl;
}

//============================================================= 
// METHOD : drawHeader
// DESCR. : Outputs the header with proper spacing af pipes
//============================================================= 
void GUIout::drawHeader(string header, size_t lengthOfBox) const
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
// DESCR. : Ouptut the seperator between lines 
//============================================================= 
void GUIout::seperator(char l, char m, char r, size_t len) const
{
	cout << l;
	for (size_t i = 0; i < len; i++)
	{
		cout << m;
	}
	cout << r << endl;
}

//============================================================= 
// METHOD : :determineLongestString 
// DESCR. : Takes a list of strings, and determines, which string is
//     the longest, and returns the length of the longest string
//============================================================= 
size_t GUIout::determineLongestString(list<string>& list) const
{
	size_t longest = 0;

	for (std::list<string>::iterator i = list.begin(); i != list.end(); i++)
	{
		longest = (i->length() > longest) ? i->length() : longest;
	}

	return longest;
}