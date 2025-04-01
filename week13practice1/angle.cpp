/***********************************************************************
 * Source:
 *    Angle
 * Summary:
 *    Just call the Angle unit tests
 * Author:
 *    James Helfrich
 ************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include "angle.h"
#include "testAngleRadians.h"
#include <math.h>  // for floor()
#include <cassert>
#define TWO_PI 6.28318530718
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


/************************************
 * MAIN
 * Simple driver
 ***********************************/
int main()
{
   TestAngle().run();
   TestAngleRadian().run();
   std::cout << "Tests Pass\n";
   
   return 0;
}
