#include <iostream>
#include <fstream>
#include "bTree.hpp"
#include "json.hpp"
#include "model.hpp"
#include "map.hpp"
using std::cerr;
using std::cout;
using std::ifstream;
using json = nlohmann::json;
using std::endl;
using std::strtod;

int main()
{
	
	btree::map<string,Customer> CustomerMap;
    btree::map<string,Order> OrderMap;
    ifstream inFile;
	
    inFile.open("data.json");
    if (!inFile)
    {
        cerr << "Unable to open file";
        exit(1); // call system to stop
    }
    char x;
    string result;
    while (inFile >> x)
    {
        result += x;
    }
    auto jsonData = json::parse(result);
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Customer c = Customer(
            jsonData["customers"][i]["firstname"],
            jsonData["customers"][i]["lastname"],
            jsonData["customers"][i]["email"],
            jsonData["customers"][i]["money"]);
		CustomerMap.insert ( std::pair<string,Customer>(c.getIdentifier(),c) );
		
        
    }
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Order c = Order(
            jsonData["orders"][i]["email"],
            jsonData["orders"][i]["price"],
            new string[2]{
                jsonData["orders"][i]["food"][0], jsonData["orders"][i]["food"][1]},
            jsonData["orders"][i]["status"]);
        OrderMap.insert ( std::pair<string,Order>(c.getIdentifier(),c) );
    }

    return 0;

    return 0;
}