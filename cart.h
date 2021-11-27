#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "item.h"

using namespace std;

class cart : public item
{
private:
	
	vector <item> items;
	int total;

public:

	//default cart
	//cart() : item_name(""), quantity(0), item_price(0) {};
	//cart(item_name, quantity, item_price) : item_name(item_name), quantity(quantity), item_price(item_price);
  
	//setters
	void setTotal(int total);

	//getters
	int getTotal();

	string getItemName(int q);

  int getItemQuantity(int q);

	//functions
	void view_cart();

	void view_total();

	void checkout();

	void view_history();

	void add_history();

  void add_items(class item item_to_add);

  void remove_items(int item_number);



};
