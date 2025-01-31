/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double aRadian) const
{  
   // Use fmod to find the remainder of aRadian divided by TWO_PI
   aRadian = fmod(aRadian, TWO_PI);

   if (aRadian < 0)
   {
      aRadian += TWO_PI;
   }
   if (aRadian > TWO_PI)
   {
      aRadian -= TWO_PI;
   }

   return aRadian;
}



