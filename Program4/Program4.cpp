/*
 * Name: Program4.cpp
 * Author: Will Westrich
 * Date: 2/22/18
 * Purpose: Convert infix expressions to postfix expressions and evaluate them
*/

#include "Stack.h"
#include "Queue.h"
#include <string>
#include <limits>
#include <stdlib.h>

using namespace std;

double CalculateExpression(string);
bool IsLowerPriority(char, char);
string InsertSpaces(string, size_t);

int main()
{
  string input;
  char end;

  cout << endl
       << endl
       << "Infix to Postfix Converter";

  do
  {
    cout << endl
         << endl;
    cout << "Enter Infix Expression: ";
    getline(cin, input);
    cout << endl
         << endl
         << endl;

    while (input.find(" ") != string::npos)
    {
      input.erase(input.find(" "), 1);
    }

    cout << "Infix Expression: " << InsertSpaces(input, input.length()) << endl;

    Stack<char> *opStack = new Stack<char>;
    Queue<char> *postfix = new Queue<char>;
    while (!(input.empty()))
    {
      if (input.at(0) == '(')
        opStack->Push(input.at(0));
      else if (input.at(0) == ')')
      {
        while (opStack->Peek() != '(')
        {
          postfix->PushBack(opStack->Pop());
        }
        end = opStack->Pop();
      }
      else if (input.at(0) == '+' || input.at(0) == '-' || input.at(0) == '*' || input.at(0) == '/')
      {
        while (!(opStack->IsEmpty()) && IsLowerPriority(input.at(0), opStack->Peek()))
        {
          postfix->PushBack(opStack->Pop());
        }
        opStack->Push(input.at(0));
      }
      else
        postfix->PushBack(input.at(0));

      input.erase(input.begin());
    }
    while (!(opStack->IsEmpty()))
    {
      postfix->PushBack(opStack->Pop());
    }

    cout << "Postfix Expression: ";
    postfix->Display();
    cout << endl;

    while (!(postfix->IsEmpty()))
    {
      input.push_back(postfix->PopFront());
    }

    cout << "Result of the Expression: " << CalculateExpression(input) << endl
         << endl;

    delete opStack;
    delete postfix;

    cout << "Would you like to run the program again? (Y/N) ";
    do
    {
      while (!(cin >> end))
      {
        cout << endl
             << "Please enter Y or N: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
      }
      if (toupper(end) != 'Y' && toupper(end) != 'N')
        cout << endl
             << "Please enter Y or N: ";
      cin.ignore();
    } while (toupper(end) != 'Y' && toupper(end) != 'N');

  } while (toupper(end) == 'Y');

  return 0;
}

double CalculateExpression(string ex)
{
  double temp1, temp2;
  string tempStr;
  Stack<double> *value = new Stack<double>;

  for (size_t i = 0; i < ex.size(); ++i)
  {
    if (ex.at(i) >= 48)
    {
      tempStr = ex.at(i);
      value->Push(atof(tempStr.c_str()));
    }
    else
    {
      temp1 = value->Pop();
      temp2 = value->Pop();

      if (ex.at(i) == '+')
      {
        value->Push(temp1 + temp2);
      }
      else if (ex.at(i) == '/')
      {
        value->Push(temp2 / temp1);
      }
      else if (ex.at(i) == '*')
      {
        value->Push(temp1 * temp2);
      }
      else
      {
        value->Push(temp2 - temp1);
      }
    }
  }
  temp1 = value->Peek();

  delete value;

  return temp1;
}

bool IsLowerPriority(char one, char two)
{

  if (one == '(')
    return true;
  else if ((one == '+' || one == '-') && (two != '(' || two == '+' || two == '-'))
    return true;
  else if ((one == '*' || one == '/') && (two == ')' || two == '*' || two == '/'))
    return true;
  else
    return false;
}

// Made this function to make things easier
string InsertSpaces(string temp, size_t size)
{
  for (size_t i = 1; i < size; i += 2)
  {
    temp.insert(i, " ");
    ++size;
  }

  return temp;
}
