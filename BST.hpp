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
        /** root is private, so helper is needed to access when we insert, search, print in BST**/

        Node* addNodeHelper(Node*, int);
        void printTreeHelper(Node*);
        void print2DUtilHelper(Node *, int);

        Node* searchKeyHelper(Node*, int);

    public:
        Node* getRoot();                // Returns root of BST
        void addNode(int);              // inserts a node in the tree.
        bool searchKey(int);            // searches for a data point in the BST
        void printTree();               // print BST
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        void print2DUtil(int);

};
#endif
