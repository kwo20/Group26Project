#pragma once

#include <string>
#include <iostream>

#include "cart.h"
#include "item.h"
#include "account.h"

using namespace std;
class admin : public cart
{
public:
    string username;
    string password;
    string shipping_info;
    string payment_info;

    //setters
    void setUser(string username);
    void setPassword(string password);
    void setShipping(string shipping_info);
    void setPayment(string payment_info);

    //getters
    string getUser();
    string getPass();
    string getShipping();
    string getPayment();

    void showinfo(vector<account> accounts);

    //create an account with information
    admin(string username, string password, string shipping_info, string payment_info) : username(username), password(password), shipping_info(shipping_info), payment_info(payment_info) {}

    //create a blank account
    admin() : username(""), password(""), shipping_info(""), payment_info("") {}

};
