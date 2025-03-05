/*************************************************************
 * 1. Name:
 *      Elijah, McClain
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/


/**************************************
 * COUNT - ARRAY
 **************************************/
int countArray(char* cString, char single)
{
   int* pEnd =  + ;
   for (int* p = array; p < pEnd; p++)
      cout << *p << endl;
}

/**************************************
 * COUNT - POINTER
 **************************************/
int countPointer(char* cString, char single)
{
   int count = 0;
   for (char * p = cString; *p; p++)
   {
      if (*p == single)
         return 0;
   }

   return 0;
}