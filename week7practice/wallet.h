/*************************************************************
 * 1. Name:
 *      -your name-
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
   void updateSam(double amount)
   {
      
   }
   
   void updateSue(double amount)
   {
      
   }
   
   void updateCurrent(double amount)
   {
      
   }
   
   void chooseSam()
   {
      
   }
   
   void chooseSue()
   {
      
   }
   
   void chooseCurrent()
   {
      
   }
   
   double getSam()
   {
      return 0.0;
   }
   
   double getSue()
   {
      return 0.0;
   }
   
   double getCurrent()
   {
      return 0.0;
   }

};

