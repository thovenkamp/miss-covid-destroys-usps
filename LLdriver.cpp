#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <time.h>

#include "LL.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    LL linkedList;
    int testData[40000]; // all data will be stored in this array
    float insert[400];
    float search[400];
       
    //search ... filling up arrays
    srand(time(nullptr));
    int values[100];
    int searched[100];
    for(int i = 0; i < 100; i++)
    {
        values[i] = rand() % 100; // values 0 - 99
    }
    
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
        int count = 0;
        float startTimeInsert = clock();
        for(int i = 0; i < 40000; i++) // loops through the array and sets all elements to 0 
        {
            getline(myfile,line,',');
            testData[i] = stoi(line);
            if(i % 100 == 0)
            {
                float endTimeInsert = clock();
                float insertTime = (endTimeInsert - startTimeInsert) / 100;
                insert[count] = insertTime;
                count++;
                startTimeInsert = endTimeInsert;

                float startTimeSearch = clock();
                for(int j = 0; j < 100; j++)
                {
                    testData[values[j]] = searched[j];
                }
                float endTimeSearch = clock();
                float searchTime = (endTimeSearch - startTimeSearch) / 100;
                search[0] = searchTime;
            }
        }
    }
}