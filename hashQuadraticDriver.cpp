#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "hashQuadratic.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    HashTable hashT(40009);
    
    int testData[40000]; // all data will be stored in this array
    float insert[400];
    float search[400];

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
            hashT.insertItem(stoi(line));
            if(i % 100 == 99); // 100 elements have been inserted
            {
                auto endTimeInsert = chrono::high_resolution_clock::now(); //marks end time after 100 elements have been added
                double insertTime = (chrono::duration_cast<chrono::nanoseconds>(endTimeInsert-startTimeInsert).count()) * 1e-2;//(float)(endTimeInsert - startTimeInsert);
                insert[count] = insertTime;

                for(int j = 0; j < 100; j++)
                {
                    values[j] = rand() % total; // values 0 - total
                }
                // cout << "after random" << endl;
                auto startTimeSearch = chrono::high_resolution_clock::now();
                for(int j = 0; j < 100; j++)
                {
                    hashT.searchItem(values[j]);
                }
                auto endTimeSearch = chrono::high_resolution_clock::now();
                double searchTime = (chrono::duration_cast<chrono::nanoseconds>(endTimeSearch-startTimeSearch).count()) * 1e-2;
            
                // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
                total += 100;
                search[count] = searchTime;
                count++;
                startTimeInsert = chrono::high_resolution_clock::now(); // resets clock
                // cout << "end" << endl;
            }    
        }
    }

    
    ofstream outFile;
    string outPut = argv[2];
    outFile.open(outPut, ios::out | ios::app);
    
    for(int i = 0; i < 400; i++)
    {
        outFile << endl << insert[i] << endl;
    }
    outFile.close();

    ofstream outFile2;
    string outPut2 = argv[3];
    outFile2.open(outPut2, ios::out | ios::app);
    for(int i = 0; i < 400; i++)
    {
        outFile2 << endl << search[i] << endl;
    }
    outFile2.close();
    return 0;
}