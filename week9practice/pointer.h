/*************************************************************
 * 1. Name:
 *      Elijah, McClain
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *     Understanding the instructions. 
 * 5. How long did it take for you to complete the assignment?
 *      30 minutes
 **************************************************************/

using namespace std;

/**************************************
 * COUNT - ARRAY
 **************************************/
int countArray(char* cString, char single)
{
	// Find the length of the string
   int length = strlen(cString); 

	int count = 0;

   // If the indexes match, count it
   for (int i = 0; i < length; i++)
   {
      if (cString[i] == single)
         count++;
   }

	return count;
}



/**************************************
 * COUNT - POINTER
 **************************************/
int countPointer(char* cString, char single)
{
	int count = 0; 

   for (char * p = cString; *p; p++)
   {
      // If the characters match, count it
      if (*p == single)
			count++;
   }

   return count;
}