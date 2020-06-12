#pragma once
#include <string>

class KeyValue{
public:
	std::string name;
	std::string value;
	KeyValue(std::string name, std::string value) :name(name), value(value) {}
	std::string toString() {
		return "'" + name + "':'" + value + "'";
	}
};