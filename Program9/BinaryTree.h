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
#include <iomanip>
#include <string>
#include <algorithm>

class BinaryTree
{
    private:
        struct Node{
            std::string name;
            int num;
            Node* left;
            Node* right;

            Node(std::string name, int num, Node* left, Node* right){
                this->name = name;
                this->num = num;
                this->left = left;
                this->right = right;
            }
        };
        Node* root;

        void Copy(Node*);

        //void Delete(std::string);

        void RemoveSubtree(Node*);

        void Insert(Node*);

        void DisplayInOrder(Node*);

        Node* Traverse(std::string, Node*&); // DeleteNode

        void Least(Node*, int&, std::string&);

        void Most(Node*, int&, std::string&);

        void Total(Node*, int&);

        Node* Balance(Node*);

        int Height(Node*);

        int HeightDiff(Node*);

        Node* ll_rotation(Node*);

        Node* lr_rotation(Node*);

        Node* rl_rotation(Node*);

        Node* rr_rotation(Node*);

        void DisplayHorizontal(Node*, int, bool);

    public:
        BinaryTree();

        // Copy constructor
        BinaryTree(const BinaryTree&);

        // Copy assignment operator
        const BinaryTree& operator=(const BinaryTree&);

        ~BinaryTree();

        void Insert(std::string, int); // InsertNode

        int Search(std::string);

        //void Remove(std::string);

        void DisplayInOrder();

        void GetLeast(int&, std::string&);

        void GetMost(int&, std::string&);

        void GetTotal(int&);

        void Display();
};
#endif
