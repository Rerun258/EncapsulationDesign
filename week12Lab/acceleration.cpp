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
void Acceleration::add(const Acceleration& a)
{
   ddx += a.getDDX();
   ddy += a.getDDY();
}


/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& a, double magnitude)
{
   // Calculate the components of the acceleration
   ddx = magnitude * sin(a.getRadians());
   ddy = magnitude * cos(a.getRadians());
}
