//============================================================================
// Name        : Hash_Table.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <chrono>

#include "ChainingHashTable.h"
#include "DoubleHashTable.h"
#include "ProbingHashTable.h"
#include "HashTable.h"
using namespace std;


unsigned int stopwatch(vector<string> dict, int running_times){
	//srand(time(NULL));
	DoubleHashTable doublehash;
	ProbingHashTable probinghash;
	ChainingHashTable chaininghash;
	auto start = std::chrono::high_resolution_clock::now();
	// Heavy computation tasks here
	/* theoretical analysis */

//	for(int i = 0;i < running_times; i++){
//		probinghash.insert(dict[i],0);
//	}
//	for(int i = 0;i < running_times; i++){
//		doublehash.insert(dict[i],0);
//	}
	for(int i = 0;i < running_times; i++){
		chaininghash.insert(dict[i],0);
	}

	auto finish = std::chrono::high_resolution_clock::now();
	auto elapsed = finish - start;
	return elapsed.count();
}

int main() {
	vector<string> dictionary;
	ifstream in("src/dictionary.txt",ios::in);
	string word;
	while (in>>word){
		// Add the word to the end of the array
		dictionary.push_back(word);
	}
	in.close();
	// dictionary size 1,000,000

	for(int i = 0;i < 1000000; i+= 10000){
		cout<<stopwatch(dictionary,i)<<endl;
	}
//	for(int i = 0;i < 1000000; i+= 10000){
//		cout<<stopwatch(doublehash, dictionary,i)<<endl;
//	}
//	for(int i = 0;i < 1000000; i+= 10000){
//		cout<<stopwatch(chaininghash, dictionary,i)<<endl;
//	}
/*  Insertion Check code */

//	for(int i = 0;i < dictionary.size(); i++){
//		cout<<"Line: "<<i+1<<endl;
//		probinghash.insert(dictionary[i],0);
//	}
//	probinghash.printAll("out_probinghash.txt");
//	for(int i = 0;i < dictionary.size(); i++){
//		cout<<"Line: "<<i+1<<endl;
//		doublehash.insert(dictionary[i],0);
//	}
//	doublehash.printAll("out_doublehash.txt");
//	for(int i = 0;i < dictionary.size(); i++){
//		cout<<"Line: "<<i+1<<endl;
//		chaininghash.insert(dictionary[i],0);
//	}
//	chaininghash.printAll("out_chaininghash.txt");

/*  Sample test code */

//	probinghash.printAll("out_probinghash.txt");
//	doublehash.printAll("out_doublehash.txt");
//  chaininghash.printAll("out_chaininghash.txt");
//	doublehash.insert("c-",0);
//	doublehash.insert("X8",0);
//	doublehash.insert("X8",0);
//	cout<<doublehash.remove("X8")<<endl;
//	doublehash.printAll("out.txt");
//	ChainingHashTable chainghash;
//	chainghash.insert("c-",0);
//	chainghash.insert("X8",0);
//	chainghash.insert("X8",0);
//	cout<<chainghash.remove("X8")<<endl;
//	chainghash.printAll("out.txt");
//	ProbingHashTable probinghash;
//	probinghash.insert("c-",0);
//	probinghash.insert("X8",0);
//	probinghash.insert("X8",0);
//	probinghash.insert("c-",0);
//	probinghash.remove("c-");
//	probinghash.printAll("out.txt");
//	for(string w : dictionary){
//		chaininghash.insert(w, 1);
//	}

	return 0;
}
