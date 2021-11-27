#include "cart.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//getters
int cart::getTotal() {

	return total;
}

//settters
void cart::setTotal(int total) {

	this->total = total;
}

//functions
void cart::view_cart() {

	for (int i = 0; i < items.size(); i++) {

		cout << "(" << i+1 << ") ";
    cout << items[i].getName() << "   ";
		cout << items[i].getQuantity() << "   ";
		cout << items[i].getPrice() << "\n";

	}

}

void cart::view_total() {

	for (int i = 0; i < items.size(); i++) {

		total = total +  items[i].getQuantity()* items[i].getPrice();

	}

	cout << "Current Total: " << total;
}


void cart::checkout() {

	
	add_history();

	items.clear();

}

void cart::add_history() {
	ofstream file_in;
	
	file_in.open("History", std::ofstream::out | std::ofstream::app);
	
	file_in << "\n";
	
	for (int i = 0; i < items.size(); i++) {

		file_in << items[i].getName() << "   ";
		file_in << items[i].getQuantity() << "   ";
		file_in << items[i].getPrice() << "\n";

	}

	file_in.close();
}

void cart::view_history() {

	fstream file_out;
	string line;
	int count = 0;

	file_out.open("History", std::ofstream::in);

	if(file_out.is_open()){

		while (getline(file_out, line)) {
			if (count == 3) {
				count = 0;
				cout << "\n";
			}

			cout << line << "   ";
			count++;

		}
	}

	cout << "\n";

	file_out.close();
}
void cart::add_items(class item item_to_add)
{
  items.push_back(item_to_add);
}

void cart::remove_items(int item_number)
{
  items.erase(items.begin() + item_number-1);
}

string cart::getItemName(int q)
{
  string test = items[q].getName();
  return test;
}

int cart::getItemQuantity(int q)
{
  return items[q].getQuantity();
}
