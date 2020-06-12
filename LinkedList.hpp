#pragma once
#include<string>
#include<iostream>
#include "KeyValue.hpp"

class LinkedList {
private:
	class Node {
	public:
		KeyValue data;
		Node* next;
		Node(KeyValue data, Node* next = nullptr) : data(data), next(next) {}
	};
	Node* head{ nullptr }, * tail{ nullptr };
	bool checkExists(std::string name) {
		if (head == nullptr) return false;
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data.name == name) return true;
			temp = temp->next;
		}
		return false;
	}
public:
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
	std::string get(std::string name) {
		Node* temp = this->head;
		while (temp != nullptr) {
			if (temp->data.name == name) return temp->data.toString();
			temp = temp->next;
		}
		return "";
	}
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
	std::string toString() {
		Node* temp = head;
		std::string result{ "{\n" };
		while (temp != nullptr) {
			result += temp->data.toString();
			result += ",\n";
			temp = temp->next;
		}
		result += "}";
		return result;
	}

};