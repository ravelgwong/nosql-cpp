#pragma once
#include<string>
#include<iostream>
#include "KeyValue.hpp"

/*
A Single collection which contains a keyvalue class
*/
class LinkedList {
private:
	class Node {
	public:
		KeyValue data;
		Node* next;
		Node(KeyValue data, Node* next = nullptr) : data(data), next(next) {}
	};
	Node* head{ nullptr }, * tail{ nullptr };

public:
//Check if certain key exists
	bool checkExists(std::string name) {
		if (this->head == nullptr) return false;
		Node* temp = this->head;
		while (temp != nullptr) {
			if (temp->data.name == name) return true;
			temp = temp->next;
		}
		return false;
	}
	//Add a new key (not overwriting)
	bool add(std::string name,std::string value) {
		if (checkExists(name)) return false;
		KeyValue data(name, value);
		if (this->head == nullptr && this->tail == nullptr) {
			this->head = new Node(data);
			this->tail = this->head;
		}
		else {
			Node* temp{ new Node(data) };
			this->tail->next = temp;
			this->tail = temp;
		}
		return true;
	}
	//Get a single key
	std::string get(std::string name) {
		Node* temp = this->head;
		while (temp != nullptr) {
			if (temp->data.name == name) return "{\n" 
				+ temp->data.toString() + "\n}";
			temp = temp->next;
		}
		return "";
	}
	//Update a new key
	bool update(std::string name,std::string value) {
		Node* temp = this->head;
		while (temp != nullptr) {
			if (temp->data.name == name) {
				temp->data.value = value;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	//Delete a key inside the collection
	bool deleteKey(std::string name) {
		Node* temp = this->head;
		Node* temp2 = this->head->next;
		if (temp != nullptr && temp2 == nullptr) {
			if (temp->data.name == name) {
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
			if (temp2->data.name == name) {
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
	// Return all items inside the colleciton as JSON
	std::string toString() {
		Node* temp = this->head;
		std::string result{ "{\n" };
		while (temp != nullptr) {
			result += temp->data.toString();
			result += ",\n";
			temp = temp->next;
		}
		result += "}";
		return result;
	}
	~LinkedList() {
		// Clear all memory usage on the heap
		Node* temp = this->head;
		while (temp != nullptr) {
			Node* temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
	}
};