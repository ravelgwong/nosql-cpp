#pragma once
#include<string>
#include "KeyValue.hpp"

template <class D>
class LinkedList {
private:
	class Node {
	public:
		KeyValue<D> data;
		Node* next;
		Node(KeyValue<D> data, Node* next = nullptr) : data(data), next(next) {}
	};
	Node* head{ nullptr }, * tail{ nullptr };
public:
	void add(KeyValue<D> data) {
		if (this->head == nullptr && this->tail == nullptr) {
			this->head = new Node(data);
			this->tail = this->head;
		}
		else {
			Node* temp{ new Node(data) };
			this->tail->next = temp;
			this->tail = temp;
		}
	}
	std::string toString() {
		Node* temp = head;
		std::string result{ "" };
		while (temp != nullptr) {
			result += temp->data.toString();
			result += "\n";
			temp = temp->next;
		}
		return result;
	}
};