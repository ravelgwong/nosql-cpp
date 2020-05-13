#include <stdio.h>
#include <iostream>
<<<<<<< HEAD
#include "bTree.hpp"
#include "json.hpp"
int main() {
    Btree customerTree(100000);
    Btree orderTree(100000);
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
        customerTree.insert(c);
    }
    for (int i{0}; i < jsonData["customers"].size(); i++)
    {
        Order c = Order(
            jsonData["orders"][i]["email"],
            jsonData["orders"][i]["price"],
            new string[2]{
                jsonData["orders"][i]["food"][0], jsonData["orders"][i]["food"][1]},
            jsonData["orders"][i]["status"]);
        orderTree.insert(c);
    }

    return 0;
    
  
    return 0; 
}
=======
#include <header.h>
int main() {
    Btree t(6);
    t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12); 
    t.insert(30); 
    t.insert(7); 
    t.insert(18); 
    t.insert(13);
    t.insert(4);
    t.insert(1);
    t.insert(21);
    t.insert(17);
    t.insert(14);
    t.insert(19);
    
  
    return 0; 
}
>>>>>>> 754803d0932e503805a0c7e45ec3ede392a4416c
