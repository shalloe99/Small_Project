/*
 * Stack
 *
 *  Created on: Sep 23, 2019
 *      Author: zshaw
 */


#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H
#include <iostream>
using namespace std;

template <class Type>
class AbstractStack
{
private:
    // data goes here

public:
   AbstractStack(void) {}
   ~AbstractStack(void) {}

   bool isEmpty(void) {return true;}

   int size(void) {return 1;}

   Type top();// throw(exception) {}

   Type pop(); //throw(exception) {}

   void push ( Type e ) { }
};

template <class Type>
class ArrayStack: public AbstractStack <Type>{
private:
	int increased_constant = 100;
	int SIZE = 0;
	int capacity = 1;
	Type* arraystack;
	Type TOP;
public:
	ArrayStack(void): AbstractStack<Type>(){
		arraystack = new Type[capacity];
	}
	~ArrayStack(void){
		delete[] arraystack;
	}

	bool isEmpty(void) {
		if (SIZE == 0){
			return true;
		}
		else return false;
	}
	int size(void) {return SIZE;}

	Type top(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}
		return TOP;
	}

	Type pop(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}else{
			Type temp = TOP;
			SIZE--;
			TOP = arraystack[SIZE];
			return temp;
		}
	}

	void push ( Type e ) {
		if(SIZE <= capacity){
		 // inside capacity
			arraystack[SIZE] = e;
			SIZE++;
		}else{
		 // break the capacity
			capacity += increased_constant;
			Type* newarraystack = new Type[capacity];
			for(int i = 0;i <SIZE;i++){
				newarraystack[i] = arraystack[i];
			}
			newarraystack[SIZE] = e;
			delete [] arraystack;
			arraystack = newarraystack;
			SIZE++;
		}
		TOP = e;
	}

};


template <class Type>
class DoubleArrayStack: public AbstractStack <Type>{
private:
	int SIZE = 0;
	int capacity = 1;
	Type* doublearraystack;
	Type TOP;
public:
	DoubleArrayStack(void): AbstractStack<Type>(){
		doublearraystack = new Type[capacity];
	}
	~DoubleArrayStack(void){
		delete[] doublearraystack;
	}

	bool isEmpty(void) {
		if (SIZE == 0){
			return true;
		}
		else return false;
	}
	int size(void) {return SIZE;}

	Type top(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}
		return TOP;
	}

	Type pop(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}else{
			Type temp = TOP;
			SIZE--;
			TOP = doublearraystack[SIZE];
			return temp;
		}
	}
	void push ( Type e ) {
		if(SIZE <= capacity){
		 // inside capacity
			doublearraystack[SIZE] = e;
			SIZE++;
		}else{
		 // break the capacity
			capacity *= 2;
			Type* newarraystack = new Type[capacity];
			for(int i = 0;i <SIZE;i++){
				newarraystack[i] = doublearraystack[i];
			}
			newarraystack[SIZE] = e;
			delete [] doublearraystack;
			doublearraystack = newarraystack;
			SIZE++;
		}
		TOP = e;
	}
};


// support node class for LinkedList
template<class Type>
struct Node{
	Node* next;
	Type value;
	Node(Type value):value(value), next(nullptr){}
    Node() : value(0), next(nullptr) {}
};

template <class Type>
class LinkedList: public AbstractStack <Type>{
private:
	Node<Type>* head;
	Node<Type>* tail;
	int SIZE = 0;
public:
	LinkedList(void): AbstractStack<Type>(){
		head = nullptr;
		tail = nullptr;
	}
	~LinkedList(void){
		clear();
	}
	void clear(){
		Node<Type>* currentNode = head;
		while (currentNode != nullptr) {
		     Node<Type>* deleteNode = currentNode;
		     currentNode = currentNode->next;
		     delete deleteNode;
		}
		head = nullptr;
		tail = nullptr;
	}
	bool isEmpty(void) {
		 if (head == nullptr && tail == nullptr)
			 return true;
		 return false;
	}
	int size(void) {return SIZE;}
	Type top(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}
		return tail->value;
	}
	Type pop(){
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}else{// Go through the linked list
			Type temp = top();
			Node<Type>* moveNode = head;
			if (SIZE ==0){
				return temp;
			}else if (SIZE ==1){
				head = nullptr; tail = nullptr;
				SIZE--;
				return temp;
			}else{
			for(int i = 0;i<SIZE-2;i++){
				moveNode = moveNode->next;
				}
			tail = moveNode;
			SIZE--;
			}
			return temp;
		}
	}
	void push (Type e ) {
		Node<Type>* currentNode = new Node<Type>(e);
		if (isEmpty()) {
			head = currentNode; tail = currentNode;
		} else {
			tail->next = currentNode;
			tail = currentNode;
		}
		SIZE++;
	//	show();
	}

	void show(){ // helper methods
	    Node<Type>* cur = head;
	    if (head != nullptr) {
	        while (cur != nullptr) {
	            cout << cur->value;
	            if (cur != tail)
	                cout << " ";
	            if (cur == tail)
	                cout << endl;
	            cur = cur->next;
	        }
	    }
	}
};
#endif
