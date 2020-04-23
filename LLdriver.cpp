#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <iomanip>
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
        auto startTimeInsert = chrono::high_resolution_clock::now();
        for(int i = 0; i < 40000; i++) // loops through the array
        {
            getline(myfile,line,',');
            testData[i] = stoi(line);
            if(linkedList.searchLL(values[i]) == NULL)
            {
                linkedList.insert(NULL, testData[i]); // inserts everything at the head
            }
            if(i % 100 == 99) // every 100
            {
                auto endTimeInsert = chrono::high_resolution_clock::now();
                double insertTime = (chrono::duration_cast<chrono::nanoseconds>(endTimeInsert-startTimeInsert).count()) * 1e-9 / 100;
                // float insertTime = (float)((endTimeInsert - startTimeInsert) / 100);
                insert[count] = insertTime;
                startTimeInsert = endTimeInsert;


                for(int j = 0; j < 100; j++)
                {
                    values[j] = rand() % total; // values 0 to total-1
                }
                total += 100;
				
                auto startTimeSearch = chrono::high_resolution_clock::now();
                for(int j = 0; j < 100; j++)
                {
                    linkedList.searchLL(values[j]);
                }
                auto endTimeSearch = chrono::high_resolution_clock::now();
                double searchTime = (chrono::duration_cast<chrono::nanoseconds>(endTimeSearch-startTimeSearch).count()) * 1e-9 / 100;
                // float searchTime = (float)((endTimeSearch - startTimeSearch) / 100);

                if(count < 40000)
                {
                    cout << insertTime << endl;
                }
                search[count] = searchTime;
                count++;
            }
        }
    }
	// for(int i = 0; i < 400; i++)
    // {
    //     cout << (float)insert[i]/CLOCKS_PER_SEC << endl;
    // }
}