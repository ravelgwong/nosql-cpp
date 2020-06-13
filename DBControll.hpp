#pragma once
#include "HashTable.hpp"
#include <string>

class DBControll {
private:
	HashTable db;
	std::string notFound{ "{'error':'data not found'}" };
public:

	LinkedList* getCollection(std::string collection) {
		return this->db.getCollection(collection);
	}

	std::string getCollectionString(std::string collection) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return this->notFound;
		return dataCollection->toString();
	}

	std::string getDocumentString(std::string collection, std::string document) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return this->notFound;
		std::string result{ dataCollection->get(document) };
		return result == "" ? this->notFound : result;
	}

	bool updateDocument(std::string collection, std::string document, std::string value) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->update(document, value);
	}

	bool addDocument(std::string collection, std::string document, std::string value) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->add(document, value);
	}
	
	bool addCollection(std::string collectionName) {
		return this->db.createKey(collectionName);
	}

	bool deleteDocument(std::string collection, std::string document) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->deleteKey(document);
	}

	bool deleteCollection(std::string collection) {
		return this->db.deleteKey(collection);
	}

	std::string boolToStringWrapper(bool condition) {
		if (condition) {
			return "{'success':'operation is successful'}";
		}
		return this->notFound;
	}

};