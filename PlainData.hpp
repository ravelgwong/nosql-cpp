#pragma once
#include <string>
template <class D>
class PlainData {
public:
	D data;
	PlainData(D data) :data(data) {}
	std::string toString() {
		return std::to_string(data);
	}
};