/* 
    File: free_list.cpp

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the class FreeList.

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include "free_list.hpp"
#include<assert.h>
/*--------------------------------------------------------------------------*/
/* NAME SPACES */ 
/*--------------------------------------------------------------------------*/

using namespace std;
/* I know, it's a bad habit, but this is a tiny program anyway... */

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR CLASS SegmentHeader */
/*--------------------------------------------------------------------------*/

SegmentHeader::SegmentHeader(size_t _length, bool _is_free) {
  length = _length;
  is_free = _is_free;
  cookie = COOKIE_VALUE;
  // You may need to initialize more members here!
  prev = nullptr;
  next = nullptr;

 // next = sizeof(SegmentHeader) + _length;
}

SegmentHeader::~SegmentHeader() {
  // You may need to add code here.

}


bool SegmentHeader::CheckValid() {
	try
	  {
		if (cookie != COOKIE_VALUE) {
//			cout << "INVALID SEGMENT HEADER!!"<<(void*)this << endl;
//			assert(false);
		 // You will need to check with the debugger to see how we got into this
		 // predicament.
		return false;
		}
	  }
	  catch (int e)
	  {
	    cout << "An exception occurred. Exception Nr. " << e << '\n';
	  }
	  return true;
}

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR CLASS FreeList */
/*--------------------------------------------------------------------------*/

FreeList::FreeList() {
  // You will need to add code here!
	head = nullptr;
	tail = nullptr;
	size = 0;
}

FreeList::~FreeList() {
  // You may need to add code here.
}

bool FreeList::Add(SegmentHeader * _segment) {

	if (head == nullptr){
		head = _segment;
		tail = head;
	}else{
		_segment->prev = nullptr;
		_segment->next = head;
		head->prev = _segment;
		head = _segment;
	}
	size++;
	return true;
}

bool FreeList::Remove(SegmentHeader * _segment) {
	SegmentHeader* temp = head;
	SegmentHeader* pre_temp;
	if (head == nullptr){// no element in list
//		cout <<"Error: no segment header in free list"<<endl;
		return true;
	}
	if (head==_segment){
		if (head->next != nullptr){
			_segment->is_free = false;
			head->next->prev = nullptr;
			head = head->next;
			size--;
			return true;
		}else{
			head = nullptr;
//			cout<<"List is empty now."<<endl;
			return true;
		}
	}else if(head!=_segment and head->next == nullptr){
		cout <<"Error: segment header is not found."<<endl;
		return false;
	}

	while(temp->next != nullptr and temp!=_segment){
		pre_temp = temp;
		temp = temp->next;
	}

	if(temp ==_segment){
		_segment->is_free = false;
		pre_temp->next = pre_temp->next->next;
		if(pre_temp->next!=nullptr){
			pre_temp->next->prev = pre_temp;
		}else{
			tail = pre_temp;
		}
		return true;
	}else{
		cout <<"Error: segment header is not found."<<endl;
		return false;
	}
}
SegmentHeader* FreeList::Pop(){
	if(head == nullptr){
		return nullptr;
	}else{
		SegmentHeader* temp = head;
		head = head ->next;
		return temp;
	}
}
void FreeList::print(){
	if(head==nullptr){
		cout<<"Empty free list"<<endl;
	}else{
		SegmentHeader* temp = head;
		while(temp!=nullptr){
			cout<<"location: "<<temp<<" length: "<< temp->length << endl;
			temp = temp->next;
		}
	}
}


bool FreeList::isEmpty(){
	return (head==nullptr);
}

