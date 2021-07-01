/*
 * Name: Stack.h
 * Author: Will Westrich
 * Date: 2/22/18
 * Purpose: Define a template stack ADT
*/

#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class Type>
class Stack
{
private:
  struct Node
  {
    Type value;
    Node *next;
  };
  Node *top;

public:
  Stack() : top(nullptr)
  {
  }
  /*
        Stack(const Stack<Type>& other){
            value = other.value;
            next = other.next;
            top = other.top;
        }

        Stack<Type>& operator=(Stack<Type> other){
            value = other.value;
            next = other.next;
            top = other.top;

            return *this;
        }*/

  ~Stack()
  {
    Node *temp;

    while (!(IsEmpty()))
    {
      temp = top->next;
      delete top;
      top = temp;
    }
  }

  void Push(Type newValue)
  {
    Node *temp = new Node;
    temp->value = newValue;

    if (IsEmpty())
    {
      top = temp;
      temp->next = nullptr;
    }
    else
    {
      temp->next = top;
      top = temp;
    }
  }

  Type Pop()
  {
    Node *temp;
    Type poppedValue;

    if (IsEmpty())
      std::cout << "Stack is empty." << std::endl
                << std::endl;
    else
    {
      poppedValue = top->value;
      temp = top->next;
      delete top;
      top = temp;
    }

    return poppedValue;
  }

  Type Peek()
  {
    return top->value;
  }

  bool IsEmpty()
  {
    if (top == nullptr)
      return true;
    else
      return false;
  }
};
#endif
