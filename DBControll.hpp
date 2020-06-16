#pragma once
#include "HashTable.hpp"
#include <string>
/*
DbControll
The class that abstract the database usage.
*/
class DBControll {
private:
	HashTable db;
	std::string notFound{ "{'error':'data not found'}" };
public:

	//Return a single collection class
	LinkedList* getCollection(std::string collection) {
		return this->db.getCollection(collection);
	}

	//return a single collection as string JSON
	std::string getCollectionString(std::string collection) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return this->notFound;
		return dataCollection->toString();
	}

	//return a single document as string JSON
	std::string getDocumentString(std::string collection, std::string document) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return this->notFound;
		std::string result{ dataCollection->get(document) };
		return result == "" ? this->notFound : result;
	}
//Update a single docuemnt, return false if it doesnt exits
	bool updateDocument(std::string collection, std::string document, std::string value) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->update(document, value);
	}
	//Add a new document
	bool addDocument(std::string collection, std::string document, std::string value) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->add(document, value);
	}
	//Add a new collection
	bool addCollection(std::string collectionName) {
		return this->db.createKey(collectionName);
	}
	//Delete a document
	bool deleteDocument(std::string collection, std::string document) {
		LinkedList* dataCollection{ getCollection(collection) };
		if (dataCollection == nullptr) return false;
		return dataCollection->deleteKey(document);
	}
	//delete a collecition
	bool deleteCollection(std::string collection) {
		return this->db.deleteKey(collection);
	}
	//return a status code according to the result of the operation
	std::string boolToStringWrapper(bool condition) {
		if (condition) {
			return "{'success':'operation is successful'}";
		}
		return this->notFound;
	}

};