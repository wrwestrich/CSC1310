#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int *, int, int);
void stringReverser(string, size_t);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;

	do
	{

		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while (choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			cout << "\n\nSUM OF NUMBERS\n";
			cout << "Enter an integer:  ";
			cin >> num;
			//print out the result of the sumOfNumbers function here
			cout << endl
					 << "The result is: " << sumOfNumbers(num) << endl;
			break;

		case 2:
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				myArray[x] = (rand() % 100) + 1;
			}
			cout << "\n\nISMEMBER ARRAY FUNCTION\n";
			cout << "Enter an integer:  ";
			cin >> num;
			cout << "\nHere are the array values:  ";
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				cout << myArray[x] << " ";
			}
			//print if the value that the user entered is in the array or not here
			if (isMember(myArray, ARRAY_SIZE, num))
				cout << endl
						 << endl
						 << num << " is in the array." << endl;
			else
				cout << endl
						 << endl
						 << num << " is not in the array." << endl;

			break;

		case 3:
			cout << "\n\nSTRING REVERSER\n";
			cout << "Enter a string and I will reverse it:  ";
			cin.ignore();
			getline(cin, userString);
			//call string reverser function here
			stringReverser(userString, userString.size());
			break;

		case 4:
			cout << "\n\nPALINDROME DETECTOR\n";
			cout << "Enter a string and I will tell you if it is a palindrome:  ";
			cin.ignore();
			getline(cin, userString);

			//change string to be all uppercase
			for (int x = 0; x < userString.length(); x++)
			{
				userString[x] = toupper(userString[x]);
			}

			//remove spaces from string
			userStrWithoutSpaces = userString;
			for (int x = 0; x < userStrWithoutSpaces.size(); x++)
			{
				if (userStrWithoutSpaces[x] == ' ')
					userStrWithoutSpaces.erase(x, 1);
			}

			//print out whether the user's string is a palindrome or not here.
			//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
			if (isPalindrome(userStrWithoutSpaces))
				cout << endl
						 << userString << " is a palindrome." << endl;
			else
				cout << endl
						 << userString << " is not a palindrome." << endl;

			break;

		case 5:
			cout << "\n\nRECURSIVE MULTIPLICATION\n";
			cout << "Enter in the first integer:  ";
			cin >> num1;
			cout << "\nEnter in the second integer:  ";
			cin >> num2;
			//print out the value returned from the multiply function here
			cout << endl
					 << num1 << " x " << num2 << " = " << multiply(num1, num2) << endl;
			break;
		}
	} while (choice != 6);

	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

//implement the five recursive functions below!!!!
int sumOfNumbers(int n)
{

	if (n == 0)
		return 0;
	else
		return n + sumOfNumbers(--n);
}

bool isMember(int *array, int size, int value)
{

	if (size == 0)
		return false;
	else if (array[--size] == value)
		return true;
	else
		return isMember(array, size, value);
}

void stringReverser(string str, size_t size)
{

	if (size == 0)
		return;
	else
	{
		cout << str.at(--size);
		stringReverser(str, size);
	}
}

bool isPalindrome(string pal)
{

	if (pal.size() <= 1)
		return true;
	else if (pal.front() == pal.back())
	{
		pal = pal.substr(1, (pal.size() - 2));
		return isPalindrome(pal);
	}
	else
		return false;
}

int multiply(int num1, int num2)
{

	if (num2 == 0)
		return 0;
	else
		return multiply(num1, --num2) + num1;
}
