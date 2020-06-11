#pragma once
#include <string>

template <class D>
class KeyValue {
public:
	std::string name;
	D value;
	KeyValue(std::string name, D value) :name(name), value(value) {}
	std::string toString() {
		return "{'" + name + "':" + value.toString() + "}";
	}
};