#pragma once
#include "LinkedList.hpp"
#include <string>

class ListContainer {
private:
	class Node {
	public:
		std::string name;
		LinkedList* collection{ new LinkedList };
		Node* next;
		Node(std::string name, Node* next = { nullptr }) : name(name), next(next) {}
	};
	Node* head{ nullptr }, * tail{ nullptr };
public:
	LinkedList* getCollection(std::string name) {
		Node* temp = this->head;
		while (temp != nullptr) {
			if (temp->name == name) return (temp->collection);
			temp = temp->next;
		}
		return nullptr;
	}

	bool add(std::string name) {
		if (getCollection(name)!=nullptr) return false;
		if (this->head == nullptr && this->tail == nullptr) {
			this->head = new Node(name);
			this->tail = this->head;
		}
		else {
			Node* temp{ new Node(name) };
			this->tail->next = temp;
			this->tail = temp;
		}
		return true;
	}

	bool deleteCollection(std::string name) {
		Node* temp = this->head;
		Node* temp2 = this->head->next;
		if (temp != nullptr && temp2 == nullptr) {
			if (temp->name == name) {
				this->head = nullptr;
				this->tail = nullptr;
				delete temp;
				return true;
			}
			return false;
		}
		if (temp == nullptr && temp2 == nullptr) {
			return false;
		}
		while (temp2 != nullptr) {
			if (temp2->name == name) {
				if (temp2 == this->tail) {
					temp->next = nullptr;
					this->tail = temp;
					delete temp2;
					return true;
				}
				temp->next = temp2->next;
				delete temp2;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		return false;
	}

	~ListContainer() {
		Node* temp = this->head;
		while (temp != nullptr) {
			Node* temp2 = temp;
			temp = temp->next;
			delete temp2->collection;
			delete temp2;
		}
	}

};