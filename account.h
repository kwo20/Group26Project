#pragma once

#include <string>
#include <iostream>

#include "cart.h"
#include "item.h"

using namespace std;
class account : public cart
{
    private:
    string username;
    string password;
    string shipping_info;
    string payment_info;
    cart account_cart;

    public:
    //setters
    void setUser(string username);
    void setPassword(string password);
    void setShipping(string shipping_info);
    void setPayment(string payment_info);
    //void setCartSize(int cart_size);

    //getters
    string getUser();
    string getPass();
    string getShipping();
    string getPayment();
    void checkout();
    void viewHistory();
    void clearCart();

    void printAccount();
    void add_item(int quantity, class item item_to_add);
    void printCart();
    void remove_item(int item_number);

    //create an account with information
    account(string username, string password, string shipping_info, string payment_info) : username(username), password(password), shipping_info(shipping_info), payment_info(payment_info) {}

    //create a blank account
    account() : username(""), password(""), shipping_info(""), payment_info("") {}

};
