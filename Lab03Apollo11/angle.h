/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/


 /* DELETE ME WHEN DONE
 * Ticket 1:  minutes
 * Ticket 2:  minutes
 * Ticket 3:  minutes
 * Ticket 4:  minutes
 */

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;
   
   // Constructors
   Angle() : radians(-99.9)  
   {

   }

   Angle(const Angle& rhs) : radians(-99.9)  
   {
   
   }

   Angle(double degrees) : radians(-99.9)
   {

   }

   // Getters
   double getDegrees() const { return radians * (180 / M_PI); }
   double getRadians() const { return radians; }

   // Setters
   void setDegrees(double degrees) { radians = (degrees * (2 * M_PI)) / 360; }
   void setRadians(double radians) { }
   void setUp()                    { }
   void setDown()                  { }
   void setRight()                 { }
   void setLeft()                  { }
   void reverse()                  { }
   Angle& add(double delta) { radians = -99.9; return *this; }

private:
   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

