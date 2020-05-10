#pragma once
#include <string>
#include <iostream>

using std::string;

template <class D>
class HashTable
{
private:
    const int capacity = 5000;
    int hash_function(string str)
    {
        int i = 0;
        for (int j = 0; str[j]; j++)
            i += str[j];
        return i % capacity;
    }
    D *data = new D[capacity];

public:
    void insert(D data)
    {
        std::cout << hash_function(data.getIdentifier()) << std::endl;
    }
};
