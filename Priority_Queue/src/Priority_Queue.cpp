//============================================================================
// Name        : Priority_Queue.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PriorityQueue.h"
using namespace std;
#include <chrono>

template<class Type>
int stopwatch(PriorityQueue<Type> queue, int running_times){
	//srand(time(NULL));
	auto start = std::chrono::high_resolution_clock::now();
	// Heavy computation tasks here
	for (int i = 0; i <running_times; i++){
		queue.insertItem(i);
	}
	for (int i = 0; i <running_times; i++){
		queue.removeMin();
	}
	auto finish = std::chrono::high_resolution_clock::now();
	auto elapsed = finish - start;
	return elapsed.count();
}
int main() {
	unsorted_PriorityQueue<int> unsorted;
	sorted_PriorityQueue<int> sorted;
	heap_PriorityQueue<int> heap;

	heap.insertItem(5);
	heap.insertItem(7);
	heap.insertItem(6);
	heap.removeMin();
	heap.show();
	heap.removeMin();
		heap.show();
//	cout<<"Unsorted Priority Queue: "<<endl;
//	for (int i = 0;i<=1048576;i+=128){
//		cout<<stopwatch<int>(unsorted,i)<<endl;
//	}
//	cout<<endl<<endl;
//		cout<<"Sorted Priority Queue: "<<endl;
//		for (int i = 0;i<=1048576;i+=128){
//			cout<<stopwatch<int>(sorted,i)<<endl;
//		}
//		cout<<endl<<endl;
//	cout<<"Heap Sorted Priority Queue: "<<endl;
//	for (int i = 0;i<=1048576;i+=128){
//		cout<<stopwatch<int>(heap,i)<<endl;
//	}
//	cout<<endl<<endl;


//  Sample test cases:
//	unsorted_PriorityQueue<int> unsorted;
//	unsorted.insertItem(7);
//	unsorted.insertItem(23);
//	unsorted.insertItem(9);
//	unsorted.insertItem(3);
//	unsorted.insertItem(12);
//	unsorted.insertItem(5);
//	unsorted.insertItem(2);
//	unsorted.insertItem(32);
//	unsorted.insertItem(6);
//	unsorted.insertItem(43);
//	unsorted.show();
//	sorted_PriorityQueue<int> sorted;
//	sorted.insertItem(7);
//	sorted.insertItem(23);
//	sorted.insertItem(9);
//	sorted.insertItem(3);
//	sorted.insertItem(12);
//	sorted.insertItem(5);
//	sorted.insertItem(2);
//	sorted.insertItem(32);
//	sorted.insertItem(6);
//	sorted.insertItem(43);
//	sorted.show();
//	heap_PriorityQueue<int> heap;
//	heap.insertItem(7);
//	heap.insertItem(23);
//	heap.insertItem(9);
//	heap.insertItem(3);
//	heap.insertItem(12);
//	heap.insertItem(5);
//	heap.insertItem(2);
//	heap.insertItem(32);
//	heap.insertItem(6);
//	heap.insertItem(43);
//	heap.show();
	return 0;
}
