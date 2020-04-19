#include <iostream>
#include <string>

#include "LL.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    LL LL1;
    // testing out --> delete once inserting and timing dataSetA and dataSetB
    LL1.insert(NULL, 1);
    LL1.insert(LL1.searchLL(1), 2);
	LL1.insert(LL1.searchLL(2),-5);
	LL1.printLL();
    ///////////////////////

    float insert[400];
    float search[400];

    string filename = argv[1]; // the user will enter the file name after writing the ./a.out command on the terminal
    ifstream myfile(filename); // creates an input file stream and opens the file
    if(argc < 2) // if there are less than 2 arguments (if no file name is specified)
    {
        cout << "Failed to open the file.";
        return 0;
    }
    if(!myfile.is_open()) // if the file won't open
    {
        cout << "Failed to open the file.";
        return 0;
    }
    else
    {
        string line = "";
        int numEntries = 0; // counter
        int testData[40000]; // all data will be stored in this array
        for(int i = 0; i < 400000; i++) // loops through the array and sets all elements to 0 
        {
            testData[i] = 0;
        }
        while(getline(myfile,line)) // going through the file line by line
        {
            if(line != "") // check if the line is not empty
            {
                for(int i = 0; i < 400001; i++)
                {
                    // fill up array
                    testData[i]]
                }
            }
        }
    }
    
    
    
}