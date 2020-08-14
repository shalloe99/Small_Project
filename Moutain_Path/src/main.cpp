//============================================================================
// Name        : Moutain_Path.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

// Normally you should not use global variables. However, the stack is
//   limited in size and will not allow arrays of this size. We'll learn
//   later how to put these arrays on the heap instead. Regardless, for now
//   we'll use these and treat them as if they were declared in main. So
//   when used in functions, we'll pass them as we would any other array.

static int elevations[MAX_ROWS][MAX_COLS];
static Pixel image[MAX_ROWS][MAX_COLS];

int main() {
	ifstream myfile;
	string filename;
	int rows,cols;
	cin>>rows;
	if(!cin.good()){
		cout<<"Error: Problem reading in rows and columns."<<endl;
		return 1;
	}
	cin>>cols;
	if(!cin.good()){
		cout<<"Error: Problem reading in rows and columns."<<endl;
		return 1;
	}
	if(rows<=0 or cols<=0){
		cout<<"Error: Problem reading in rows and columns."<<endl;
		return 1;
	}
	cin>>filename;

	myfile.open(filename);
	if(!myfile.is_open()){
		cout<< "Error: Unable to open file <"<<filename<<">."<<endl;
		return 1;
	}
	if(myfile.eof()){
		cout<<"Error: Problem reading the file."<<endl;
		return 1;
	}
	int count = 0;
	while (true) {
	    int x;
	    myfile >> x;
	    if( myfile.eof() ) break;
	    count++;
	    if(!myfile.good()){
	    	cout<<"Error: Read a non-integer value."<<endl;
	   		break;
 		}
	}
	cout<< count <<endl;
	cout<< rows*cols<<endl;
	if(count < (rows*cols)){
		cout<<"Error: End of file reached prior to getting all the required data."<<endl;
		return 1;
	}
	if(count >= (rows*cols)){
		cout<<"Error: Too many data points."<<endl;
	}
	myfile.clear();
	myfile.seekg(0, std::ios::beg);// Back to the start
	loadData(elevations,rows,cols,myfile);
	int max,min;
	findMaxMin(elevations,rows,cols,max,min);
	loadGreyscale(image,elevations,rows,cols,max,min);
	Pixel RED;
	RED.red = 252;
	RED.blue = 63;
	RED.green = 25;
	int step;
	int stepArray[MAX_ROWS];
	for(int i = 0;i<rows;i++){
		step = colorPath(elevations,image, rows, cols,RED,i);
		stepArray[i] = step;
	}
	int minStep = 0;
	for(int i = 0; i<rows;i++){
		if(stepArray[minStep] >= stepArray[i]){
			minStep = i;
		}
	}
	Pixel GREEN;
	RED.red = 31;
	RED.blue = 13;
	RED.green = 253;
	int tempory = colorPath(elevations,image, rows, cols,RED,minStep);
	myfile.close();

	ofstream yourfile;
	filename = filename+".ppm";
//	string strrows = to_string(rows);
//	string strcols = to_string(cols);
//	filename = filename + strrows + "-"+strcols+".dat.ppm";
	yourfile.open(filename);
	outputImage(image,rows,cols,yourfile);
	yourfile.close();
	return 0;
}
