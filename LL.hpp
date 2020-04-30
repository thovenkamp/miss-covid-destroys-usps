/**
 * Names: Jamie Joung & Taryn Hovenkamp
 * Contributions:
 *  - Livecoded (utilized Live Share via VS Code with audio call)
 *  - Each function was created with joint efforts, therefore, we understand all of our coding and not just bits and pieces of it.
 *  - Additionally, each function was commented by both partners and thoroughly discussed 
 * */

#ifndef LL_H
#define LL_H
#include <iostream>

struct Node
{
    int key;
    Node *next;
};

class LL
{
  private:
    Node *head;

  public:
    LL()
    {
        head = NULL;
    }
    Node* getHead();
    void insert(Node *prev, int inKey);
    Node* searchLL(int key);
    bool deleteAtIndex(int index);
    void printLL();
};

#endif
