/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Will Westrich                                                    *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class BinaryTree
{
private:
  struct Node
  {
    std::string name;
    int num;
    Node *left;
    Node *right;
  };
  Node *root;

  void Copy(Node *);

  void Delete(std::string);

  void RemoveSubtree(Node *);

  void Insert(Node *);

  void DisplayInOrder(Node *);

  Node *Traverse(std::string name, Node *&parent)
  { // DeleteNode
    Node *current = root;
    parent = nullptr;

    while (current && current->name != name)
    {
      parent = current;

      if (name < current->name)
        current = current->left;
      else
        current = current->right;
    }
    return current;
  }

  void Least(Node *, int &, std::string &);

  void Most(Node *, int &, std::string &);

  void Total(Node *, int &);

public:
  BinaryTree();

  // Copy constructor
  BinaryTree(const BinaryTree &);

  // Copy assignment operator
  const BinaryTree &operator=(const BinaryTree &);

  ~BinaryTree();

  void Insert(std::string, int); // InsertNode

  int Search(std::string);

  void Remove(std::string);

  void DisplayInOrder();

  void GetLeast(int &, std::string &);

  void GetMost(int &, std::string &);

  void GetTotal(int &);
};
#endif
