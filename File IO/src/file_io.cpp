//============================================================================
// Name        : File.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
using namespace std;



int main()
{
	const int MAX_SIZE = 100;
	srand(time(NULL));

	int nums[MAX_SIZE];
    int size = 0;

	//EDIT1 comment out the next for loop
	// Load with random values
	for (int i=0; i<MAX_SIZE; ++i) {
		nums[i] = (rand()%2) ? -1* rand()%999 : rand()%999;
        size++;
	}

	// EDIT2: Setup and use input file "nums.dat"
	string filename = "nums.dat"; // src/nums.dat
	// Input Step 1 Open file, preferably with RAII approach
	ifstream myfile;
	myfile.open(filename);
	if (!myfile.is_open()){
		cout << "File not found"<<endl;
		return 1;
	}

	int count = 0;
	int temp = 0;
	// Input Step 2 Check that file opened sucessfully
	while(myfile.good()){
		myfile >> temp;
		nums[count] = temp;
		count ++;
	//	myfile.clear();
	//	myfile.ignore(numeric_limits<std::streamsize>::max(),'\n');
	}
	// Input Step 3 Use file (i.e. read numbers from file into nums array)

	// Input Step 4 Close file, preferably with RAII approach
	myfile.close();

    // Output values in array to standard out
	cout << "Unsorted values: " << endl;
	for (unsigned int i = 0; i < size; ++i) {
		cout << setw(5) << nums[i];
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	sort(nums, nums+size);

	// Output values in array to standard out
	cout << "Sorted values: " << endl;
	for (unsigned int i = 0; i < size; ++i) {
		cout << setw(5) << nums[i];
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	// Calculate the median
    // next statement probably needs a comment,
	//    but as a challenge figure out what's going on...
	double median = (size % 2) ? nums[(size - 1) / 2] :
		(nums[(size - 1) / 2] + nums[size / 2]) / 2.0;

    // Calculate the average
    int sum = 0;
    for (unsigned int i=0; i < size; ++i) {
        sum += nums[i];
    }
    double average = sum/size;

    // Edit3: convert to send to the output file instead of to standard out
    ofstream yourfile;
    string outputFile = "stats.dat";
	// Output Step 1 Open file, preferably with RAII approach
    yourfile.open(outputFile);
	// Output Step 2: Check that file opened successfully
    if (!yourfile.is_open()){
    		cout << "File not found"<<endl;
    		return 1;
    	}
    if(yourfile.good()){

	// Output Step 3: Use file
    //  (convert from using standard out to the output filestream)
		yourfile << "Min: " << nums[0] <<"\n";
		yourfile << "Max: " << nums[size - 1] << "\n";
		yourfile << "Median: " << median << "\n";
		yourfile << "Average: " << average << "\n";
    }
	// Output Step 4 Close, preferably with RAII approach
    yourfile.close();
     return 0;
}
