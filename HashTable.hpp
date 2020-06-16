#pragma once
#include <string>
#include "ListContainer.hpp"
#include "LinkedList.hpp"
/*
Hashtable,
the main engine of the database,
stores all the collection with open addressing.
*/
class HashTable
{
private:
    //Create a new hashtable with capacity of 2000
    const int capacity{ 2000 };
    //Hash function of the hashtable convert the key to int value.
    int hashFn(std::string str)
    {
        int i = 0;
        for (int j{ 0 }; str[j]; j++)
            i += str[j];
        return i % capacity;
    }
    ListContainer* data{ new ListContainer[capacity] };

public:
    //Create a new collection(not overwrite)
    bool createKey(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].add(name);
    }
    //Remove a collection
    bool deleteKey(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].deleteCollection(name);
    }
    // Return a single collection
    LinkedList* getCollection(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].getCollection(name);
    }
};
