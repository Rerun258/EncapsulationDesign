/***********************************************************************
 * Source File:
 *    ACCELERATION 
 * Author:
 *    McClain, Elijah
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>



/*********************************************
* ACCELERATION : ADD
*  a += a
*********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   ddx += acceleration.getDDX();
   ddy += acceleration.getDDY();
}


/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   // Convert angle to radians if it's not already in radians
   double radians = angle.getRadians();

   // Calculate the components of the acceleration
   ddx = magnitude * sin(radians);
   ddy = magnitude * cos(radians);
}
