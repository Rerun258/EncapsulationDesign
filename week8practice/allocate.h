/*************************************************************
 * 1. Name:
 *      Elijah, McClain
 * 
 * 2. Assignment Name:
 *      Practice 08: Allocation
 * 
 * 3. Assignment Description:
 *      Allocate an array and then use it
 * 
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 * 
 **************************************************************/

class TestAllocate;

class Allocate
{
   friend TestAllocate;

public:
   /****************************
   * ALLOCATE ONE FLOAT
   ****************************/
   float * allocateOneFloat(float newFloat)
   {
      pFloat = new float(newFloat);

      if (pFloat == nullptr)
      {
         std::cout << "ERROR";
         return nullptr;
      }

      else
      {
         std::cout << "FLOAT ALLOCATED";
         return pFloat;
      }

   }

   /****************************
   * ALLOCATE ARRAY of DOUBLEs
   ****************************/
   double * allocateArrayDouble(int slots)
   {
      if (slots <= 0) { return nullptr; }

      else
      {
         pSlots = new(nothrow) double pSlots [slots + 1];
      }
         
   }

   /****************************
   * DELETE ONE FLOAT
   ****************************/
   void deleteOneFloat(float* pFloat)
   {
      delete pFloat;
      std::cout << "FLOAT DELETED";
   }

   /****************************
   * DELETE ARRAY of DOUBLEs
   ****************************/
   void deleteArrayDouble(double * p)
   {
      delete [] p;
   }

   private:
      float* pFloat;
      double* pSlots;

};