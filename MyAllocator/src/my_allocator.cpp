/* 
    File: my_allocator.cpp

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the class MyAllocator.

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <cstdlib>
#include "my_allocator.hpp"
#include <assert.h>
#include <iostream>

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
/* FUNCTIONS FOR CLASS MyAllocator */
/*--------------------------------------------------------------------------*/

// find the biggest fibonnacci term of the given block_size
// num  -> sequence in : 1, 2, 3, 5, 8, 21, 34, 55
// term -> corrs order : 0, 1, 2, 3, 4,  5,  6, 7
int findfibonnacciterm(int block_size){
	bool found = false;
	int first_num = 1;
	int second_num = 2;
	int next_num;
	int fibonnaci_term = 0;
	if(block_size == first_num){
		return 0;
	}
	if(block_size == second_num){
		return 1;
	}
	while(!found){
		next_num = first_num + second_num;
		fibonnaci_term++;
		if(next_num > block_size){
			found = true;
		}
		first_num = second_num;
		second_num = next_num;
	}
	return fibonnaci_term;
}
int findfibonnaccinum(int term){
	int result = 0;
    if(term == 0)
    {
       return 1;
    }
    if(term == 1)
    {
       return 2;
    }
    int t1 = 1, t2 = 2;
    for (int i = 1; i < term; ++i)
    {
        // Prints the first two terms.
    	result = t1 + t2;
        t1 = t2;
        t2 = result;
    }
    return result;
}
void initFreeList(vector<FreeList>* ALL_free_list, void* start, int block_num,size_t _basic_block_size){
	// term means order in fibonnacci
	// size means data mem size
	// num means number of blocks
	void* temp_start = start;
	int ALL_free_list_term = findfibonnacciterm(block_num);// iteration times
	int remain_num = block_num;
	int temp_block_term = ALL_free_list_term;// current term of fibonnacci
	int temp_block_num = findfibonnaccinum(temp_block_term);// current data size of fib block
	for(int i = ALL_free_list_term;i >=0; i--){
		// push the biggest block at the front
		FreeList temp_list;

		if (remain_num > 0 and temp_block_term == i){
			SegmentHeader* header = new(temp_start) SegmentHeader(temp_block_num,true);
			temp_list.Add(header);
			remain_num -= temp_block_num;
			temp_start = (void*)((char*)temp_start + temp_block_num*_basic_block_size);
			temp_block_term = findfibonnacciterm(remain_num);
			temp_block_num = findfibonnaccinum(temp_block_term);
		}
		ALL_free_list->push_back(temp_list);
	}
	// make it ascended order
	reverse(ALL_free_list->begin(), ALL_free_list->end());
}

MyAllocator::MyAllocator(size_t _basic_block_size, size_t _size) {
  // We don't do anything yet...
	this->_basic_block_size = _basic_block_size;
	this->_size = _size;
	_num_block = _size/_basic_block_size; // total blocks of mem
	_remain_block = _num_block;
	start = std::malloc(this->_size); // allocate mem

	// Initialize free lists
	initFreeList(&ALL_free_list, start,_num_block, _basic_block_size);
}

MyAllocator::~MyAllocator() {
  // Same here...
}

Addr MyAllocator::Malloc(size_t _length) {

	int requestedblocknum =(_length + sizeof(SegmentHeader))/_basic_block_size + 1;
	int preferedterm = findfibonnacciterm(requestedblocknum);
	if ((requestedblocknum - findfibonnaccinum(preferedterm)) > 0){
		preferedterm ++;
	} // making sure given space is enough
	int vector_term = preferedterm;
	if(preferedterm >= ALL_free_list.size()){
		cout<< "Error: requested size too big. "<<endl;
		return nullptr;
	}
	int split1_num = 0, split2_num = 0;
	void* split1_pos; void* split2_pos;
	SegmentHeader* split1;SegmentHeader* split2;
	bool found = false;
	while (!found and (vector_term < ALL_free_list.size())){

		if(!ALL_free_list[preferedterm].isEmpty()){
			found = true;
		}else if(!ALL_free_list[vector_term].isEmpty() and vector_term >1){
			// remove fseg from free list
			// split big memory down to smaller memory
			// then reassigned
			SegmentHeader* temp = ALL_free_list[vector_term].Pop();

			split1_num = findfibonnaccinum(vector_term-1);
			split2_num = findfibonnaccinum(vector_term-2);
			split1_pos =(void*) (temp);
			split2_pos =(void*) (split1_pos + split1_num*_basic_block_size);
			split1 = new(split1_pos) SegmentHeader(split1_num,true);
			split2 = new(split2_pos) SegmentHeader(split2_num,true);
			ALL_free_list[vector_term-1].Add(split1);
			ALL_free_list[vector_term-2].Add(split2);
			vector_term = preferedterm;
		}else{
			vector_term++;
		}
	}
	if (!found ){
		cout <<"Error: no big enough space found."<<endl;
		return nullptr;
	}
	SegmentHeader* temp_result = ALL_free_list[preferedterm].Pop();
	if (temp_result == nullptr){
		cout<<"Error: no segment header is found in term: "<< preferedterm <<endl;
		return nullptr;
	}
	temp_result->is_free = false;

	void* result = (void*)((char*)temp_result+sizeof(SegmentHeader));
	//return to user from ALL_free_list[preferedterm]
	return result;
}

