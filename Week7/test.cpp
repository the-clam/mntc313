#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    float nums[10][11];
    string filename = "C:/Users/Carl/Documents/Code/VSCode/Week7/Assignment/outputFileA.txt";
    FILE* inputFile = fopen(filename.c_str(), "r");

    string rawLine,rawValue;
    
    for(int i = 0; i < 10; i++)
    {
        getline(cin, rawLine);

        for(int j = 0; j < 11; j++)
        {

        }
    }
    fclose(inputFile);
    printf("%s", rawLine);
   
}