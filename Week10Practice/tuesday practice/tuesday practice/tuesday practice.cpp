/*************************************************************
 * 1. Name:
 *      McClain, Elijah
 * 2. Assignment Name:
 *      Practice 10: Exceptions
 * 3. Assignment Description:
 *      Throwing and catching exceptions
 * 4. What was the hardest part? Be as specific as possible.
 *      Writing the catches. 
 * 5. How long did it take for you to complete the assignment?
 *      1 hour
 **************************************************************/

#include <iostream>
using namespace std;
#include <cassert>


/**************************************
 * GET POSITION
 * Turn a chess position like "d4" into a number
 **************************************/
int getPosition(const char* position)
{
   int row = -1;
   int col = -1;
   try {
      if (nullptr == position)
      {
         throw runtime_error("ERROR: Please provide a valid string");
      }
   }
   catch (const runtime_error e) {
      cout << e.what() << endl;
      return -1;
   }

   try {
      for (const char* p = position; *p; p++)
      {
         if (isalpha(*p))
         {
            if (col != -1)
            {
					throw runtime_error("ERROR: More than one column specifier");
               return -1;
            }

            else if (isupper(*p))
            {
					throw runtime_error("ERROR: Columns must be lowercase");
             
               return -1;
            }

            else if ('a' <= *p && *p <= 'h')
               col = *p - 'a';

            else
            {
					throw runtime_error("ERROR: Columns must be between a and h");
               
               return -1;
            }
         }
         else if (isdigit(*p))
         {
            if (row != -1)
            {
					throw runtime_error("ERROR: More than one row specifier");
               
               return -1;
            }

            else if ('1' <= *p && *p <= '8')
               row = *p - '1';
               
            else
            {
					throw runtime_error("ERROR: Rows must be between 1 and 8");
               
               return -1;
            }
         }
         else
         {
				throw runtime_error("ERROR: Unknown letter");
            
            return -1;
         }
      }

      if (row == -1)
      {
         throw runtime_error("ERROR: You must specify a row");

         return -1;
      }

      else if (col == -1)
      {
         throw runtime_error("ERROR: You must specify a column");

         return -1;
      }
   }
   catch (const runtime_error e) {
      cout << e.what() << endl;
      return -1;
   }

   return row * 8 + col;
}


/**************************************
 * TEST GET POSITION
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void test_getPosition()
{
   // Correct output
   assert(27 == getPosition("d4"));
   assert(27 == getPosition("4d"));
   assert(0  == getPosition("a1"));
   assert(63 == getPosition("h8"));
   assert(7  == getPosition("h1"));
   assert(56 == getPosition("a8"));

   // Should return a runtime error
   assert(-1 == getPosition(nullptr));
   assert(-1 == getPosition("D4"));
   assert(-1 == getPosition("dd4"));
   assert(-1 == getPosition("d44"));
   assert(-1 == getPosition("d"));
   assert(-1 == getPosition("4"));
   assert(-1 == getPosition("i8"));
   assert(-1 == getPosition("h9"));
   assert(-1 == getPosition("d4^"));
}

/**************************************
 * MAIN
 **************************************/
int main()
{
   test_getPosition();
   cout << "Tests pass\n";

   return 0;
}