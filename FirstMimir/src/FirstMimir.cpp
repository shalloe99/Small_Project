//============================================================================
// Name        : FirstMimir.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int fnum,snum;
	cout << "Enter First Number: " << endl;
	cin >> fnum;
	cout << "Enter Second Number: " << endl;
	cin >> snum;
	int totalnum = fnum + snum;
	cout << fnum<< " + "<<snum<<" = "<<totalnum;
	return 0;
}
