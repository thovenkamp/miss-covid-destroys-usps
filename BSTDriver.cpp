#include <iostream>
#include <fstream>
#include "BST.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int testData[40000]; // all data will be stored in this array
    float insert[400];
    float search[400];
    BST tree;

    //search ... filling up arrays
    srand(time(nullptr));
    int values[100];
    int searched[100];
    int total = 100;
    int trials = 0;
    int count = 0;
    
    if(argc < 2) // if there are less than 2 arguments (if no file name is specified)
    {
        cout << "Failed to open the file.";
        return 0;
    }
    string filename = argv[1]; // the user will enter the file name after writing the ./a.out command on the terminal
    ifstream myfile(filename); // creates an input file stream and opens the file
    
    if(!myfile.is_open()) // if the file won't open
    {
        cout << "Failed to open the file.";
        return 0;
    }
    else
    {
        string line = "";
        float startTimeInsert = clock();
        for(int i = 0; i < 40000; i++) // loops through the array
        {
            getline(myfile,line,',');
            testData[i] = stoi(line);
            tree.addNode(testData[i]); // creating tree
            //////// may not work lmao ///////////
            if(i % 100 == 0) // every 100
            {
                float endTimeInsert = clock();
                float insertTime = (endTimeInsert - startTimeInsert) / 100;
                insert[count] = insertTime;
                startTimeInsert = endTimeInsert;


                for(int i = 0; i < 100; i++)
                {
                    values[i] = rand() % total; // values 0 - total
                }
                float startTimeSearch = clock();
                cout << startTimeSearch << endl;
                for(int j = 0; j < 100; j++)
                {
                    tree.searchKey(values[j]);
                }
                float endTimeSearch = clock();
                float searchTime = (endTimeSearch - startTimeSearch) / 100;
                total += 100;
                search[count] = searchTime;
                count++;
            }
            ///////////////////////////
        }
    }
    return 0;
}

///////////////////////////////