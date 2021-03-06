/*********************************************************************************
 *     Title:   BinaryTree.cpp                                                   *
 *     Author:  Will Westrich                                                    *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the implementation file for the BinaryTree class, which  *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
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
  Node *newNode = new Node(name, num, nullptr, nullptr);

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

/*void BinaryTree::Remove(std::string name){
    std::cout << std::endl << "You are trying to delete: " << name << std::endl;
    Delete(name);
}*/

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

void BinaryTree::Display()
{
  DisplayHorizontal(root, 1, 0);
}

//
// Private Functions
//

void BinaryTree::Copy(Node *foo)
{

  if (foo)
  {
    Insert(foo->name, foo->num);
    Copy(foo->left);
    Copy(foo->right);
  }
}

/*void BinaryTree::Delete(std::string name){
    
    Node* parent = nullptr;
    Node* current = Traverse(name, parent);

    if(current){
        if(current->left && current->right){ // 2 children case
            Node* temp = current;
            parent = current;
            current = current->left;

            while(current->right){
                parent = current;
                current = current->right;
            }
            temp->name = current->name;
            temp->num = current->num;
        }

        // 1 or 0 child case
        Node* temp = (current->left ? current->left : current->right);

        if(!parent)
            root = temp;
        else if(parent->name < current->name)
            parent->right = temp;
        else
            parent->left = temp;

        // Delete the node
        std::cout << "Successfully deleted " << current->name << std::endl;
        delete current;
    }
    else
        std::cout << std::endl << name << " doesn't exist." << std::endl;
}*/

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

    root = Balance(root);
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

BinaryTree::Node *BinaryTree::Traverse(std::string name, Node *&parent)
{
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

BinaryTree::Node *BinaryTree::Balance(Node *temp)
{
  if (temp)
  {
    int balanceFactor = HeightDiff(temp);

    if (balanceFactor > 1)
    {
      if (HeightDiff(temp->left) > 0)
        temp = ll_rotation(temp);
      else
        temp = lr_rotation(temp);
    }
    else if (balanceFactor < -1)
    {
      if (HeightDiff(temp->right) > 0)
        temp = rl_rotation(temp);
      else
        temp = rr_rotation(temp);
    }
    if (temp->left)
      temp->left = Balance(temp->left);
    if (temp->right)
      temp->right = Balance(temp->right);
  }
  return temp;
}

int BinaryTree::Height(Node *temp)
{

  int height = 0;

  if (temp)
  {
    int leftHeight = Height(temp->left);
    int rightHeight = Height(temp->right);
    height = std::max(leftHeight, rightHeight) + 1;
  }
  return height;
}

int BinaryTree::HeightDiff(Node *temp)
{

  int leftHeight = Height(temp->left);
  int rightHeight = Height(temp->right);

  return (leftHeight - rightHeight);
}

BinaryTree::Node *BinaryTree::ll_rotation(Node *parent)
{

  Node *temp = parent->left;
  parent->left = temp->right;
  temp->right = parent;

  return temp;
}

BinaryTree::Node *BinaryTree::lr_rotation(Node *parent)
{

  Node *temp = parent->left;
  parent->left = rr_rotation(temp);

  return ll_rotation(parent);
}

BinaryTree::Node *BinaryTree::rl_rotation(Node *parent)
{

  Node *temp = parent->right;
  parent->right = ll_rotation(temp);

  return rr_rotation(parent);
}

BinaryTree::Node *BinaryTree::rr_rotation(Node *parent)
{

  Node *temp = parent->right;
  parent->right = temp->left;
  temp->left = parent;

  return temp;
}

void BinaryTree::DisplayHorizontal(Node *foo, int level, bool left)
{

  if (foo)
  {
    DisplayHorizontal(foo->right, level + 1, false);

    std::cout << std::endl;

    if (foo == root)
      std::cout << std::setw(12) << std::left << "Root -> " << std::right << foo->name.at(0) << foo->name.at(1);
    else if (left)
    {
      std::cout << std::setw(10 + level * 3) << std::right << "\\  " << std::endl;
      std::cout << std::setw(10 + level * 3) << std::right << foo->name.at(0) << foo->name.at(1);
    }
    else
    {
      std::cout << std::setw(10 + level * 3) << std::right << foo->name.at(0) << foo->name.at(1) << std::endl;
      std::cout << std::setw(10 + level * 3) << std::right << "/  ";
    }

    DisplayHorizontal(foo->left, level + 1, true);
  }
}
