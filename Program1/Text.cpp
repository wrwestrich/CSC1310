/*
	Title:  Text.cpp
	Author:  Mark Boshart, modified by April Crockett
	Date:  11/7/2017
	About:  A structure version of the C++ string class
*/

#include "Text.h"

using namespace std;

Text::Text()
{
	textArray = '\0';
	//:textArray(NULL)
}

Text::Text(const char *text)
{
	//get the length of the string passed to this function
	textLength = strlen(text);

	//dynamically allocate a new character array
	//the line below wont work because I need textArray to be const but I can't dynamically allocate a const char array
	//myText->textArray = new char[(myText->textLength)+1];
	char *tempTextArray = new char[(textLength) + 1];

	/*
		Now put text inside of tempTextArray
		I can either use the cstring function called strcpy OR
		I could have created a for loop and copy one character at a time.
	*/
	strcpy(tempTextArray, text);

	//put the text sent to this function into the newly created array
	//I can do assignment because it is assigning a pointer (not a cstring)
	textArray = tempTextArray;
}

Text::~Text()
{
	if (textArray != nullptr)
		delete[] textArray;
}

void Text::displayText()
{
	//print out the c-string
	cout << textArray;
}

const char *Text::getText()
{
	return textArray;
}

int Text::getLength()
{
	return textLength;
}

void Text::editText(const char *text)
{

	delete[] textArray;

	textLength = strlen(text);

	char *tempText = new char[textLength + 1];

	strcpy(tempText, text);

	textArray = text;
}
