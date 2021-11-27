#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include "account.h"
#include "item.h"
#include "cart.h"
using namespace std;
int i;
int account_option, shop_option, cart_size;
int main() 
{
  vector<account> accounts;
  vector<item> items;
  cart carts;
  
  string accountfile, itemfile;
  string line;
  
  fstream file, file2;

  accountfile = "account.txt";
  itemfile = "item.txt";
  file.open(accountfile);
  
  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      account accountz;
      accountz.setUser(line);
      getline(file, line);
      accountz.setPassword(line);
      getline(file, line);
      accountz.setShipping(line);
      getline(file, line);
      accountz.setPayment(line);
      accounts.push_back(accountz);
    }
    file.close();
  }
  
  int quantity;
  float price;
  file2.open(itemfile);
  if (file2.is_open())
  {
    while(getline(file2, line))
    {
      item itemz;
      itemz.setName(line);
      getline(file2, line);
      quantity = stoi(line);
      itemz.setQuantity(quantity);
      getline(file2, line);
      price = stof(line);
      itemz.setPrice(price);
      items.push_back(itemz);
    }
    file2.close();
  }
  
  int menu_option, login_option;
  
  string username, password, shipping_info, payment_info;
  
  cout << "Welcome to the Group 26 Store!" << "\n";
  while(1)
  {
    cout << "Would you like to login(1), create a new account(2), or exit(3)?";
    cin >> menu_option;
    if(menu_option == 2)
    {
      cout << "Please enter the following information:\n";
      cout << "Username: ";
      getline(cin >> ws, username);
      cout << "Password: ";
      getline(cin, password);
      cout << "Shipping Address: ";
      getline(cin, shipping_info);
      cout << "Card #: ";
      getline(cin, payment_info);
      account accountz(username, password, shipping_info, payment_info);
      accounts.push_back(accountz);
      cout << "Account created! Now please login.\n";
      menu_option = 1;
    }
    if(menu_option == 1)
    {
      cout << "Username: ";

      getline(cin >> ws, username);
      
      for(i = 0; i<accounts.size(); i++)
      {
        if(username == accounts[i].getUser())
        {
          cout << "Password: ";
          getline(cin, password);
          if(password == accounts[i].getPass())
          {
            //continue with shop
            cout << "Welcome, " << username << "\n\n";
            //added set username to the cart class
            carts.setUsername(username);

            while(1)
            {
              cout << "(1)View Shop\n" << "(2)View Cart\n" << "(3)View Account\n" << "(4)Logout\n";
              cin >> login_option;
              if(login_option == 1)
              {
                while(1)
                {
                  int item_choice, item_quantity;
                  for(int z = 0; z<items.size(); z++)
                  {
                    cout << z+1 << ". ";
                    items[z].viewItem();
                    cout << endl;
                  }
                  cout << "(1)Add item to your cart\n" << "(2)Go back\n";
                  cin >> shop_option;
                  if(shop_option == 1)
                  {
                    cout << "Please input the number that corresponds to the item you want: ";
                    cin >> item_choice;
                    if(item_choice > 0 && item_choice <= items.size())
                    {
                      cout << "You have chosen " << items[item_choice-1].getName() << "\n";
                      cout << "How much of this item do you want? ";
                      cin >> item_quantity;
                      while(1)
                      {
                        if(item_quantity > items[item_choice-1].getQuantity())
                        {
                          cout << "More than available quantity, please re-enter: ";
                          cin >> item_quantity;
                        }
                        else
                        {
                          break;
                        }
                      }
                      accounts[i].add_item(item_quantity, items[item_choice-1]);
                      item current_cart_item;
                      current_cart_item.setName(items[item_choice-1].getName());
                      current_cart_item.setQuantity(item_quantity);
                      current_cart_item.setPrice(items[item_choice-1].getPrice());
                      carts.add_items(current_cart_item);
                      cart_size+=1;
                      cout << "Item added to your cart!\n";
                    }
                    else
                    {
                      cout << "broke\n";
                    }
                  }
                  else if(shop_option == 2)
                  {
                    break;
                  }
                }
              }
              else if(login_option == 2)
              {
                while(1)
                {
                  int cart_option;
                  accounts[i].printCart();
                  cout << "(1)Remove item from cart\n" << "(2)Checkout\n" << "(3)Go back\n";
                  cin >> cart_option;
                  if(cart_option == 1)
                  {
                    int item_to_remove;
                    cout << "Please enter the number corresponding to the item you want to remove: ";
                    cin >> item_to_remove;
                    accounts[i].remove_item(item_to_remove);
                    cart_size-=1;
                  }
                  else if(cart_option == 2)
                  {
                    
                    for(int t = 0; t<cart_size; t++)
                    {
                      for(int s = 0; s<items.size(); s++)
                      {                     
                        if(carts.getItemName(t) == items[s].getName())
                        {
                          items[s].decreaseQuantity(carts.getItemQuantity(t));
                        }
                      }
                    }//I think I added this, don't remember
                    carts.checkout();
                    accounts[i].checkout();
                    
                  }
                  else if(cart_option == 3)
                  {
                    break;
                  }
                }
              }
              else if(login_option == 3)
              {
                while(1)
                {
                  string passchange, shipchange, paychange;
                  cout << "(1)View Account Info\n" << "(2)Change Password\n" << "(3)Change Shipping Information\n" << "(4)Change Payment Information\n" << "(5)Delete Account\n" << "(6)Go Back\n";
                  cin >> account_option;
                  if(account_option == 1)
                  {
                    accounts[i].printAccount();
                  }
                  else if(account_option == 2)
                  {
                    getline(cin >> ws, passchange);
                    accounts[i].setPassword(passchange);
                    printf("password changed");
                  }
                  else if(account_option == 3)
                  {
                    getline(cin >> ws, shipchange);
                    accounts[i].setShipping(shipchange);
                    printf("shipping info changed");
                  }
                  else if(account_option == 4)
                  {
                    getline(cin >> ws, paychange);
                    accounts[i].setPayment(paychange);
                    printf("payment info changed");
                  }
                  else if(account_option == 5)
                  {
                    accounts.erase(accounts.begin()+i);
                    //added delete history when account is deleted
                    carts.del_history();
                    printf("Account erased\n");
                    login_option = 4;
                    break;
                  }
                  else if(account_option == 6)
                  {
                    break;
                  }
                }
              }
              if(login_option == 4)
              {
                break;
              }
            }
          }
          else
          {
            printf("WRONG PASSWORD\n");
            break;
          }
          break;
        }
      }
      if(account_option == 0 && i == accounts.size())
      {
        printf("user doesnt exist\n");
      }
    }
    if(menu_option == 3)
    {
      break;
    }
  }
  
  ofstream account_write;
  account_write.open("account.txt");
  for(int j = 0; j<accounts.size(); j++)
  {
    account_write << accounts[j].getUser() << "\n";
    account_write << accounts[j].getPass() << "\n";
    account_write << accounts[j].getShipping() << "\n";
    account_write << accounts[j].getPayment() << "\n";
  }
  account_write.close();

  ofstream item_write;
  item_write.open("item.txt");
  for(int j = 0; j<items.size(); j++)
  {
    item_write << items[j].getName() << "\n";
    item_write << items[j].getQuantity() << "\n";
    item_write << items[j].getPrice() << "\n";
  }
  item_write.close();
} 
