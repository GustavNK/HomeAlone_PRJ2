#include "GUIout.h"

GUIout::GUIout()
{
}

void GUIout::draw(string& header, list<string>& mainLeft, list<string>& mainRight, list<string>& choice)
{
	int length = 2;
	cout << lt;
	for (size_t i = 0; i < length; i++)
	{
		cout << vPipe;
	}
	cout << rt;
}

void GUIout::draw(string& header, list<string>& main, list<string>& choice)
{
	size_t lengthOfText;

	lengthOfText = header.length();
	lengthOfText = determineLongestString(main) > lengthOfText ? determineLongestString(main) : lengthOfText;
	lengthOfText = determineLongestString(choice) > lengthOfText ? determineLongestString(choice) : lengthOfText;

	size_t lengthOfBox = lengthOfText + 2;

	cout << lt;
	for (size_t i = 0; i < lengthOfBox; i++)
	{
		cout << vPipe;
	}
	cout << rt << endl;

	drawHeader("as", lengthOfBox);

	for (std::list<string>::iterator i = main.begin(); i != main.end(); i++)
	{
		drawText(*i, lengthOfText);
	}

	cout << lb;
	for (size_t i = 0; i < lengthOfBox; i++)
	{
		cout << vPipe;
	}
	cout << rb << endl;
}

void GUIout::draw(list<string>& test)
{
	size_t lengthOfText = determineLongestString(test);
	size_t lengthOfBox = lengthOfText + 2;
	cout << lt;
	for (size_t i = 0; i < lengthOfBox; i++)
	{
		cout << vPipe;
	}
	cout << rt << endl;

	drawHeader("as", lengthOfBox);

	for (std::list<string>::iterator i = test.begin(); i != test.end(); i++)
	{
		drawText(*i, lengthOfText);
	}

	seperator(lb, hPipe, rb, lengthOfBox);
	/*cout << lb;
	for (size_t i = 0; i < lengthOfBox; i++)
	{
		cout << vPipe;
	}
	cout << rb << endl;*/
}

void GUIout::drawText(string text, size_t lengthOfText)
{
	cout << hPipe << " " << text;
	for (size_t i = 0; i <=  lengthOfText - text.length(); i++)
	{
		cout << " ";
	}
	cout << "" << hPipe << endl;

}

void GUIout::drawHeader(string header, size_t lengthOfBox)
{
	int blankSpace = floor((lengthOfBox - header.length()) / 2);

	cout << hPipe;
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
	cout << hPipe << endl;
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