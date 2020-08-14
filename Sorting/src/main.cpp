//============================================================================
// Name        : Sorting.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <chrono>

#include "bubblesort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;
void displayArray(vector<int> numbers,int n){
	//Display the numbers - vector
	cout << "Numbers:\n";
	for (int i=0; i<n; i++) {
	  	cout << numbers[i] << ' ';
	}
	cout<<endl;
}
void displayArray(int* numbers,int n){
	//Display the numbers - array
	cout << "Numbers:\n";
	for (int i=0; i< n; i++) {
	  	cout << numbers[i] << ' ';
	}
	cout<<endl;
}


template<class Type>
int stopwatch(Type data, int size){
	auto start = std::chrono::high_resolution_clock::now();
	// sorting methods
//	bubblesort(data,size);
//	heapsort(data,size);
//	mergesort(data,0,size-1);
	quicksort(data,0,size-1);

	auto finish = std::chrono::high_resolution_clock::now();
	auto elapsed = finish - start;
	return elapsed.count();
}

int main() {
	/*Experiment start*/
	srand(time(NULL));
	for(int size = 128; size < 16384; size+=128){
		int data[size];
		// data type
//		for (int i = 0; i <size; i++){//sorted order
//			data[i] = i;
//		}
//		for (int i = 0; i <size; i++){//reverse sorted order
//			data[i] = size-i;
//		}
		for (int i = 0; i <size; i++){//random order
			data[i] = rand();
		}
		cout<<stopwatch(data,size)<<std::endl;
	}



	/*Experiment ends*/

	/*Test*/
    //Create a dynamic array to hold the values
    vector<int> numbers;

    // Create an input file stream
    ifstream in("src/numbers.txt",ios::in);
    int algo_id; // Which sorting algorithm to use
    int count; // How many numbers to read
    in >> algo_id; // read the first line
    in >> count; // read the second line

    int number;  // Variable to hold each number as it is read

    // Read number using the extraction (>>) operator
    // As long as we haven't reached the end of the file, keep reading entries.
    while (in >> number) {
        // Add the number to the end of the array
        numbers.push_back(number);
    }

    // Close the file stream
    in.close();

    int n = numbers.size();

    // Convert to array
    int arr[n];
    for (int i=0; i<n; i++) {
       arr[i] = numbers[i];
    }

    // Display the old set of number

//    displayArray(arr,n);
//    // Sorting the numbers
//    switch(algo_id){
//    	case 1: // bubble sort
//    		{
//    			cout<<"bubble sort"<<endl;
//    			bubblesort(arr,n);
//    		}
//    		break;
//    	case 2: // heap sort
//    		{
//    			cout<<"heap sort"<<endl;
//    			heapsort(arr,n);
//    		}
//    		break;
//    	case 3: // merge sort
//    		{
//    			cout<<"merge sort"<<endl;
//    			mergesort(arr,0,n-1);
//    		}
//    		break;
//    	case 4: // quick sort
//    		{
//    			cout <<"quick sort"<<endl;
//    			quicksort(arr,0,n-1);
//    		}
//    	   	break;
//    	default:
//    		throw runtime_error("Input not valid");
//    }
//    //Display sorting
//    displayArray(arr,n);

    return 0;
}
