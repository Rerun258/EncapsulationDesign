/*************************************************************
 * 1. Name:
 *      Elijah
 * 2. Module
 *      WALLET
 * 3. Assignment Description:
 *      A class to represent an wallet with multiple credit cards
 **************************************************************/

#pragma once

#include <cassert>

using namespace std;

class TestWallet;

 /************************************
  * WALLET
  ************************************/
class Wallet
{
   friend TestWallet;
   
   Wallet()
   {
      accountSam = 0;
      accountSue = 0;
      pCurrentAccount = &accountSam;
      cout << *pCurrentAccount;
   }
   
   private:
      double accountSam;
      double accountSue;
      double * pCurrentAccount;
   
public:
   
   // Update accounts
   void updateSam(double amount)
   {
      accountSam += amount;
   }
   
   void updateSue(double amount)
   {
      accountSue += amount;
   }
   
   void updateCurrent(double amount)
   {
      *pCurrentAccount += amount;
   }
   
   // Choose an account
   void chooseSam()
   {
      pCurrentAccount = &accountSam;
   }
   
   void chooseSue()
   {
      pCurrentAccount = &accountSue;
   }
   
   void chooseCurrent()
   {
      if (accountSam > accountSue)
      {
         pCurrentAccount = &accountSam;
      }
      
      else
      {
         pCurrentAccount = &accountSue;
      }
   }
   
   // Pull from an account
   double getSam()
   {
      return accountSam;
   }
   
   double getSue()
   {
      return accountSue;
   }
   
   double getCurrent()
   {
      return *pCurrentAccount;
   }

};

