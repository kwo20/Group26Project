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

void admin::setAdminpwd(string adminpwd)
{
	this->adminpwd = adminpwd;
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

void admin::printAccount()
{
	cout << "Username: " << username << "\n" << "Password: " << password << "\n" << "Shipping Info: " << shipping_info << "\n" << "Card Number: " << payment_info << "Admin Pwd: " << adminpwd << "\n\n";
}

void admin::add_item(int quantity, class item item_to_add)
{
	item_to_add.setQuantity(quantity);
	admin_cart.add_items(item_to_add);
}

void admin::remove_item(int item_number)
{
	account_cart.remove_items(item_number);
}

void admin::printCart()
{
	account_cart.view_cart();
}

void admin::checkout()
{
	account_cart.checkout();
}

void admin::viewHistory()
{
	account_cart.view_history();
}

void admin::clearCart()
{
	account_cart.clear_cart();
}

void admin::showinfo()
{
	std::ifstream f("account.txt");

	if (f.is_open())
		std::cout << f.rdbuf();
}