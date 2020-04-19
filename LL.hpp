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
    void insert(Node *prev, int inKey);
    Node* searchLL(int key);
    bool deleteAtIndex(int index);
    void printLL();
};

#endif
