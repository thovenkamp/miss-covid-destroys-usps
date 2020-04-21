#include <iostream>
#include <fstream>
#include <string>

#include "LL.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    int testData[40000]; // all data will be stored in this array
    float insert[400];
    float search[400];
    
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
        for(int i = 0; i < 40000; i++) // loops through the array and sets all elements to 0 
        {
            getline(myfile,line,',');
            testData[i] = stoi(line);
        }
    }
    for(int i = 0; i < 100; i++)
    {
        cout << testData[i] << " " << endl;
    }
    
}