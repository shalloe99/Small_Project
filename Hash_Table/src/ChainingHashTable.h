#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"


// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
    // TODO: insert additional variables needed here
	std::vector<std::pair<std::string, int>> empty;
	std::vector<std::vector<std::pair<std::string, int>>> hashtable;

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
    bool isfree(int index);
    void printAll(std::string filename);
};

#endif
