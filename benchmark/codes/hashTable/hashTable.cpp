#include <iostream>
#include <fstream>
// #include "hashTable.hpp"
#include "model.hpp"
#include "json.hpp"
#include "sparsepp/spp.h"

using std::cerr;
using std::cout;
using std::ifstream;
using json = nlohmann::json;
using std::endl;
using std::strtod;
/*
------------------------------------------------------------------------------
    Read data from json file then insert it to hashtable then redelete it.
------------------------------------------------------------------------------
*/
namespace std
{
    // inject specialization of std::hash for Person into namespace std
    // ----------------------------------------------------------------
    template <>
    struct hash<Customer>
    {
        std::size_t operator()(Customer const &p) const
        {
            std::size_t seed = 0;
            spp::hash_combine(seed, p.firstName);
            spp::hash_combine(seed, p.lastName);
            return seed;
        }
    };
    template <>
    struct hash<Order>
    {
        std::size_t operator()(Order const &p) const
        {
            std::size_t seed = 0;
            spp::hash_combine(seed, p.email);
            return seed;
        }
    };
} // namespace std

int main()
{
    // HashTable<Customer> customerTable;
    // HashTable<Order> orderTable;

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
    spp::sparse_hash_set<Customer> customerTable;

    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Customer c = Customer(
            jsonData["customers"][i]["firstname"],
            jsonData["customers"][i]["lastname"],
            jsonData["customers"][i]["email"],
            jsonData["customers"][i]["money"]);
        customerTable.insert(c);
    }
    cout << customerTable.size() << endl;
    spp::sparse_hash_set<Order> orderTable;
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Order c = Order(
            jsonData["orders"][i]["email"],
            jsonData["orders"][i]["price"],
            new string[2]{
                jsonData["orders"][i]["food"][0], jsonData["orders"][i]["food"][1]},
            jsonData["orders"][i]["status"]);
        orderTable.insert(c);
    }
    cout << orderTable.size() << endl;
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Customer c = Customer(
            jsonData["customers"][i]["firstname"],
            jsonData["customers"][i]["lastname"],
            jsonData["customers"][i]["email"],
            jsonData["customers"][i]["money"]);
        customerTable.erase(c);
    }
    cout << customerTable.size() << endl;
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Order c = Order(
            jsonData["orders"][i]["email"],
            jsonData["orders"][i]["price"],
            new string[2]{
                jsonData["orders"][i]["food"][0], jsonData["orders"][i]["food"][1]},
            jsonData["orders"][i]["status"]);
        orderTable.erase(c);
    }
    cout << orderTable.size() << endl;
    return 0;
}