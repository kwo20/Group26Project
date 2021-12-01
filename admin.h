#pragma once
#pragma once

#include <string>
#include <iostream>

#include "cart.h"
#include "item.h"

using namespace std;
class admin : public cart
{
public:
    string username;
    string password;
    string shipping_info;
    string payment_info;
    string adminpwd;
    cart account_cart;

    //setters
    void setUser(string username);
    void setPassword(string password);
    void setShipping(string shipping_info);
    void setPayment(string payment_info);
    void setAdminpwd(string adminpwd);
    void setCartSize(int cart_size);

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
    void showinfo();

    //create an account with information
    admin(string username, string password, string shipping_info, string payment_info) : username(username), password(password), shipping_info(shipping_info), payment_info(payment_info) {}

    //create a blank account
    admin() : username(""), password(""), shipping_info(""), payment_info("") {}

};