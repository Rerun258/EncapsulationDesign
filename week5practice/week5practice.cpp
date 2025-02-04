// week5practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

/*****************
* READ BALANCE
* Returns balance from file.
******************/
double readBalance()
{
   // TODO: Pull balance from file.
   return 0.0;
}

/*****************
* UPDATE BALANCE
* Update balance in file by user input.
******************/
void updateBalance()
{
   double change;

   std::cout << "Change: ";
   std::cin >> change;

   // TODO: Update file here.
   // 
   // Displaying balance will be handled by main via displayBalance.
}

/*****************
* WRITE BALANCE
* Write a new balance in file.
******************/
void writeBalance()
{
  
}

/*****************
* DISPLAY BALANCE
* Display balance onto the console.
******************/
void displayBalance()
{
   double balance = readBalance();

   std::cout << "Account balance: $" << balance << endl;
}

/*****************
* MAIN
******************/
int main()
{
    std::cout << "Hello World!\n";
}