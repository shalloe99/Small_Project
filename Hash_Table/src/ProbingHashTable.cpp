#include "ProbingHashTable.h"
#include <fstream>
// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	hashtable.resize(capacity);
	std::fill(hashtable.begin(), hashtable.end(), empty);
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	hashtable.clear();
	hashtable.shrink_to_fit();
}
bool ProbingHashTable::isfree(int index){
	return (hashtable[index].first=="" and hashtable[index].second==0);
}
// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	int index = hash(key);
	//std::cout<<"index: "<<index<< " key: "<< key <<std::endl;
	//std::cout<<"size: " <<size << std::endl;

	if (size >= capacity){
		throw std::runtime_error("reach space limits");
	}else{

		// add element into hash table
		if (isfree(index))
		{
			// if nothing on index
			hashtable[index].first = key;
			hashtable[index].second += 1;
			size++;
		}
		else{
			// if not find next spot
			while (!isfree(index) and !(hashtable[index].first ==key)){
				index++;
				index = index % capacity;
			}
			if(isfree(index))
				size++;
			hashtable[index].first = key;
			hashtable[index].second += 1;
		}
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int index = hash(key);

	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}
	else{
		int temp_size = 0;
		while ((not isfree(index))and(hashtable[index].first !=key) and (temp_size<=capacity)){
			index++;
			index = index % capacity;
			temp_size ++;
		}
		if ((temp_size == capacity) or isfree(index)){
			throw std::runtime_error("key not exist error");
		}
		int result = hashtable[index].second;
		hashtable[index].first = "";
		hashtable[index].second = 0;
		size--;
		return result;
	}
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {
	int index = hash(key);

	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}
	else{
		int temp_size = 0;
		while ((not isfree(index))and(hashtable[index].first !=key) and (temp_size<=capacity)){
			index++;
			index = index % capacity;
			temp_size ++;
		}
		if ((temp_size == size) or isfree(index)){
			throw std::runtime_error("key not exist error");
		}
		int result = hashtable[index].second;
		return result;
	}
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
//	test loop
//	for(int i = 143; i<143+5;i++){
//		std::cout<<hashtable[i].first<<" "<<hashtable[i].second<<std::endl;
//	}
	myfile.open(filename);
	for (std::vector<std::pair<std::string, int>>::iterator it = hashtable.begin();it != hashtable.end(); ++it){
		if (it->second != 0){
			 //std::cout<<it->first<<" "<<it->second<<std::endl;
			 myfile << it->first<<" "<<it->second<<"\n";
		 }
	}
	myfile.close();
}
