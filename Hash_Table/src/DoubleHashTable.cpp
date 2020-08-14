#include "DoubleHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {
	hashtable.resize(capacity);
	std::fill(hashtable.begin(), hashtable.end(), empty);
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	hashtable.clear();
	hashtable.shrink_to_fit();
}

bool DoubleHashTable::isfree(int index){
	return (hashtable[index].first=="" and hashtable[index].second==0);
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
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
			hashtable[index].second ++;
			size++;
		}
		else{
			// if not find next spot
			int second_hash = secondHash(key);
			while (!isfree(index) and !(hashtable[index].first ==key)){
				index += second_hash;
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
int DoubleHashTable::remove(std::string key) {
	int index = hash(key);
	int second_hash = secondHash(key);

	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}
	else{
		int temp_size = 0;
		while ((not isfree(index))and(hashtable[index].first !=key) and (temp_size<=capacity)){
			index += second_hash;
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
int DoubleHashTable::get(std::string key) {
	int index = hash(key);
	int second_hash = secondHash(key);
	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}
	else{
		int temp_size = 0;
		while ((not isfree(index))and(hashtable[index].first !=key) and (temp_size<=capacity)){
			index += second_hash;
			index = index % capacity;
			temp_size ++;
		}
		if ((temp_size == capacity) or isfree(index)){
			throw std::runtime_error("key not exist error");
		}
		int result = hashtable[index].second;
		return result;
	}
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
//	for(int i = 143; i<143+5;i++){
//		std::cout<<"index at: "<<i<<" is "<<hashtable[i].first<<" "<<hashtable[i].second<<std::endl;
//	}
	myfile.open(filename);
	for (std::vector<std::pair<std::string, int>>::iterator it = hashtable.begin();it != hashtable.end(); ++it){
		 if (it->second != 0){
			 myfile << it->first<<" "<<it->second<<"\n";
		 }
	}
	myfile.close();
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {

	int hash = 0;
	int n = s.length();     //s is the given word
	for (int i = 0; i < n; i++) {
		hash = g*hash + int(s.at(i));
		//ASCII value of char at position i in the word
		//g is a positive constant chosen by you
	} // capacity is total memory size allocated for hash table
	return 13-hash%13;
}
