#include "ChainingHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	hashtable.resize(capacity);
	std::fill(hashtable.begin(), hashtable.end(), empty);
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	hashtable.clear();
	hashtable.shrink_to_fit();
}
bool ChainingHashTable::isfree(int index){
	return hashtable[index].empty();
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	// Call hash function to calculate hash ASCII key
	int index = hash(key);
	//std::cout<<"index: "<<index<< " key: "<< key <<std::endl;
	//std::cout<<"size: " <<size << std::endl;

	if(isfree(index)){
		//if the spot is empty
		std::pair<std::string,int> thing = std::make_pair(key,1);
		hashtable[index].push_back(thing);
		size ++;
	}else{
		//if the spot is filled
		std::vector<std::pair<std::string, int>>::iterator  it = hashtable[index].begin();
		int times = 0;
		while (it != hashtable[index].end() and it->first !=key){
			++it;
			times ++;
		}
		if (it == hashtable[index].end()){
			//key not exist
			std::pair<std::string,int> thing = std::make_pair(key,1);
			hashtable[index].push_back(thing);
			size++;
		}else{
			it->first = key;
			it->second += 1;
		}
	}
	// find hash key position then insert key and val
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int index = hash(key);
	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}else{
		std::vector<std::pair<std::string, int>>::iterator  it = hashtable[index].begin();
		while ((it != hashtable[index].end())and (it->first !=key))
			it++;

		if (it == hashtable[index].end())
			//key not exist
			throw std::runtime_error("key not exist error");
		else{

			int result = it->second;
			hashtable[index].erase(it);
			size--;
			return result;
		}
	}
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	int index = hash(key);

	if (isfree(index))
	{
		throw std::runtime_error("key not exist error");
	}
	else{
		std::vector<std::pair<std::string, int>>::iterator  it = hashtable[index].begin();
		while ((it != hashtable[index].end())and (it->first !=key))
			it++;
		if (it == hashtable[index].end()){
			//key not exist
			throw std::runtime_error("key not exist error");
		}else{
			return it->second;
		}
	}
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
//	for(int i = 143; i<143+5;i++){
//		for(std::pair<std::string,int> item : hashtable[i]){
//			std::cout<<"Index at "<<i<<" "<<item.first<<" "<<item.second<<std::endl;
//		}
//	}
	myfile.open(filename);
	for (std::vector<std::vector<std::pair<std::string, int>>>::iterator it = hashtable.begin();it != hashtable.end(); ++it){
		if(not (*it).empty()){
			for(std::pair<std::string,int> item : *it){
				myfile<<item.first<<" "<<item.second<<"\n";
			}
		}
	}
	myfile.close();
}
