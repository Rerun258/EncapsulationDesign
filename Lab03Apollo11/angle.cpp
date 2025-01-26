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

#define TWO_PI 6.28318530718

using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double aRadian)
{
   //while (aRadian > TWO_PI)
   //{
   //   aRadian -= TWO_PI;
   //}

   //while (aRadian < 0)
   //{
   //   aRadian += TWO_PI;
   //}

   aRadian = fmod(aRadian, TWO_PI); // Use fmod to find the remainder of aRadian divided by TWO_PI
   if (aRadian < 0)
   {
      aRadian += TWO_PI; // Adjust the result for negative angles
   }
   if (aRadian > 0)
   {
      aRadian -= TWO_PI; // Adjust the result for negative angles
   }

   return aRadian;
}


