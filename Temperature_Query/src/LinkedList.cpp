#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include <sstream>
using namespace std;

LinkedList::LinkedList() {
	head =nullptr;
	tail =nullptr;
	// Implement this function
}

LinkedList::~LinkedList() {
	LinkedList::clear();
	// Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	if (this != &source){
			//  delete the elements of our linked list (can call clear())
		    clear();
			if (source.head==nullptr)//rhs is empty
			{
				this->head = nullptr;
				this->tail = head;
			}
		    if (source.head == source.tail){
			 	// rhs.tail has the same value as rhs.head
		        //assign head a new Node initialized with (rhs.head)->value
		    	this->head = new Node(source.head->data.id,source.head->data.year,source.head->data.month,source.head->data.temperature);
		    	this->tail = this->head;
		        // assign tail the address value stored in head (tail = head)
		    }
			else{
		    // create a new Node* curr_rhs and initialize to rhs.head
		    // assign head a new Node(curr_rhs->value)
		    // assign curr_rhs with curr_rhs->next
		    // create a new Node* curr_lhs and initialize to head
			Node * curr_rhs = source.head;
		    this->head = new Node(source.head->data.id,source.head->data.year,source.head->data.month,source.head->data.temperature);
		    curr_rhs = curr_rhs->next;
		    Node * curr_lhs = head;
		     while (curr_rhs != nullptr){
		      // assign curr_lhs->next a new Node(curr_rhs->value)
		    	 curr_lhs->next = new Node(curr_rhs->data.id,curr_rhs->data.year,curr_rhs->data.month,curr_rhs->data.temperature);
		         this->tail = curr_lhs->next;
		         curr_rhs = curr_rhs->next;
		         curr_lhs = curr_lhs->next;
		     	 }
			}
		}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (this != &source){
		//  delete the elements of our linked list (can call clear())
	    clear();
		if (source.head==nullptr)//rhs is empty
		{
			return *this;
		}
	    if (source.head == source.tail){
		 	// rhs.tail has the same value as rhs.head
	        //assign head a new Node initialized with (rhs.head)->value
	    	this->head = new Node(source.head->data.id,source.head->data.year,source.head->data.month,source.head->data.temperature);
	    	this->tail = this->head;
	        // assign tail the address value stored in head (tail = head)
	        return *this;
	    }
		else{
	    // create a new Node* curr_rhs and initialize to rhs.head
	    // assign head a new Node(curr_rhs->value)
	    // assign curr_rhs with curr_rhs->next
	    // create a new Node* curr_lhs and initialize to head
		Node * curr_rhs = source.head;
	    this->head = new Node(source.head->data.id,source.head->data.year,source.head->data.month,source.head->data.temperature);
	    curr_rhs = curr_rhs->next;
	    Node * curr_lhs = head;
	     while (curr_rhs != nullptr){
	      // assign curr_lhs->next a new Node(curr_rhs->value)
	    	 curr_lhs->next = new Node(curr_rhs->data.id,curr_rhs->data.year,curr_rhs->data.month,curr_rhs->data.temperature);
	         this->tail = curr_lhs->next;
	         curr_rhs = curr_rhs->next;
	         curr_lhs = curr_lhs->next;
	     	 }
		}
	    return *this;
	}
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	Node* curr = new Node(location,year,month,temperature);
	if(head == nullptr){
		head = curr;
		tail = head;
	}else if(head == tail){
		if(head->data < curr->data){
			head->next = curr;
			tail = curr;
		}else{
			curr->next = head;
			tail = head;
			head = curr;
		}
	}
	else{
		Node* count = head;
		while(count->next != nullptr and count->next->data<curr->data){
			count = count->next;
		}
		Node* old = count->next;
		count->next = curr;
		curr->next = old;
	}
	//current
	// Implement this function
}

void LinkedList::clear() {
	// Implement this function
	Node* current = head;
	while (current != nullptr) {
	       Node* deleteNode = current;
	        current = current->next;
	        delete deleteNode;
	}
    head = nullptr;
    tail = nullptr;
}

Node* LinkedList::getHead() const {
	if(head == nullptr)
		return nullptr;
	else
		return head;
	// Implement this function it will be used to help grade other functions
}

string LinkedList::print() const {
	string outputString="";
	Node* curr = head;
	if(curr == nullptr){
		outputString = "Nothing";
	}
	else{
		do{
			outputString = outputString + curr->data.id+" ";
			outputString = outputString + to_string(curr->data.year)+" ";
			outputString = outputString + to_string(curr->data.month)+" ";
			stringstream ss;
			ss << curr->data.temperature;
			string temperature = ss.str();
			outputString = outputString + temperature+"\n";
			curr = curr->next;
		} while(curr !=nullptr);
	}
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
