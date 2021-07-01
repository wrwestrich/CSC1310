/*
 * Name: Zoo.cpp
 * Date: 2/15/18
 * Author: Will Westrich
 * Purpose:
*/

#include <limits>
#include <iostream>
#include "LinkedList.h"
#include "Creature.h"
using namespace std;

void EnterCreature(list<Creature> *);
void EnterCreatureFromFile(list<Creature> *);
void DeleteCreature(list<Creature> *);
void PrintCreature(list<Creature> *);
void SaveToFile(list<Creature> *);

int main()
{
  short input;
  char inputC;
  list<Creature> *List = new list<Creature>;

  do
  {
    cout << endl
         << endl
         << "What would you like to do?" << endl;
    cout << "\t1 - Enter Creature" << endl;
    cout << "\t2 - Delete a Creature" << endl;
    cout << "\t3 - Print Creatures" << endl;
    cout << "\t4 - Quit" << endl;
    cout << "Enter 1-4: ";
    do
    {
      while (!(cin >> input))
      {
        cout << endl
             << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
      }
      if (input < 1 || input > 4)
        cout << endl
             << "Please enter a valid number: ";
    } while (input < 1 || input > 4);
    cin.ignore();

    switch (input)
    {
    case 1:
      cout << endl
           << endl
           << "Choose how you would like to enter the data:" << endl;
      cout << "\t1 - Manually" << endl;
      cout << "\t2 - From a File" << endl;
      cout << "Enter 1-2: ";
      do
      {
        while (!(cin >> input))
        {
          cout << endl
               << "Please enter a valid number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max());
        }
        if (input < 1 || input > 2)
          cout << endl
               << "Please enter a valid number: ";
      } while (input < 1 || input > 2);
      cin.ignore();

      switch (input)
      {
      case 1:
        EnterCreature(List);
        break;

      case 2:
        EnterCreatureFromFile(List);
        break;
      }
      break;

    case 2:
      DeleteCreature(List);
      break;

    case 3:
      PrintCreature(List);
      break;

    case 4:
      cout << "Would you like to save your creatures?" << endl;
      cout << "(Y/N): ";
      cin >> inputC;
      cin.ignore();

      if (inputC == 'y' || inputC == 'Y')
        SaveToFile(List);
      break;
    }
  } while (input != 4);
}

void EnterCreature(list<Creature> *List)
{
  string tempName, tempDes, temp;
  float tempCost;
  bool tempDan;

  do
  {
    cout << endl
         << "Enter the creature's name: ";
    getline(cin, tempName);

    cout << endl
         << "Enter a description:" << endl;
    getline(cin, tempDes);

    cout << endl
         << "Is the creature dangerous(y or n)? ";
    getline(cin, temp);

    cout << endl
         << "Enter cost per month: ";
    cin >> tempCost;
    cin.ignore();

    if (temp == "y" || temp == "Y")
      tempDan = true;
    else
      tempDan = false;

    Creature *newThing = new Creature(tempName, tempDes, tempDan, tempCost);

    List->AppendNode(newThing);

    cout << endl
         << tempName << " has been added." << endl
         << endl;
    cout << "Would you like to add another creature? ";
    cin >> temp;
    cin.ignore();
    if (temp == "y" || temp == "Y")
      tempDan = true;
    else
      tempDan = false;
  } while (tempDan);
}

void EnterCreatureFromFile(list<Creature> *List)
{
  ifstream inF;
  string temp, tempName, tempDes;
  float tempCost;
  bool tempDan;
  size_t numAdded = 0;

  cout << endl
       << "Enter the name of the file(example.txt): ";
  getline(cin, temp);

  inF.open(temp, std::fstream::in);
  if (!inF.is_open())
  {
    cout << endl
         << "File could not be found." << endl
         << endl;
    return;
  }
  while (getline(inF, temp))
  {
    tempName = temp;
    getline(inF, temp);
    tempDes = temp;
    inF >> tempDan;
    inF >> tempCost;

    Creature *newThing = new Creature(tempName, tempDes, tempDan, tempCost);
    List->AppendNode(newThing);
    ++numAdded;
    getline(inF, temp);
  }
  inF.close();

  cout << endl
       << numAdded << " creatures were added from the file." << endl;
}

void DeleteCreature(list<Creature> *List)
{
  size_t remove;
  Creature temp;

  for (size_t i = 0; i < List->GetLength(); ++i)
  {
    temp = List->GetValue(i);
    cout << "Creature " << i + 1 << ": " << temp.GetName() << endl;
  }

  cout << endl
       << "choose the creature you'd like to remove:" << endl;
  cin >> remove;

  List->DeleteNode(remove - 1);

  cout << endl
       << "The creature has been removed" << endl
       << endl;
}

void PrintCreature(list<Creature> *List)
{
  Creature temp;
  size_t size = List->GetLength();

  if (size == 0)
  {
    cout << endl
         << "There are no creatures in the zoo." << endl;
    return;
  }
  cout << endl;
  for (size_t i = 0; i < List->GetLength(); ++i)
  {
    temp = List->GetValue(i);
    temp.Print();
    cout << endl;
  }
}

void SaveToFile(list<Creature> *List)
{
  Creature temp;
  string name;
  size_t size = List->GetLength();

  if (size == 0)
  {
    cout << endl
         << "There are no creatures in the zoo." << endl;
    return;
  }

  cout << endl
       << "Enter the name of the file you'd like to save to(example.txt):" << endl;
  getline(cin, name);

  for (size_t i = 0; i < List->GetLength(); ++i)
  {
    temp = List->GetValue(i);
    temp.PrintToFile(name);
  }
}
