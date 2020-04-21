#ifndef HASHCHAINING_HPP
#define HASHCHAINING_HPP

#include <iostream>
#include <string>

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;      // No. of buckets (linked lists)
    node* *table;       // Pointer to an array containing buckets
    int numOfCollisions = 0;
    node* createNode(int key, node* next);

public:
    HashTable(int bsize);                   // Constructor
    bool insertItem(int key);               // inserts a key into hash table
    unsigned int hashFunction(int key);     // hash function to map values to key
    void printTable();
    int getNumOfCollisions();

    node* searchItem(int key);
};

#endif
