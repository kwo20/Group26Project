#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "item.h"

using namespace std;

class cart : public item
{
private:
	
	vector <item> items;
	float total = 0;
	string username;

public:
  
	//setters
	void setTotal(float total);

	void setUsername(string username);

	//getters
	float getTotal();

	string getUsername();

	string getItemName(int q);

	int getItemQuantity(int q);

	//functions
	void view_cart();

	void view_total();

	void checkout();

	void view_history();

	void add_history();

	void del_history();

    void add_items(class item item_to_add);

    void remove_items(int item_number);

    void clear_cart();
};