bool MyAllocator::Free(Addr _a) {
	// This empty implementation just uses C standard library free

  	// Check if given addr is valid
  	SegmentHeader* _s = nullptr;
  	int my_fibo_term = 0;
  	SegmentHeader* left_candidate = nullptr;
  	SegmentHeader* right_candidate = nullptr;
  	int left_fibo_term = 0;
  	int right_fibo_term = 0;
  	int left_fibo_num = 0;
  	int right_fibo_num = 0;
  	SegmentHeader* selected_candidate = nullptr;
	int selected_fibo_term = 0;
	int left_or_right = -1; // left is 0 and right is 1

	int uplevel_fibo_term = 0;
	SegmentHeader* temp_result = nullptr;
	int temp_num = 0;
	void* temp_pos = nullptr;
	// given addr _a is what we initially gave to user
	// Hence, we need to get back the length of SgH
  	_s = (SegmentHeader*) ((char*)_a-sizeof(SegmentHeader));
  	if(!_s->CheckValid()){
  		cout<<"Calculated addr is: "<<_s<<endl;
  		cout<<"Given addr is: "<<_a<<endl;
  	  	cout<<"Error: Given Addr is not valid SegmentHeader Addr."<<endl;
  	  	return false;
  	}
  	if(_s->is_free){
  		cout<<"Warning: the given block is already free."<<endl;
  		return true;
  	}
  	my_fibo_term = findfibonnacciterm(_s->length);
	int term = 0;
//	for(FreeList temp : ALL_free_list){
//		cout<< "TERM: "<< term<<endl;
//		temp.print();
//	}
	cout<< "----------START-------------"<<endl;
	cout<< "my_fibo_term: "<<my_fibo_term << " "<<_s<<endl;
  	do{
		// find buddy candidates
  		// prevent wrong linking
  	  	_s->next = nullptr;
  	  	_s->prev = nullptr;
  		_s->is_free = true;
		right_fibo_term = my_fibo_term-1;
		right_fibo_num = findfibonnaccinum(right_fibo_term);
		right_candidate = (SegmentHeader*)((void*)((char*)_s + _s->length*_basic_block_size));
		left_fibo_term = my_fibo_term+1;
		left_fibo_num = findfibonnaccinum(left_fibo_term);
		left_candidate = (SegmentHeader*)((char*)_s - left_fibo_num*_basic_block_size);

		if((char*)_s == (char*)start){// left base fibo term
			if(right_candidate->CheckValid()){
				if(right_candidate->is_free == true and right_candidate->length == left_fibo_num){
					selected_candidate = right_candidate;
					selected_fibo_term = right_fibo_num;
					left_or_right = 1;
				}
			}
			if(left_or_right == -1){
				selected_candidate = nullptr;
				uplevel_fibo_term = my_fibo_term;
			}
		}else if (my_fibo_term == 0){ // right base fibo term
			if(left_candidate->CheckValid()){
				if(left_candidate->is_free == true and left_candidate->length == left_fibo_num){
					selected_candidate = left_candidate;
					selected_fibo_term = left_fibo_term;
					left_or_right = 0;
				}
			}
			if(left_or_right == -1){
				selected_candidate = nullptr;
				uplevel_fibo_term = my_fibo_term;
			}
		}else{
		// Check if buddy candidates exist and valid

			if((int*)left_candidate >= (int*)start){
				if(left_candidate->CheckValid()){

					if (left_candidate->is_free == true and left_candidate->length == left_fibo_num){
						selected_candidate = left_candidate;
						selected_fibo_term = left_fibo_term;
						left_or_right = 0;
					}
				}
			}
			if((int*)right_candidate >= (int*)start and (int*)right_candidate <= ((int*)start +_size)){
			if(right_candidate->CheckValid()){
				if (right_candidate->is_free == true and right_candidate->length == right_fibo_num){

					selected_candidate = right_candidate;
					selected_fibo_term = right_fibo_term;
					left_or_right = 1;
					}
				}
			}

			if(left_or_right == -1){
				selected_candidate = nullptr;
				uplevel_fibo_term = my_fibo_term;
			}
		}

		// Remove selected buddy candidate from free list
	  	if (selected_candidate != nullptr){

	  		ALL_free_list[selected_fibo_term].Remove(selected_candidate);
	  		selected_candidate->is_free = false;

	  		if(left_or_right == 0){//left candidate selected to be merged
	  			uplevel_fibo_term = selected_fibo_term +1;
	  			temp_num = findfibonnaccinum(uplevel_fibo_term);
	  			temp_pos =(void*) (selected_candidate);
	  			temp_result = new(temp_pos) SegmentHeader(temp_num,true);
	  		}else{// right candidate selected to be merged
	  			uplevel_fibo_term = my_fibo_term +1;
	  			temp_num = findfibonnaccinum(uplevel_fibo_term);
	  			temp_pos =(void*) (_s);
	  			temp_result = new(temp_pos) SegmentHeader(temp_num,true);
	  		}
	  		_s = temp_result;
	  		my_fibo_term = findfibonnacciterm(_s->length);
	  		left_or_right = -1;

	  	}

  	}while(selected_candidate != nullptr and my_fibo_term < (ALL_free_list.size()-1));

	ALL_free_list[uplevel_fibo_term].Add(_s);

  return true;
}

