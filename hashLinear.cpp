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
    int hash = hashFunction(key); //calculate hash value using the function
    node* temp = new node; //creates new temp node. set key to parameter value
    temp->key = key;
    temp->next = NULL;
    
    while (table[hash] != NULL) // iterates through the whole table until it finds an open space
    {
        hash = (hash+1) % tableSize; // increments index by 1 (mod tablesize for circular array implementation)
        numOfCollisions++; //increment collisions
    }
    if(table[hash] == NULL) //open space in table
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
        cout << table[i]->key << endl; //prints key at each table space
    }
}

int HashTable::getNumOfCollisions() // accessor for number of collisions
{
    return numOfCollisions;
}

node* HashTable::searchItem(int key)
{
    unsigned int hash = hashFunction(key); // index to look for key within hash table
    
    while(table[hash] != NULL && table[hash]->key != key) // looking through filled spaces and to see if the key matches
    {
        hash = (hash+1) % tableSize; //increment 1 to the hash value, then MOD tableSize for circular array
    }
    return table[hash]; //returns node with key
}