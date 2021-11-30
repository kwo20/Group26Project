#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include "account.h"
#include "item.h"
#include "cart.h"
using namespace std;
int i;

int account_option, cart_size;
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
  
  //reads in the account information from the file to the program
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
  
  //reads in the item information from the file to the program
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
  
  int menu_option, login_option, shop_option;
  
  string username, password, shipping_info, payment_info;
  
  //Main Menu
  cout << "Welcome to the Group 26 Store!" << "\n";
  while(1)
  {
    cout << "Would you like to login(1), create a new account(2), or exit(3)?";
    cin >> menu_option;

    //Create Account 
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

    //Login information
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
            cout << "\x1B[2J\x1B[H";
            cout << "Welcome, " << username << "\n";
            carts.setUsername(username);
            
            while(1)
            {
              
              cout << "Main Menu\n\n";
              cout << "(1)View Shop\n" << "(2)View Cart\n" << "(3)View Account\n" << "(4)Logout\n";
              cin >> login_option;

              //View shop options
              if(login_option == 1)
              {
                cout << "\x1B[2J\x1B[H";
                while(1)
                {
                  
                  cout << "Shop Catalog\n\n";
                  int item_choice, item_quantity;
                  for(int z = 0; z<items.size(); z++)
                  {
                    cout << z+1 << ". ";
                    items[z].viewItem();
                    cout << endl;
                  }

                  cout << "(1)Add item to your cart\n" << "(2)Go back\n";
                  cin >> shop_option;

                  //Add items to cart
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
                      item current_cart_item;
                      current_cart_item.setName(items[item_choice-1].getName());
                      current_cart_item.setQuantity(item_quantity);
                      current_cart_item.setPrice(items[item_choice-1].getPrice());
                      carts.add_items(current_cart_item);
                      cart_size+=1;
                      cout << "\x1B[2J\x1B[H";
                      cout << "Item added to your cart!\n";
                      break;
                    }
                    else
                    {
                      cout << "broke\n";
                    }
                  }
                  //Goes back
                  else if(shop_option == 2)
                  {
                    cout << "\x1B[2J\x1B[H";
                    break;
                  }
                }
              }
              //View cart options
              else if(login_option == 2)
              {
                cout << "\x1B[2J\x1B[H";
                while(1)
                {
                  cout << "Cart Menu\n\n";
                  int cart_option = 0;
                  carts.view_cart();
                  cout << "(1)Remove item from cart\n" << "(2)Checkout\n" << "(3)Go back\n";
                  cin >> cart_option;

                  //Remove item from cart
                  if(cart_option == 1)
                  {
                    int item_to_remove;
                    cout << "Please enter the number corresponding to the item you want to remove: ";
                    cin >> item_to_remove;
                    carts.remove_items(item_to_remove);
                    cart_size-=1;
                    cout << "\x1B[2J\x1B[H";
                    cout << "Item Removed!\n";
                    break;
                  }

                  //Checkout
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
                    }
                    carts.checkout(); 
                    cart_size = 0;
                    cout << "\x1B[2J\x1B[H";
                    cout << "Checkout successful!\n";
                    break;
                  }
                  else if(cart_option == 3)
                  {
                    cout << "\x1B[2J\x1B[H";
                    break;
                  }
                }
              }

              //View account options
              else if(login_option == 3)
              {
                cout << "\x1B[2J\x1B[H";
                while(1)
                {
                  
                  cout << "Account Menu\n\n";
                  string passchange, shipchange, paychange;
                  cout << "(1)View Account Info\n" << "(2)Change Password\n" << "(3)Change Shipping Information\n" << "(4)Change Payment Information\n" << "(5)Delete Account\n" << "(6)View Order History\n" << "(7)Go Back\n";
                  cin >> account_option;
                  //View account
                  if(account_option == 1)
                  {
                    cout << "\x1B[2J\x1B[H";
                    accounts[i].printAccount();
                  }
                  //Change password
                  else if(account_option == 2)
                  {
                    cout << "Please enter your new password: ";
                    getline(cin >> ws, passchange);
                    accounts[i].setPassword(passchange);
                    cout << "\x1B[2J\x1B[H";
                    printf("Password changed!\n");
                  }
                  //Change shipping
                  else if(account_option == 3)
                  {
                    cout << "Please enter your new shipping address: ";
                    getline(cin >> ws, shipchange);
                    accounts[i].setShipping(shipchange);
                    cout << "\x1B[2J\x1B[H";
                    printf("Shipping info changed!\n");
                  }
                  //Change payment information
                  else if(account_option == 4)
                  {
                    cout << "Please enter your new card number: ";
                    getline(cin >> ws, paychange);
                    accounts[i].setPayment(paychange);
                    cout << "\x1B[2J\x1B[H";
                    printf("Payment info changed!\n");
                  }
                  //Delete account
                  else if(account_option == 5)
                  {
                    carts.del_history();
                    accounts.erase(accounts.begin()+i);
                    cout << "\x1B[2J\x1B[H";
                    printf("Account erased!\n");
                    login_option = 4;
                    break;
                  }
                  //View order history
                  else if(account_option == 6)
                  {
                    cout << "\x1B[2J\x1B[H";
                    carts.view_history();
                  }
                  //Goes back
                  else if(account_option == 7)
                  {
                    cout << "\x1B[2J\x1B[H";
                    break;
                  }
                }
              }
              //logout
              if(login_option == 4)
              {
                carts.clear_cart();
                cout << "\x1B[2J\x1B[H";
                break;
              }
            }
          }
          //wrong password
          else
          {
            printf("WRONG PASSWORD\n");
            break;
          }
          break;
        }
      }
      //Prints user does not exist if user entered an account that do not exists
      if(account_option == 0 && i == accounts.size())
      {
        printf("user doesnt exist\n");
      }
    }
    //exits the program
    if(menu_option == 3)
    {
      break;
    }
  }
  

  //Writes all of the item and account information to a file to store.
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
