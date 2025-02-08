// week5practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <sstream>

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
   // Declare a list to hold the lines read from the file
   list<string> lines;

   // Open the file for reading
   ifstream fin(fileName);

   // Read the current contents of the file into the list
   string line;
   while (getline(fin, line)) {
      lines.push_back(line);
   }

   // Close the input stream
   fin.close();

   // Format the new balance to 2 decimal places and add to the list
   stringstream ss;
   ss << fixed << setprecision(2) << balance;
   lines.push_back(ss.str());

   // Open the file for writing
   ofstream fout(fileName);

   // Write all lines back to the file, each on a new line
   for (const auto& line : lines) {
      fout << line << "\n";
   }

   // Close the output stream
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
   
	ifstream fin;
	fin.open(fileName);
   if (fin.fail()) 
   {
      cout << "Error!";
      fin.close(); 
		return 1;
   }
   

   else
   {
      fin.close();  
      displayBalance(fileName);
      updateBalance(fileName);
      displayBalance(fileName);
		writeBalance(fileName, 1000);
      
   }

}