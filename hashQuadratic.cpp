#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "hashQuadratic.hpp"

using namespace std;

HashTable::HashTable(int bsize) // Constructor
{
    tableSize = bsize;
    table = new node*[tableSize]; // dynamically allocating new array of nodes for table
    for(int i = 0; i < tableSize; i++) // filling up array w NULL pointers
    {
        table[i] = NULL;
    }
}

bool HashTable::insertItem(int key)
{
    int hash = hashFunction(key);  //find hash value for parameter key
    int counter = 1; //set counter to 1 in order to increment 
    
    node* temp = new node; // dynamically creating new node
    temp->key = key; // setting key
    temp->next = NULL; // setting next pointer
    
    while (table[hash] != NULL)
    {
        hash = (hash + counter) % tableSize; //add hash and counter, then MOD by tableSize for circular array
        counter+=2; // increment counter. achieves same results as counter*2 by adding 2 for each hash iteration. ex: 100, 101, 104, 109, 116 = 100, 100 + 1^2, 100 + 2^2, 100 + 3^2, 100 + 4^2
        numOfCollisions++; // increment collisions counter
    }
    table[hash] = temp; // inserts item
    return true;
}

unsigned int HashTable::hashFunction(int key) // hash function to map values to key. unsigned = cannot be negative integer
{
    return key % tableSize; //return division hash
}

void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[i]->key << endl; //prints key at each space
    }
}

int HashTable::getNumOfCollisions() // accessor for number of collisions
{
    return numOfCollisions;
}

node* HashTable::searchItem(int key)
{
    int counter = 1;
    unsigned int hash = hashFunction(key); // index to look for

    while(table[hash] != NULL && table[hash]->key != key)
    {
        hash = (hash + counter) % tableSize; //add hash and counter, then MOD by tableSize for circular array
        counter+=2; // increment counter. achieves same results as counter*2 by adding 2 for each hash iteration. ex: 100, 101, 104, 109, 116 = 100, 100 + 1^2, 100 + 2^2, 100 + 3^2, 100 + 4^2
        numOfCollisions++; // increment collisions counter
    }
    return table[hash];
}