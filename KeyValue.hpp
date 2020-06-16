#pragma once
#include <string>
/*
Keyvalue class,
a class that contains single document(key,value) of key value nosql database
*/
class KeyValue{
public:
	std::string name;
	std::string value;
	KeyValue(std::string name, std::string value) :name(name), value(value) {}
	// Return the current document data as string
	std::string toString() {
		return "'" + name + "':'" + value + "'";
	}
};