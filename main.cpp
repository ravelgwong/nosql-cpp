#include "LinkedList.hpp"
#include "KeyValue.hpp"
#include <iostream>
#include <string>

int main() {
	LinkedList c;
	std::cout<<c.add("ravel", "fdsa")<<std::endl;
	std::cout << c.add("gogo", "fdsf") << std::endl;
	std::cout << c.get("ravel") << std::endl;
	std::cout << c.deleteKey("rx") << std::endl;
	std::cout << c.toString() << std::endl;
	return 0;
}
