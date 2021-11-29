#include "item.h"

void item::setName(string item_name)
{
  this->item_name = item_name;
}

void item::setQuantity(int quantity)
{
  this->quantity = quantity;
}

void item::setPrice(float price)
{
  this->price = price;
}

string item::getName()
{
  return item_name;
}

int item::getQuantity()
{
  return quantity;
}

float item::getPrice()
{
  return price;
}

void item::decreaseQuantity(int quantity)
{
  this->quantity-=quantity;
}

void item::increaseQuantity(int quantity)
{
  this->quantity+=quantity;
}

void item::viewItem()
{
  cout << " Name: " << item_name << " " << " Quantity: " << quantity << " " << " Price: $" << price << "\n";
}
