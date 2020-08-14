#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() {

}

// destructor
HashTable::~HashTable() {

}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {

	int hash = 0;
	int n = s.length();     //s is the given word
	for (int i = 0; i < n; i++) {
		hash = g * hash + int(s.at(i));
		//ASCII value of char at position i in the word
		//g is a positive constant chosen by you
	}
	return hash % capacity; // capacity is total memory size allocated for hash table
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	if (size==0)
		return false;
	return true;
}
