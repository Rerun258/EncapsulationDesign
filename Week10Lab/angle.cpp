/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Elijah, McClain
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
double Angle::normalize(double radians) const
{
   radians = fmod(radians, TWO_PI);

   if (radians < 0)
      radians += TWO_PI;
   
   if (radians > TWO_PI)
      radians -= TWO_PI;

   return radians;
}



