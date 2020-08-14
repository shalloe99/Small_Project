/*
 * Deque.h
 *
 *  Created on: Oct 2, 2019
 *      Author: zshaw
 */

#include "Node.h"
#include <assert.h>

template <class Type>
class Deque {
private:
    int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque() {
		firstNode = nullptr;
		lastNode = nullptr;
		s = 0;
	}
	~Deque() {
		clear();
	}
	void clear(){
		Node<Type>* point = firstNode;
		Node<Type>* nextPoint = firstNode;
		while(point != nullptr){
			 nextPoint = nextPoint->getNext();
			 delete point;
			 point = nextPoint;
		}
	}
	void show(){
		std::cout<<"Current Queue: ";
		Node<Type>* cur = firstNode;
		    if (firstNode != nullptr) {
		        while (cur != nullptr) {
		            std::cout << cur->getData();
		            if (cur != lastNode)
		            	std::cout << " ";
		            if (cur == lastNode)
		            	std::cout << std::endl;
		            cur = cur->getNext();
		        }
		    }
		    else {
		        std::cout << "<Empty List>" << " ";

		   }
		   showData(firstNode);
		   showData(lastNode);
	}

	bool isEmpty() {
		if (firstNode == nullptr && lastNode == nullptr)
			return true;
		return false;
	}

	int size() {
		return s;
	}

	Type first() {
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}
		return firstNode->getData();
	}

	Type last() {
		if (isEmpty()){
			throw std::runtime_error("My error message.");
		}
		return lastNode->getData();
	}

	void insertFirst(Type o) {
        if(isEmpty()){
        	Node<Type>* new_Node = new Node<Type>(o);
        	firstNode = new_Node;
        	lastNode = new_Node;
        }else{
        	Node<Type>* new_Node = new Node<Type>(o,firstNode,nullptr);
        	firstNode->setPrev(new_Node);
        	firstNode = new_Node;
        }
        s++;
	}

	void insertLast(Type o) {
		if(isEmpty()){
		     Node<Type>* new_Node = new Node<Type>(o);
		     firstNode = new_Node;
		     lastNode = new_Node;
	    }else{
	         Node<Type>* new_Node = new Node<Type>(o,nullptr,lastNode);
		     lastNode->setNext(new_Node);
		     lastNode = new_Node;
	    }
		s++;
	}

	Type removeFirst() {
		if(isEmpty()){
			 throw std::runtime_error("My error message.");
		}else{
			Type removed_value = first();
			if(s ==1){
			//	std::cout<<"activated"<<std::endl;
				delete lastNode,firstNode;
				lastNode = nullptr, firstNode = nullptr;
			}else{
				 Node<Type>* new_first = firstNode->getNext();
				 new_first->setPrev(nullptr);
				 firstNode = new_first;
			}
			 s--;
			 return removed_value;
		}
	}
	void showData(Node<Type>* node){
		std::cout<<"Prev: "<<(node->getPrev()==nullptr)<<std::endl;
		std::cout<<"Current: "<<node->getData()<<std::endl;
		std::cout<<"Next: "<<(node->getNext()==nullptr)<<std::endl;
	}
	Type removeLast() {
		if(isEmpty()){
		throw std::runtime_error("My error message.");
		}else{
			Type removed_value = last();
			if(s ==1){
				//std::cout<<"activated"<<std::endl;
				delete lastNode,firstNode;
				lastNode = nullptr, firstNode = nullptr;
			}else{
			   Node<Type>* new_last = lastNode->getPrev();
			   delete lastNode;
			   lastNode = new_last;
			   lastNode->setNext(nullptr);
			}
		   s--;
		   return removed_value;
		}
	}
};

