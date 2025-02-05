// week5practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*****************
* READ BALANCE
* Returns balance from file.
* 
* INPUT
*  string fileName: filename
******************/
double readBalance(string fileName)
{
   //Open file and read balance.
   ifstream fin;
   double balance;

   fin.open(fileName);

   fin >> balance;

   fin.close();

   return balance;
}

/*****************
* UPDATE BALANCE
* Update balance in file by user input.
* 
* INPUT
*  string fileName: filename
******************/
void updateBalance(string fileName)
{
   // Ask user for change.
   double change;

   cout << "Change: ";
   cin >> change;

   // Add change to balance.
   double balance = readBalance(fileName);
   balance = balance + change;

   // Write updated balance to file.
   ofstream fout;
   fout.open(fileName);

   fout << balance;

   fout.close();
}

/*****************
* WRITE BALANCE
* Write a new balance in file.
******************/
void writeBalance(string fileName, double balance)
{
   ofstream fout;
   fout.open(fileName);

   fout << balance;

   fout.close();
}

/*****************
* DISPLAY BALANCE
* Display balance onto the console.
* 
* INPUT
*  string fileName: filename
******************/
void displayBalance(string fileName)
{
   double balance = readBalance(fileName);

   cout << "Account balance: $" << balance << endl;
}

/*****************
* MAIN
******************/
int main()
{
   string fileName = "data.txt";
   
    
   if (false) 
   {
      // TODO: Get the error check working.
   }

   else
   {
      displayBalance(fileName);
      updateBalance(fileName);
      displayBalance(fileName);
      
   }

}