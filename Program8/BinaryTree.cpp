/*********************************************************************************
 *     Title:   BinaryTree.cpp                                                   *
 *     Author:  Will Westrich                                                    *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the implementation file for the BinaryTree class, which  *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#include <iostream>
#include "BinaryTree.h"

// Public Functions

BinaryTree::BinaryTree() : root(nullptr)
{
}

BinaryTree::BinaryTree(const BinaryTree &other)
{
  root = nullptr;
  Copy(other.root);
}

const BinaryTree &BinaryTree::operator=(const BinaryTree &other)
{

  if (this != &other)
  {
    RemoveSubtree(root);
    root = nullptr;
    Copy(other.root);
  }
  return *this;
}

BinaryTree::~BinaryTree()
{
  RemoveSubtree(root);
}

void BinaryTree::Insert(std::string name, int num)
{
  Node *newNode = new Node;
  newNode->name = name;
  newNode->num = num;
  newNode->left = newNode->right = nullptr;

  Insert(newNode);
}

int BinaryTree::Search(std::string name)
{
  Node *parent = nullptr;
  Node *current = Traverse(name, parent);
  if (current)
    return current->num;
  else
    return -1;
}

void BinaryTree::Remove(std::string name)
{
  std::cout << std::endl
            << "You are trying to delete: " << name << std::endl;
  Delete(name);
}

void BinaryTree::DisplayInOrder()
{
  DisplayInOrder(root);
}

void BinaryTree::GetLeast(int &min, std::string &minName)
{
  min = root->num;
  minName = root->name;
  Least(root, min, minName);
}

void BinaryTree::GetMost(int &max, std::string &maxName)
{
  max = root->num;
  maxName = root->name;
  Most(root, max, maxName);
}

void BinaryTree::GetTotal(int &total)
{
  total = 0;
  Total(root, total);
}

// Private Functions

void BinaryTree::Copy(Node *foo)
{

  if (foo)
  {
    Insert(foo->name, foo->num);
    Copy(foo->left);
    Copy(foo->right);
  }
}

void BinaryTree::Delete(std::string name)
{

  Node *parent = nullptr;
  Node *current = Traverse(name, parent);

  if (current)
  {
    if (current->left && current->right)
    { // 2 children case
      Node *temp = current;
      parent = current;
      current = current->left;

      while (current->right)
      {
        parent = current;
        current = current->right;
      }
      temp->name = current->name;
      temp->num = current->num;
    }

    // 1 or 0 child case
    Node *temp = (current->left ? current->left : current->right);

    if (!parent)
      root = temp;
    else if (parent->name < current->name)
      parent->right = temp;
    else
      parent->left = temp;

    // Delete the node
    std::cout << "Successfully deleted " << current->name << std::endl;
    delete current;
  }
  else
    std::cout << std::endl
              << name << " doesn't exist." << std::endl;
}

void BinaryTree::RemoveSubtree(Node *foo)
{

  if (foo)
  {
    RemoveSubtree(foo->left);
    RemoveSubtree(foo->right);
    delete foo;
  }
}

void BinaryTree::Insert(Node *newNode)
{
  Node *parent = nullptr;
  Node *current = Traverse(newNode->name, parent);

  if (!current)
  {
    if (!parent)
      root = newNode;
    else if (newNode->name < parent->name)
      parent->left = newNode;
    else
      parent->right = newNode;
  }
  else
  {
    std::cout << std::endl
              << newNode->name << " already exists." << std::endl;
    delete newNode;
  }
}

void BinaryTree::DisplayInOrder(Node *foo)
{

  if (foo)
  {
    DisplayInOrder(foo->left);
    std::cout << foo->name << std::endl;
    DisplayInOrder(foo->right);
  }
}
/*
Node* BinaryTree::Traverse(std::string name, Node*& parent){
    Node* current = root;
    parent = nullptr;

    while(current && current->name != name){
        parent = current;

        if(name < current->name)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}*/

void BinaryTree::Least(Node *temp, int &min, std::string &minName)
{

  if (temp)
  {
    Least(temp->left, min, minName);
    if (temp->num < min)
    {
      min = temp->num;
      minName = temp->name;
    }
    Least(temp->right, min, minName);
  }
}

void BinaryTree::Most(Node *temp, int &max, std::string &maxName)
{

  if (temp)
  {
    Most(temp->left, max, maxName);
    if (temp->num > max)
    {
      max = temp->num;
      maxName = temp->name;
    }
    Most(temp->right, max, maxName);
  }
}

void BinaryTree::Total(Node *temp, int &total)
{

  if (temp)
  {
    Total(temp->left, total);
    total += temp->num;
    Total(temp->right, total);
  }
}
