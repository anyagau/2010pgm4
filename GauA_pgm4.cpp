//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Create a bar graph based off the input from a file
// Process: After inputting the initial number, it associates that number with the proper .txt file. From there, it takes the input from the .txt file
// for the bar graph and creates the bar graph. Between inputs, the code tests for minimum/maximum values and saves them to be outputted after the bar
// graph is finished.
// Results: Hopefully a bar graph, as well as the three largest and smallest variables inputted from the .txt file
//
// Class: CS2010
// Section: 100x
// Term: Fall 2024
// Author: Anya Gau
//
// Reflection: Essentially, I have no clue how this assignment will turn out as for some reason I could not input from the files. I don't know what
// or where I went wrong, if I even did (??). I had a friend who has done something like this before me try to help find out what is wrong, but he 
// couldn't either. I followed the instructions for downloading the files and putting them in the right folder, so I don't know. I have no idea what
// went well. 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char SPACE = ' ';
const char SET = 'X';
int main () {

    // All the variables
    ifstream inFS; 
    int userChoice;
    string userString;
    int maxValue;
    int maxValue2;
    int maxValue3;
    int minValue;
    int minValue2;
    int minValue3;
    int xInput;
    int yCount = 1;
    int xCount;
    int x;
    int invalidCount = 0;

    // The first output that prompts you to select your choice
    do {
        cout << "Select a file to process: " << "\n" << "1. mixed.txt" << "\n" << "2. valid.txt" << "\n" << "3. three.txt" << "\n" << "4. missing.txt" << "\n";
        cout << "\n" << "Choice: ";
        cin >> userChoice;

    //This will assign each choice with the proper output via switch statement
        switch (userChoice) {
            case 1:
                userString = "mixed.txt";
                break;
            case 2:
                userString = "valid.txt";
                break;
            case 3: 
                userString = "three.txt";
                break;
            case 4:
                cout << "\n" << "ERROR: Data file not found.";
                return 1;
        }
    } while ((userChoice < 0) || (userChoice > 4));

    cout << "Bar graph for data contained in " << userString << " file." << "\n" << "\n";

    inFS.open(userString);
    inFS >> xInput;
    
    // setting the max and min values
    maxValue = xInput;
    maxValue2 = xInput;
    maxValue3 = xInput;
    minValue = xInput;
    minValue2 = xInput;
    minValue3 = xInput;

    while (xInput != 9999); {

        // Finding the maximum 3 values
        if (xInput > maxValue) {
            maxValue3 = maxValue2;
            maxValue2 = maxValue;
            maxValue = xInput;
        }
        else if ((xInput > maxValue2) && (xInput < maxValue)) {
            maxValue3 = maxValue2;
            maxValue2 = xInput;
        }
        else if ((xInput > maxValue3) && (xInput < maxValue2)) {
            maxValue3 = xInput;
        }

        // Finding the minimum 3 values
        if (xInput < minValue) {
            minValue3 = minValue2;
            minValue2 = minValue;
            minValue = xInput;
        }
        else if ((xInput < minValue2) && (xInput > minValue)) {
            minValue3 = minValue2;
            minValue2 = xInput;
        }
        else if ((xInput < minValue3) && (xInput > minValue2)) {
            minValue3 = xInput;
        }

        while (xInput <= -1) {
            invalidCount = invalidCount + 1;
            xInput = abs(xInput);
        }
        cout << right << setw(2) << yCount << SPACE << "|" << SPACE;

        //xInput will not output more than 112, I don't know how to determine what will fit the console window
        if (xInput >= 112) {
                xInput = 112;
            }
        for (x = 0; x < xInput; ++x) {
            cout << SET;
        }
        cout << "\n";
        ++yCount;

        inFS >> xInput;

    }

    inFS.close();

    // This will make the x-axis for the bar graph
    cout << setfill('-') << setw(118) << "\n";
    cout << setfill(' ') << setw(6) << "1" << setfill(' ') << setw(10) << "10" << setfill(' ') << setw(10) << "20" << setfill(' ') << setw(10) << "30" ;
    cout << setfill(' ') << setw(10) << "40" << setfill(' ') << setw(10) << "50" << setfill(' ') << setw(10) << "60" << setfill(' ') << setw(10) << "70";
    cout << setfill(' ') << setw(10) << "80" << setfill(' ') << setw(10) << "90" << setfill(' ') << setw(10) << "100" << setfill(' ') << setw(10) << "110" << "\n";

    // The output for minimum/maximum values
    cout << "\n" << "SMALLEST" << "\n" << "========" << "\n";
    cout << "The 1st smallest value: " << minValue << "\n";
    cout << "The 2nd smallest value: " << minValue2 << "\n";
    cout << "The 3rd smallest value: " << minValue3 << "\n" << "\n";

    cout << "LARGEST" << "\n" << "=======" << "\n";
    cout << "The 1st largest value: " << maxValue << "\n";
    cout << "The 2nd largest value: " << maxValue2 << "\n";
    cout << "The 3rd largest value: " << maxValue3 << "\n" << "\n";

    // Datermining if value/s, will not output if there are no invalid values to begin with
    if (invalidCount == 1) {
        cout << "INVALID" << "\n" << "=======" << "\n";
        cout << "There is " << invalidCount << " invalid value in this data." << "\n";
    }
    else if(invalidCount > 1) {
        cout << "INVALID" << "\n" << "=======" << "\n";
        cout << "There are " << invalidCount << " invalid values in this data." << "\n";
    }

    if (inFS.is_open()) {
        inFS.close();
    }


    return 0;
}