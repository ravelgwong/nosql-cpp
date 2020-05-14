#include <iostream>
#include <fstream>
#include "bTree.hpp"
#include "json.hpp"
#include "model.hpp"

using std::cerr;
using std::cout;
using std::ifstream;
using json = nlohmann::json;
using std::endl;
using std::strtod;

int main()
{
    //BUILD FAILING

    // Btree<Customer> customerTree(100000);
    // Btree<Order> orderTree(100000);
    // ifstream inFile;

    // inFile.open("data.json");
    // if (!inFile)
    // {
    //     cerr << "Unable to open file";
    //     exit(1); // call system to stop
    // }
    // char x;
    // string result;
    // while (inFile >> x)
    // {
    //     result += x;
    // }
    // auto jsonData = json::parse(result);
    // for (int i{0}; i < jsonData["customers"].size(); i++)
    // {
    //     Customer c = Customer(
    //         jsonData["customers"][i]["firstname"],
    //         jsonData["customers"][i]["lastname"],
    //         jsonData["customers"][i]["email"],
    //         jsonData["customers"][i]["money"]);
    //     customerTree.insert(c);
    // }
    // for (int i{0}; i < jsonData["customers"].size(); i++)
    // {
    //     Order c = Order(
    //         jsonData["orders"][i]["email"],
    //         jsonData["orders"][i]["price"],
    //         new string[2]{
    //             jsonData["orders"][i]["food"][0], jsonData["orders"][i]["food"][1]},
    //         jsonData["orders"][i]["status"]);
    //     orderTree.insert(c);
    // }

    return 0;
}