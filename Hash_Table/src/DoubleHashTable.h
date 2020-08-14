#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "HashTable.h"


// Double hashing hash table class
class DoubleHashTable : public HashTable {
    private:
    // helper functions
    int secondHash(std::string s);

    // TODO: insert additional variables here
    std::pair<std::string,int> empty = std::make_pair("",0);
    std::vector<std::pair<std::string, int>> hashtable;

    
    public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    bool isfree(int index);
    void printAll(std::string filename);
};

#endif
