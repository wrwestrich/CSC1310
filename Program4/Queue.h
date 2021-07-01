/*
 * Name: Queue.h
 * Author: Will Westrich
 * Date: 2/22/18
 * Purpose: Define a template queue ADT
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <cstddef>

template <class Type>
class Queue
{
private:
  struct Node
  {
    Type value;
    Node *next;
  };
  Node *front;
  Node *end;
  std::size_t size;

public:
  Queue() : front(nullptr), end(nullptr), size(0)
  {
  }

  /*Queue(const Queue<Type>& other){
            value = other.value;
            next = other.next;
            front = other.front;
            end = other.end;
            size = other.size;
        }

        Queue<Type>& operator=(Queue<Type> other){
            value = other.value;
            next = other.next;
            front = other.front;
            end = other.end;
            size = other.size;

            return *this;
        }*/

  ~Queue()
  {
    Node *temp;

    while (!(IsEmpty()))
    {
      temp = front->next;
      delete front;
      --size;
      front = temp;
    }
  }

  void PushBack(Type newValue)
  {
    Node *temp = new Node;
    temp->value = newValue;
    temp->next = nullptr;

    if (IsEmpty())
    {
      front = temp;
      front->next = end;
      end = temp;
    }
    else
    {
      end->next = temp;
      end = temp;
    }
    ++size;
  }

  Type PopFront()
  {
    Node *temp;
    Type poppedValue;

    if (IsEmpty())
      std::cout << "Queue is empty." << std::endl
                << std::endl;
    else
    {
      poppedValue = front->value;
      temp = front->next;
      delete front;
      front = temp;
    }
    --size;

    return poppedValue;
  }

  bool IsEmpty()
  {
    if (size == 0)
      return true;
    else
      return false;
  }

  void Display()
  {
    Node *temp = front;

    while (temp != nullptr)
    {
      if (temp->next == nullptr)
        std::cout << temp->value;
      else
        std::cout << temp->value << " ";

      temp = temp->next;
    }
  }
};
#endif
