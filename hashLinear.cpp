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
    
    node* crawler = table[hash];
    if(crawler == NULL)
    {
        table[hash] = temp;
        return true;
    }
    numOfCollisions++;
    while(crawler->next != NULL)
    {
        crawler = crawler->next; // keep going until you find an open index in the array
    }
    crawler->next = temp;
    
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
        node* crawler = table[i];
        while(crawler != NULL)
        {
            cout << crawler->key << endl; // prints all keys from linked list at one node
            crawler = crawler->next; // goes down linked list
        }
    }
}

int HashTable::getNumOfCollisions()
{
    return numOfCollisions;
}

node* HashTable::searchItem(int key)
{
    unsigned int hash = hashFunction(key);
    node* crawler = table[hash];
    while (crawler != NULL && crawler->key != key) //keeps looping until key is found 
    {
        crawler = crawler->next; // keep going through table
    }
    return crawler;
}