#pragma once

#include <string>
#include <iostream>

using namespace std;
class account
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

    void printAccount();

    //create an account with information
    account(string username, string password, string shipping_info, string payment_info) : username(username), password(password), shipping_info(shipping_info), payment_info(payment_info) {}

    //create a blank account
    account() : username(""), password(""), shipping_info(""), payment_info("") {}

    //destructor
    //~account();
};