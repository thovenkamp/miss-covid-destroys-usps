#include <iostream>
#include <vector>
#include <string>
#include "hash.hpp"

using namespace std;

HashTable(int bsize) // Constructor
{
    tableSize = bsize;
}

bool HashTable::insertItem(int key) // inserts a key into hash table
{
    index = hashSum(value, tableSize) 
    node.key = value 
    node.next = NULL 
    if (hashTable[index] == NULL) 
              node.previous = NULL 
          hashTable[index] = hashElement
      else 
        tmp = hashTable[index]
          while(tmp != NULL) 
            if(tmp.key == value) 
                 print("duplicate") 
                 return 
}              

unsigned int HashTable::hashFunction(int key) // hash function to map values to key. unsigned = cannot be negative integer
{
    // get the sum
    int hash = 0;
    for(int i = 0; i < key.size(); i++)
    {
        hash = hash + key[i];
    }
    cout << "sum " << endl;
    // mod by the table size
    hash = hash % tableSize;
    return hash;
}

void HashTable::printTable()
{
    for(int i = 0; i < 401; i++)
    {
        cout << 
    }
    
}

int HashTable::getNumOfCollision()
{

}

node* HashTable::searchItem(int key)
{
    
}