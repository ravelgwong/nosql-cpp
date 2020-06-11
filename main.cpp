#include "LinkedList.hpp"
#include "KeyValue.hpp"
#include "PlainData.hpp"
#include <iostream>
#include <string>

int main() {
	LinkedList<PlainData<float>> x;
	x.add(KeyValue<PlainData<float>>("avc",PlainData<float>(100.321312)));
	std::cout << x.toString() << std::endl;

	return 0;
}
