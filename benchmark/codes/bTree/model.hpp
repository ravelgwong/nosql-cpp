#pragma once
#include <string>
using std::string;

class Customer
{
private:
    string firstName;
    string lastName;
    string email;
    string money;

public:
    Customer(string first, string last, string email, string money) : firstName(first), lastName(last), email(email), money(money) {}
    string getIdentifier()
    {
        return this->email;
    }
    Customer() {}
};

class Order
{
private:
    string email;
    string price;
    string *order;
    string status;

public:
    Order()
    {
    }
    Order(string email, string price, string orderData[], string status) : email(email), price(price), order(orderData), status(status) {}
    string getIdentifier()
    {
        return this->email;
    }
};