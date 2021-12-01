#include "admin.h"
#include <fstream>

void admin::setUser(string username)
{
	this->username = username;
}

void admin::setPassword(string password)
{
	this->password = password;
}

void admin::setShipping(string shipping_info)
{
	this->shipping_info = shipping_info;
}

void admin::setPayment(string payment_info)
{
	this->payment_info = payment_info;
}

string admin::getUser()
{
	return username;
}

string admin::getPass()
{
	return password;
}

string admin::getShipping()
{
	return shipping_info;
}

string admin::getPayment()
{
	return payment_info;
}

void admin::showinfo(vector<account> accounts)
{
  int i;
  for(i = 0; i<accounts.size(); i++)
  {
    cout << i+1 << ". Username: " << accounts[i].getUser();
    cout << "\n   Password: " << accounts[i].getPass();
    cout << "\n   Shipping Info: " << accounts[i].getShipping();
    cout << "\n   Card #: " << accounts[i].getPayment();
    cout << "\n\n";
  }
}
