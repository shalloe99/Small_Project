//============================================================================
// Name        : Temperature_Query.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "TemperatureDatabase.h"

#include <iostream>
using namespace std;

// You do not need to edit this code
int main(int argc, char** argv) {
	TemperatureDatabase database;
	database.loadData("src/test.txt");
	cout<< database.records.print();
	cout<<"------------------------"<<endl;
	database.performQuery("src/query.txt");

/*	Copy Assignment cases
    LinkedList ll;
	ll.insert("mac", 2015, 7, 22.3);
	ll.insert("abe", 2017, 6, 18.5);
	ll.insert("zeb", 1995, 2, 5);
	ll.insert("kev", 2013, 5, 19.2);
	LinkedList ll2;
	ll2 = ll;
	cout<<ll.print()<<endl;
	cout<<ll2.print()<<endl;*/
/*	Node test cases
 * Node node1("abe", 2017, 6, 18.5);
	Node node2("mac", 2015, 7, 22.3);
	cout<<(node2<node1)<<endl;*/
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
	//	cout << argv[0] << "---" << argv[1] << "---" << argv[2]<<endl;
		TemperatureDatabase database;
		database.loadData(argv[1]); // Do in Part 1
		database.performQuery(argv[2]); // Do in Part 2
	}
}
