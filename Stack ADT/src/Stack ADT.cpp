//============================================================================
// Name        : Stack.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include "Stack.h"

using namespace std;

template<class Type>
int stopwatch(AbstractStack<Type> stack, int running_times){
	srand(time(NULL));
	auto start = std::chrono::high_resolution_clock::now();
	// Heavy computation tasks here
	for (int i = 0; i <running_times; i++){
		stack.push(i);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	auto elapsed = finish - start;
	return elapsed.count();
}

int main() {

	ArrayStack<int> arraystack;
	DoubleArrayStack<int> doublearraystack;
	LinkedList<int> linkedlist;
	// show content
	cout<<"Arraystack with incremental strategy: "<<endl;
	for (int i = 1000;i<=100000;i+=1000){
		cout<<stopwatch<int>(arraystack,i)<<",";
	}
	cout<<endl<<endl;
	cout<<"Arraystack with doubling strategy: "<<endl;
	for (int i = 1000;i<=100000;i+=1000){
		cout<<stopwatch<int>(doublearraystack,i)<<",";
	}
	cout<<endl<<endl;
	cout<<"Linked list stack: "<<endl;
	for (int i = 1000;i<=100000;i+=1000){
		cout<<stopwatch<int>(linkedlist,i)<<",";
	}
	cout<<endl<<endl;
	return 0;
}
