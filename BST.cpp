#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10


// creates a new node for BST
Node* BST:: createNode(int data)
{
    Node* newNode = new Node; // dynamically allocate 
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
    root = NULL;
}


BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}


Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL) //if node being added is NULL, create null with int data from parameter
    {
        return createNode(data); 
    }
    else if(currNode->key < data) // adding to right -> follows BST rules
    {
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data) // adding to left -> follows BST rules
    {
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    // cout<<data<<" has been added"<<endl;
}


 // searches data in BST
 // helper for searchKey
Node* BST::searchKeyHelper(Node* currNode, int data)
{
    if(currNode == NULL) //if node is NULL, return NULL
    {
        return NULL;
    }
    if(currNode->key == data) // key is found
    {
        return currNode;
    }
    if(currNode->key > data) // must keep going to the left down the tree -> recursively calls to left
    {
        return searchKeyHelper(currNode->left, data);
    }
    return searchKeyHelper (currNode->right, data); // must keep going to the right down the tree -> recursively calls to right
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key)
{
    Node* temp = searchKeyHelper(root, key); //set node equal to helper (node with key)
    if(temp != NULL)   //if node is not NULL, means it has been found
    {
        return true;
    }
    // cout << "Key not found in the BST" << endl;
    return false;
}

