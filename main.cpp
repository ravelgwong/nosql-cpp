#include "DBControll.hpp"
#include <iostream>
#include <string>


int main() {
	DBControll x;
	x.addCollection("hello");
	x.addDocument("hello", "index", "10");
	x.addDocument("hello", "inde1x", "20");
	x.addDocument("hello", "indef1x", "20");
	x.addCollection("helli");
	x.addDocument("helli", "index", "231");
	x.updateDocument("hello", "index", "20");
	x.deleteDocument("hello", "index");

	std::cout << x.getCollectionString("hello") << std::endl;
	std::cout << x.getCollectionString("helli") << std::endl;
	return 0;
}
