/*
 * Node.h
 *
 *  Created on: Oct 16, 2019
 *      Author: zshaw
 */
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <list>
#include <iterator>
#include <exception>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class PriorityQueue
{
private:
	// data here

public:
   PriorityQueue(void){}

   ~PriorityQueue(void){}

   bool isEmpty(void);

   int size(void);

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){}

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){}

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void );
};

template <class Type>
class unsorted_PriorityQueue : public PriorityQueue<Type>{
private:
	int Size;
	list<Type> priority_queue;
	typename list <Type> :: iterator it;
public:
	unsorted_PriorityQueue(void) : PriorityQueue<Type>(){
		Size = 0;
   }

   ~unsorted_PriorityQueue(void){ }

   bool isEmpty(void){
	 return priority_queue.empty();
   }

   int size(void){ return Size;}

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
	   priority_queue.push_back(data);
	   Size += 1;
   }
   // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
   Type minValue ( void ){
 	  if(isEmpty()){
 		throw std::runtime_error("Empty queue error");
 	  }else{
 	  	Type temp = priority_queue.front();
		it = priority_queue.begin();
		while(it != priority_queue.end()){
			if(temp >*it)
				temp = it;
			it++;
		}
		return temp;
 	  }
   }
   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
	   if(isEmpty()){
		 throw std::runtime_error("Empty queue error");
	   }else{
		   Type temp = minValue();
		   priority_queue.remove(temp);
		   return temp;
	   }
   }
   void show(void){
	   typename list <Type> :: iterator it;
	   for(it = priority_queue.begin(); it != priority_queue.end(); ++it)
	         cout << ' ' << *it;
	   cout << '\n';
   }
};

template <class Type>
class sorted_PriorityQueue : public PriorityQueue<Type>{
private:
	int Size;
	list<Type> priority_queue;
	typename list <Type> :: iterator it;
public:
	sorted_PriorityQueue(void) : PriorityQueue<Type>(){
		Size = 0;
   }

   ~sorted_PriorityQueue(void){   }

   bool isEmpty(void){
	 return priority_queue.empty();
   }

   int size(void){ return Size;}

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
//	   if(isEmpty()){
//		   priority_queue.push_back(data);
//	   }else{
		it = priority_queue.begin();
		while(data > *it and it != priority_queue.end())
			it++;
	   priority_queue.insert(it,data);
	   Size += 1;
   }
   // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
   Type minValue ( void ){
 	  if(isEmpty()){
 		throw std::runtime_error("Empty queue error");
 	  }else{
 	  	return priority_queue.front();
 	  }
   }
   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
	   if(isEmpty()){
		 throw std::runtime_error("Empty queue error");
	   }else{
		   Type temp = minValue();
		   priority_queue.remove(temp);
		   return temp;
	   }
   }
   void show(void){
	   typename list <Type> :: iterator it;
	   for(it = priority_queue.begin(); it != priority_queue.end(); ++it)
	         cout << ' ' << *it;
	   cout << '\n';
   }
};

template <class Type>
class heap_PriorityQueue : public PriorityQueue<Type>{
private:
	int Size;
	int capacity = 1048576;
	Type* heap_array;
	Type father;
public:
	heap_PriorityQueue(void) : PriorityQueue<Type>(){
		Size = 0;
		heap_array = new Type[capacity];
		std::cout<<"The capacity of this heap will be "<<capacity<<std::endl;
	}

   ~heap_PriorityQueue(void){
	   delete[] heap_array;
   }

   bool isEmpty(void){
	  if(Size ==0)
		  return true;
	  return false;
   }
   int size(void){ return Size;}
   Type minValue ( void ){
      if(isEmpty()){
    	throw std::runtime_error("Empty queue error");
      }else{
    	return heap_array[0];
      }
   }
   void insertItem ( Type data ){
	   if(Size>=capacity){
		   throw std::runtime_error("Exceed Capacity error");
	   }else{
		  if(Size==0){
			  heap_array[Size] = data;
		  }else{
		  heap_array[Size] = data;
		  int old_loc_pointer = Size;
		  int loc_pointer;
		  if(old_loc_pointer%2==0){//right child
			 loc_pointer = (old_loc_pointer-2)/2;
			 father = heap_array[loc_pointer];
		  }else{//left child
			 loc_pointer = (old_loc_pointer-1)/2;
			 father = heap_array[loc_pointer];
		  }
		  while(data<father){
			  Type temp = data;
			  heap_array[loc_pointer] = temp;
			  heap_array[old_loc_pointer] = father;
			  old_loc_pointer = loc_pointer;//update pointer

			  if(loc_pointer%2==0){//right child
				loc_pointer = (old_loc_pointer-2)/2;
			  	father = heap_array[loc_pointer];
			  }else{//left child
			  	loc_pointer = (old_loc_pointer-1)/2;
			  	father = heap_array[loc_pointer];
			  	}
		  }
		 }
	   }
	  Size++;
   }
   Type removeMin ( void ){
   	   if(isEmpty()){
   		 throw std::runtime_error("Empty queue error");
   	   }else{
   		   Size--;
   		   Type min = minValue();
   		   Type newTop = heap_array[Size];

   		   heap_array[0] = newTop;
   		   int loc_pointer = 0;
   		   int left_loc_pointer = 2*loc_pointer +1;
   		   int right_loc_pointer = 2*loc_pointer +2;
   		   Type leftChild = heap_array[left_loc_pointer];
   		   Type rightChild = heap_array[right_loc_pointer];

   		   while((newTop>leftChild or newTop>rightChild) and left_loc_pointer<Size){
   	   		   if(leftChild<rightChild and newTop>leftChild){
   	   			   //swap with left Child
   	   			   Type temp = heap_array[loc_pointer];
   	   			   heap_array[left_loc_pointer] = temp;
   	   			   heap_array[loc_pointer] = leftChild;
   	   			   loc_pointer = 2*loc_pointer +1;

   	   		   }else if(rightChild<leftChild and newTop>rightChild){

   	   			   //swap with right Child
   	   			   Type temp = heap_array[loc_pointer];
   	   			   heap_array[right_loc_pointer] = temp;
   	   			   heap_array[loc_pointer] = rightChild;
   	   			   loc_pointer = 2*loc_pointer +2;

   	   		   }
   	   		   newTop = heap_array[loc_pointer];
   	   		   left_loc_pointer = 2*loc_pointer +1;
   	   	   	   right_loc_pointer = 2*loc_pointer +2;
   	   	   	   leftChild = heap_array[left_loc_pointer];
   	   	   	   rightChild = heap_array[right_loc_pointer];

   		   }
   		   return min;
   	   }
    }
   void show(){
	   for(int i = 0;i<Size;i++){
		   std::cout<<heap_array[i]<<" ";
	   }
	   std::cout<<std::endl;
   }

};


#endif
