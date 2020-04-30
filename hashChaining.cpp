#include <iostream>
#include <vector>
#include <string>
#include "hashChaining.hpp"

using namespace std;

HashTable::HashTable(int bsize) // Constructor
{
    tableSize = bsize; //sets hash table size to parameter
    table = new node*[tableSize]; // dynamically allocating new array of nodes for table
    for(int i = 0; i < tableSize; i++) // filling up array w NULL pointers
    {
        table[i] = NULL;
    }
}

bool HashTable::insertItem(int key)
{
    int hash = hashFunction(key); // call to hashFunction to get hash value
    node* temp = new node;  // create new temp node with key value
    temp->key = key; // setting key
    temp->next = NULL; // setting next pointer
    
    node* crawler = table[hash]; // sets crawler to index with hash value
    if(crawler == NULL) // if the crawler is null (open space)
    {
        table[hash] = temp;
        return true;
    }
    numOfCollisions++; // else, crawler is not NULL, meaning there has been a collision.
    while(crawler->next != NULL) // iterates through list until it finds an open space
    {
        crawler = crawler->next; // keep going until you find an open index in the array
    }
    crawler->next = temp; // open space found

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
        node* crawler = table[i]; //crawler to get through 
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
    unsigned int hash = hashFunction(key); //find hash value using key
    node* crawler = table[hash];  //creates crawler starting at index of hash
    while (crawler != NULL && crawler->key != key) //keeps looping until key is found 
    {
        crawler = crawler->next; // keep going through table until key is found 
    }
    return crawler;
}