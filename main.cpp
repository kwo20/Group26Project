#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include "account.h"
using namespace std;
int main() 
{
  vector<account> test;
  
  string filename;
  string line;
  
  fstream file;

  filename = "test.txt";
  file.open(filename);
  
  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      account testr;
      testr.setUser(line);
      getline(file, line);
      testr.setPassword(line);
      getline(file, line);
      testr.setShipping(line);
      getline(file, line);
      testr.setPayment(line);
      test.push_back(testr);
    }
    file.close();
  }

  int menu_option;
  
  string username, password, shipping_info, payment_info;
  
  cout << "Welcome to the Group 26 Store!" << "\n" << "Would you like to login(1), create a new account(2), or exit(3)?";

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
    account testr(username, password, shipping_info, payment_info);
    test.push_back(testr);
    cout << "Account created! Now please login.\n";
    menu_option = 1;
  }
  if(menu_option == 1)
  {
    cout << "Username: ";

    getline(cin >> ws, username);
    
    for(int i = 0; i<test.size(); i++)
    {
      if(username == test[i].getUser())
      {
        cout << "Password: ";
        getline(cin, password);
        if(password == test[i].getPass())
        {
          //continue with shop
          printf("CORRECT");
          cout << "Welcome, " << username << "\n\n";
          while(1)
          {
            cout << "(1)View Shop Catalog\n" << "(2)View Cart\n" << "(3)View Account\n" << "(4)Logout\n";
            cin >> menu_option;
            if(menu_option == 1)
            {

            }
            else if(menu_option == 2)
            {

            }
            else if(menu_option == 3)
            {
              while(1)
              {
                int account_option;
                string passchange, shipchange, paychange;
                cout << "(1)View Account Info\n" << "(2)Change Password\n" << "(3)Change Shipping Information\n" << "(4)Change Payment Information\n" << "(5)Delete Account\n" << "(6)Go Back\n";
                cin >> account_option;
                if(account_option == 1)
                {
                  test[i].printAccount();
                }
                else if(account_option == 2)
                {
                  getline(cin >> ws, passchange);
                  test[i].setPassword(passchange);
                  printf("password changed");
                }
                else if(account_option == 3)
                {
                  getline(cin >> ws, shipchange);
                  test[i].setShipping(shipchange);
                  printf("shipping info changed");
                }
                else if(account_option == 4)
                {
                  getline(cin >> ws, paychange);
                  test[i].setPayment(paychange);
                  printf("payment info changed");
                }
                else if(account_option == 5)
                {
                  printf("del acc");
                }
                else if(account_option == 6)
                {
                  printf("go back");
                  break;
                }
              }
            }
            else if(menu_option == 4)
            {
              break;
            }
          
          }
        }
        else
        {
          
          printf("WRONG PASSWORD");
         
        }
      }
    }
    printf("DIDNT FIND USER");
  }
  if(menu_option == 3)
  {
    exit(EXIT_SUCCESS);
  }

  ofstream filetest;
  filetest.open("test.txt");
  for(int j = 0; j<test.size(); j++)
  {
    //test[j].printAccount();
    //printf("\n\n");
  
    filetest << test[j].getUser() << "\n";
    filetest << test[j].getPass() << "\n";
    filetest << test[j].getShipping() << "\n";
    filetest << test[j].getPayment() << "\n";
  }
  filetest.close();
} 
