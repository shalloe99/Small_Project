//============================================================================
// Name        : CSCE.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	// Initiate Variables
		string fname,lname;
		int feet_height,inch_height,birth_year;
	// Import information from the user
		cout << "First name: ";
		cin >> fname;
		cout << "Last name: ";
		cin >> lname;
		cout << "Birth year: ";
		cin >> birth_year;
		cout << "Height in feet (do not include inches): ";
		cin >> feet_height;
		cout << "Height in inches (do not include feet): "<<endl;
		cin >> inch_height;
	// Subsequence process - calculation
		int current_year = 2019;
		int user_age = current_year - birth_year;
		inch_height = inch_height + feet_height*12;
		float cm_height = inch_height *2.54;
		float annual_growth = (cm_height - 51)/user_age;
	// Output result to the user
		cout<<"Hello "+ fname +" "+lname+"."<< endl;
		cout<<"You are "<<user_age<<" years old in 2019."<< endl;
		cout<<"Your height is "<<cm_height<<" cm."<<endl;
		cout<<"You grew an average of "<<annual_growth<<" cm per year (assuming you were 51 cm at birth)."<<endl;
		return 0;



}
