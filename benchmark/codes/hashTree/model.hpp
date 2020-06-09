#pragma once
#include <string>
using std::string;

class Customer
{
public:
    string firstName;
    string lastName;
    string email;
    string money;

    Customer(string first, string last, string email, string money) : firstName(first), lastName(last), email(email), money(money) {}
    string getIdentifier()
    {
        return this->email;
    }
    Customer() {}

    bool operator==(const Customer &o) const
    {
        return firstName == o.firstName && lastName == o.lastName;
    }
};

class Order
{
public:
    string email;
    string price;
    string *order;
    string status;

    Order()
    {
    }
    Order(string email, string price, string orderData[], string status) : email(email), price(price), order(orderData), status(status) {}
    string getIdentifier()
    {
        return this->email;
    }
    bool operator==(const Order &o) const
    {
        return email == o.email;
    }
};