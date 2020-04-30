#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "LL.hpp"

using namespace std;

Node* LL::getHead() // accessor for the head node
{
    return head;
}

// Add a new node to the list
void LL::insert(Node* prev, int inKey)
{
    //Check if head is Null i.e list is empty
    if(head == NULL)
    {
        head = new Node; //creates new node that is head of empty linked list
        head->key = inKey;
        head->next = NULL;
    }

    // if list is not empty, look for prev and append our node there
    // utilized in our implementation, since we always decide to insert at the head
    else if(prev == NULL)   // inserting at head (but not empty linked list initially)
    {
        Node* newNode = new Node;
        newNode->key = inKey;
        newNode->next = head;
        head = newNode; // the node inserted is /now/ the head
    }

    else // if you want to insert in the middle of the linked list
    {
        Node* newNode = new Node;
        newNode->key = inKey;
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

// Deletes node at a certain index
bool LL::deleteAtIndex(int n)
{
    bool isDeleted = false; // flag for if node is deleted
    Node  *temp;

    if(head == NULL) //list is empty, no nodes
    {
        cout<< "List is already empty"<<endl;
        return isDeleted; //returns false
    }

    // Special case to delete the head
    if (n == 0) 
    {
        temp = head;      //deletes head
        head = head->next;  //head set to next node
        delete temp;
        isDeleted = true; // set flag true here
        return isDeleted;
    }

    Node *pres = head;
    Node *prev = NULL;

    int i = 0;
    while(i != n && pres->next != NULL) //keeps going down list with two crawlers
    {
        prev = pres;
        pres = pres->next;
        i++;
    }
    prev->next = pres->next;
    delete pres;
    isDeleted = true;

    if (n != 0)
    {
        cout << "index out of bound";
        return false;
    }
    return isDeleted;
}


// Prints the keys in the linked list
void LL::printLL()
{
    Node* temp = head;

    while(temp->next != NULL)   
    {
        cout << temp->key << " -> ";
        temp = temp->next;
    }
    cout << temp->key << endl;
}

// Search for a specified key and return a pointer to that node
Node* LL::searchLL(int key)
{
    Node* ptr = head;  //set pointer to head
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next; // keep going through list until you find the key you want
    }
    return ptr; // return pointer to node
}
