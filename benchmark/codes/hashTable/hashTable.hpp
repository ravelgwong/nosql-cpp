#pragma once
#include <string>
#include <iostream>

using std::string;

template <class E>
class LinkedList
{
private:
    class Node
    {
    public:
        Node *prev, *next;
        E data;
        Node(E data, Node *next = {nullptr}, Node *prev = {nullptr}) : data(data), next(next), prev(prev) {}
    };
    Node *head{nullptr}, *tail{nullptr};

public:
    LinkedList() {}
    void insert(E data)
    {
        if (head == nullptr)
        {
            this->head = new Node(data);
            this->tail = head;
            return;
        }
        Node *temp = new Node(data, nullptr, this->tail);
        this->tail->next = temp;
        this->tail = temp;
    }
};

template <class D>
class HashTable
{
private:
    const int capacity = 1000;
    int hash_function(string str)
    {
        int i = 0;
        for (int j = 0; str[j]; j++)
            i += str[j];
        return i % capacity;
    }
    LinkedList<D> *data = new LinkedList<D>[capacity];

public:
    void insert(D newData)
    {
        data[hash_function(newData.getIdentifier())].insert(newData);
    }
};
