#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"

// Linear probing hash table class
class ProbingHashTable : public HashTable {
    private:
    // TODO: insert additional variables here

	std::pair<std::string,int> empty = std::make_pair("",0);
	std::vector<std::pair<std::string, int>> hashtable;

    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    bool isfree(int index);
    void printAll(std::string filename);
};

#endif
