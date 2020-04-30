/**
 * Names: Jamie Joung & Taryn Hovenkamp
 * Contributions:
 *  - Livecoded (utilized Live Share via VS Code with audio call)
 *  - Each function was created with joint efforts, therefore, we understand all of our coding and not just bits and pieces of it.
 *  - Additionally, each function was commented by both partners and thoroughly discussed 
 * */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>


using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

class BST
{
    private:
        Node* root;
        Node* createNode(int data);
        Node* addNodeHelper(Node*, int);
        Node* searchKeyHelper(Node*, int);

    public:
        Node* getRoot(); // Returns root of BST
        void addNode(int); // inserts a node in the tree.
        bool searchKey(int); // searches for a data point in the BST
        BST(); // default constructor
        BST(int data); // parameterized constructor

};
#endif
