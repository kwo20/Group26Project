#pragma once

#include <string>
#include <iostream>

using namespace std;

class item
{
  public:
    float price;
    int quantity;
    string item_name;

    void setName(string item_name);
    void setQuantity(int quantity);
    void setPrice(float price);

    string getName();
    int getQuantity();
    float getPrice();

    void decreaseQuantity(int quantity);
    void increaseQuantity(int quantity);
    void viewItem();

    item(string item_name, int quantity, float price) : item_name(item_name), quantity(quantity), price(price) {} 

    item() : item_name(""), quantity(0), price(0) {}
};