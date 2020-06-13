#pragma once
#include <string>
#include "ListContainer.hpp"
#include "LinkedList.hpp"

class HashTable
{
private:
    const int capacity{ 2000 };
    int hashFn(std::string str)
    {
        int i = 0;
        for (int j{ 0 }; str[j]; j++)
            i += str[j];
        return i % capacity;
    }
    ListContainer* data{ new ListContainer[capacity] };

public:
    bool createKey(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].add(name);
    }

    bool deleteKey(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].deleteCollection(name);
    }

    LinkedList* getCollection(std::string name) {
        int hash = this->hashFn(name);
        return data[hash].getCollection(name);
    }
};
