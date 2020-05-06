#include "GUIout.h"

GUIout::GUIout()
{
}

void GUIout::draw(string& header, list<string>& mainLeft, list<string>& mainRight, list<string>& choice)
{
	size_t lengthOfText;

	lengthOfText = header.length();
	//lengthOfText = determineLongestString(main) > lengthOfText ? determineLongestString(main) : lengthOfText;
	lengthOfText = determineLongestString(choice) > lengthOfText ? determineLongestString(choice) : lengthOfText;

	size_t lengthOfBox = lengthOfText + 2;

	seperator(lt, hPipe, rt, lengthOfBox);

	drawHeader(header, lengthOfBox);

	seperator(rT, hPipe, lT, lengthOfBox);

	//TODO Implement new main, that can be seperatet into 2 columns
	//":" sepertor must alwauys be equal length away 

	seperator(rT, hPipe, lT, lengthOfBox);

	for (std::list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawText(*i, lengthOfText);
	}
	seperator(lb, hPipe, rb, lengthOfBox);
}

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

	for (std::list<string>::iterator i = main.begin(); i != main.end(); i++)
	{
		drawText(*i, lengthOfText);
	}

	seperator(rT, hPipe, lT, lengthOfBox);

	for (std::list<string>::iterator i = choice.begin(); i != choice.end(); i++)
	{
		drawText(*i, lengthOfText);
	}
	seperator(lb, hPipe, rb, lengthOfBox);
}


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

void GUIout::drawHeader(string header, size_t lengthOfBox)
{
	int blankSpace = floor((lengthOfBox - header.length()) / 2);

	cout << vPipe;
	for (size_t i = 0; i < blankSpace; i++)
	{
		cout << " ";
	}
	if (lengthOfBox % 2 != 0) cout << " ";
	cout << header;
	for (size_t i = 0; i < blankSpace; i++)
	{
		cout << " ";
	}
	cout << vPipe << endl;
}

void GUIout::seperator(char l, char m, char r, size_t len)
{
	cout << l;
	for (size_t i = 0; i < len; i++)
	{
		cout << m;
	}
	cout << r << endl;
}

size_t GUIout::determineLongestString(list<string>& list)
{
	size_t longest = 0;

	for (std::list<string>::iterator i = list.begin(); i != list.end(); i++)
	{
		longest = (i->length() > longest) ? i->length() : longest;
	}

	return longest;
}