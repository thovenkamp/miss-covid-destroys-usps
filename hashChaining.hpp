/**
 * Names: Jamie Joung & Taryn Hovenkamp
 * Contributions:
 *  - Livecoded (utilized Live Share via VS Code with audio call)
 *  - Each function was created with joint efforts, therefore, we understand all of our coding and not just bits and pieces of it.
 *  - Additionally, each function was commented by both partners and thoroughly discussed 
 * */

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
