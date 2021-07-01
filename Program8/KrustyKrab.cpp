/*********************************************************************************
 *     Title:   KrustyKrab.cpp                                                   *
 *     Author:  April Crockett, modified by PUT_YOUR_NAME_HERE                   *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is a program for Mr. Krabs at the Krusty Krab in beautiful  *
 *              Bikini Bottom!  The program allows you to choose from a menu     *
 *              of options:  enter customer data, remove customer data, print    *
 *              statistics, and search for a customer's data.  This data in this *
 *              program is stored in a Binary Search Tree.                       *
 *********************************************************************************/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	int choice;
	string name;
	int numKrabbyPatties, total = 0;

	BinaryTree tree;

	cout << "\n\n_  _   ____   _  _    ___   _____  _  _     _  _   ____     _    ___  \n";
	cout << ") |) / /  _ \\ ) () (  (  _( )__ __() () (   ) |) / /  _ \\   )_\\  \\  _)\n";
	cout << "| ( (  )  ' / | \\/ |  _) \\    | |  '.  /    | ( (  )  ' /  /( )\\ |  ( \n";
	cout << ")_|)_\\ |_()_\\ )____( )____)   )_(   /_(     )_|)_\\ |_()_\\ )_/ \\_(/__o)\n\n";

	do
	{
		cout << "Welcome to the Krusty Krab!\n";
		cout << "Choose one of the following options:\n";
		cout << "1.  Enter customer data.\n";
		cout << "2.  Remove a customer's data.\n";
		cout << "3.  Get statistics on Krabby Patties.\n";
		cout << "4.  Search for a customer's data.\n";
		cout << "5.  End Program.\n";
		cout << "ENTER 1-5:  ";
		cin >> choice;

		while (choice < 1 || choice > 5)
		{
			cout << "Invalid choice.  Please enter 1-5:  ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1: //insert customer's data
			do
			{
				cout << "Enter a customer's name or -1 to quit entering data.\n";
				cout << "NAME:  ";
				cin.ignore();
				getline(cin, name);

				if (name != "-1")
				{
					cout << "NUMBER KRABBY PATTIES EATEN:  ";
					cin >> numKrabbyPatties;
					//LOOK!!  Call the insertNode BinaryTree member function here
					tree.Insert(name, numKrabbyPatties);
				}
			} while (name != "-1");
			cout << endl;
			break;

		case 2: //remove customer's data
			cout << "\n\nYou may remove the following customers:\n";
			//LOOK!!  Call the displayInOrder BinaryTree member function here
			tree.DisplayInOrder();
			cout << "\n\nEnter the name of the customer you wish to remove.\n";
			cout << "NAME:  ";
			cin.ignore();
			getline(cin, name);
			cout << endl;
			tree.Remove(name);
			cout << endl;
			break;

		case 3: //statistics

			//LOOK!!  Call the getLeastNumPatties BinaryTree member function here
			tree.GetLeast(numKrabbyPatties, name);
			cout << "\n\nLEAST NUMBER OF KRABBY PATTIES EATEN:  " << name << ", " << numKrabbyPatties << " Krabby Patties\n";

			//LOOK!!  Call the getMostNumPatties BinaryTree member function here
			tree.GetMost(numKrabbyPatties, name);
			cout << "LARGEST NUMBER OF KRABBY PATTIES EATEN:  " << name << ", " << numKrabbyPatties << " Krabby Patties\n";

			//LOOK!!  Call the getTotalNumPatties BinaryTree member function here
			tree.GetTotal(total);
			cout << "TOTAL NUMBER OF KRABBY PATTIES EATEN:  " << total << endl
					 << endl;
			break;

		case 4: //search
			cout << "\n\nWhich customer are you looking for?\n";
			//LOOK!!  Call the displayInOrder BinaryTree member function here
			tree.DisplayInOrder();

			cout << "Enter the name of the customer.\n";
			cout << "NAME:  ";
			cin.ignore();
			getline(cin, name);

			//LOOK!!  Call the searchNode BinaryTree member function here
			numKrabbyPatties = tree.Search(name);

			if (numKrabbyPatties != -1)
				cout << "\n"
						 << name << " ate " << numKrabbyPatties << " Krabby Patties\n\n";
			else
				cout << "\n"
						 << name << " is not a customer of the Krusty Krab.\n";
			break;

		case 5: //end
			cout << "\n\nGoodbye!\n\n";
		}
	} while (choice != 5);

	return 0;
}
