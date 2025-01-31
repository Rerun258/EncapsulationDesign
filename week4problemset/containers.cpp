/*************************************************************
 * 1. Name:
 *      McClain, Elijah
 *
 * 2. Assignment Name:
 *      Practice 04: Contaiers
 *
 * 3. Assignment Description:
 *      Work with a list and a vector
 *
 * 4. What was the hardest part? Be as specific as possible.
 *      Using the iterator, and learning to use it with a 
 *       for loop. After using it, and discussing on it, 
 *       iterators make more sense now.
 *
 * 5. How long did it take for you to complete the assignment?
 *      ~1.5 hours
 **************************************************************/


#include "testContainers.h"
#include <string>
#include <list>
using namespace std;

/*****************************
 * ARRAY TO LIST
*****************************/
list<string> arrayToList(string a[], int num)
{
   list<string> result;
   int index;

   for (index = 0; index < num; index++) 
   {
      result.push_back(a[index]);   
   }

   return result;
}

/*****************************
 * ARRAY TO LIST BACKWARDS
*****************************/
list<string> arrayToListBackwards(string a[], int num) 
{
   list<string> result;

   for (int index = num; index > 0; index--) 
   {
      // Corrected index to avoid out-of-bounds access.
      result.push_back(a[index - 1]); 
   }

   return result;
}

/*****************************
 * LIST TO VECTOR
*****************************/
vector<string> listToVector(const list<string>& l) 
{
   vector<string> result;

   for (auto it = l.begin(); it != l.end(); it++) 
   {
      result.push_back(*it);
   }

   return result;
}

/*****************************
 * LIST TO VECTOR BACKWARDS
*****************************/
vector<string> listToVectorBackwards(const list<string>& l) 
{
   vector<string> v;

   // Reserve space in the vector for performance.
   v.reserve(l.size()); 

   // Iterate through the list in reverse order and push elements into the vector.
   for (auto rit = l.rbegin(); rit != l.rend(); ++rit) 
   {
      v.push_back(*rit);
   }

   return v;
}

/*****************************
 * FIND ELEMENT IN VECTOR
*****************************/
bool findElementInVector(const vector<string> & v, const string& element)
{
   for (auto it = v.begin(); it != v.end(); it++) 
   {
      if (*it == element) return true;
   }

   return false;
}

/*****************************
 * MAIN
*****************************/
int main()
{
   TestCollection().run();
   return 0;
}
