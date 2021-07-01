/*
 * Name: LinkedList.h
 * Date: 2/15/18
 * Author: Will Westrich
 * Purpose:
*/

#ifndef LIST_H
#define LIST_H

template <class Type>
class list
{
private:
  struct Node
  {
    Type value;
    Node *next;
  };
  Node *head;
  Node *tail;
  std::size_t size;

public:
  list()
      : head(nullptr), tail(nullptr), size(0)
  {
  }

  /*list(const list& other){

        }

        list& operator=(list other){

        }*/

  ~list()
  {
    Node *temp = head;

    while (temp != nullptr)
    {
      Node *next = temp->next;
      delete temp;
      temp = next;
    }
  }

  std::size_t GetLength()
  {
    return size;
  }

  Type GetValue(std::size_t i)
  {

    Node *temp = head;
    for (std::size_t j = 0; j < i; ++j)
      temp = temp->next;

    return temp->value;
  }

  void AppendNode(Type *newValue)
  {
    Node *newNode = new Node;

    newNode->value = *newValue;
    newNode->next = nullptr;

    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    ++size;
  }

  void DeleteNode(std::size_t i)
  {
    Node *temp = head;

    for (std::size_t j = 0; j < i - 1; ++j)
      temp = temp->next;

    if (i == 0)
      head = temp->next;

    if (temp->next->next == nullptr)
      tail = temp->next;

    temp->next = temp->next->next;
    temp = temp->next;
    delete temp;

    --size;
  }
};

#endif
