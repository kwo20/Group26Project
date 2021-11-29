#include "account.h"

void account::setUser(string username)
{
  this->username = username;
}

void account::setPassword(string password)
{
  this->password = password;
}

void account::setShipping(string shipping_info)
{
  this->shipping_info = shipping_info;
}

void account::setPayment(string payment_info)
{
  this->payment_info = payment_info;
}

string account::getUser()
{
  return username;
}

string account::getPass()
{
  return password;
}

string account::getShipping()
{
  return shipping_info;
}

string account::getPayment()
{
  return payment_info;
}

void account::printAccount()
{
  cout << "Username: " << username << "\n" << "Password: " << password << "\n" <<  "Shipping Info: " <<shipping_info << "\n" << "Card Number: " << payment_info << "\n\n";
}

void account::add_item(int quantity, class item item_to_add)
{
  item_to_add.setQuantity(quantity);
  account_cart.add_items(item_to_add);
}

void account::remove_item(int item_number)
{
  account_cart.remove_items(item_number);
}

void account::printCart()
{
  account_cart.view_cart();
}

void account::checkout()
{
  account_cart.checkout();
}

void account::viewHistory()
{
  account_cart.view_history();
}

void account::clearCart()
{
  account_cart.clear_cart();
}
