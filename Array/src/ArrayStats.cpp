//============================================================================
// Name        : Array.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator
    cout << "Enter seed value: ";
    int rseed;
    cin >> rseed;
    srand(rseed);
    cout << endl;

    // define constants
    const int NUM_VALUES = 100;
    const int RANGE = 1000000;

    // populate a array with random values
    int values[NUM_VALUES];
    for (int i = 0; i < NUM_VALUES; i++)
    {
        int val = (rand()%2==0) ? rand()%RANGE : rand()%RANGE*-1;
        values[i] = val;
    }

    // iterate through array and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR AUTOGRADER SUBMISSION
    for (int i = 0; i < NUM_VALUES; i++)
    {
        cout << setw(8) << values[i];
        if ((i + 1) % 10 == 0) cout << endl; // new line every 10 numbers
        // For fun, change i+1 to just i above, run and
        //    see how that affects the output
    }
    cout << endl;

    int min = values[0], max = values[0];
    double avg, sum;
    for (int i = 0; i <NUM_VALUES;i++){
    	if(min >values[i]) min = values[i];
    	if(max <values[i]) max = values[i];
    	sum += values[i];
    }
    avg = sum / NUM_VALUES;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;
}
