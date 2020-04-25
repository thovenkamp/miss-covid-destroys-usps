#include <iostream>
#include <vector>
#include <string>
#include "hashLinear.hpp"

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
    int hash = hashFunction(key); 
    node* temp = new node;
    temp->key = key;
    temp->next = NULL;
    
    while (table[hash] != NULL)
    {
        hash = (hash+1) % tableSize;
        numOfCollisions++;
    }
    if(table[hash] == NULL)
    {
        table[hash] = temp; // inserts item
        return true;
    }
    return false;
}

unsigned int HashTable::hashFunction(int key) // hash function to map values to key. unsigned = cannot be negative integer
{
    return key % tableSize; //return division hash
}

void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << table[i]->key << endl;
    }
}

int HashTable::getNumOfCollisions()
{
    return numOfCollisions;
}

node* HashTable::searchItem(int key)
{
    // unsigned int hash = hashFunction(key); //find hash value for key
    // for (int i = 0; i < tableSize; i++)
    // {
    //     if (table[i]->key == key) //goes through entire table, if key is found
    //     {
    //         return table[i]; //return node at index i
    //     }
    // }
    // return NULL;

    unsigned int hash = hashFunction(key); // index to look for
    
    while(table[hash] != NULL && table[hash]->key != key)
    {
        hash = (hash+1) % tableSize;
    }
    return table[hash];
}