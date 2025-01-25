/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/


 /* DELETE ME WHEN DONE
 * Ticket 1: ~45 minutes
 * Ticket 2: ~60 minutes
 * Ticket 3: ~45 minutes
 * Ticket 4: ~45 minutes
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
      Angle() : radians(0.0) { }

      Angle(const Angle& rhs): radians(rhs.getRadians()) { }

      Angle(double degrees) : radians(degrees* M_PI / 180) { }
   

      // Getters
      double getDegrees() const { return radians * (180 / M_PI); }
      double getRadians() const { return radians; }

      // Setters
      void setDegrees(double degrees) 
      { 
         degrees = (degrees * (2.0 * M_PI)) / 360;
         radians = normalize(degrees); 
      }

      void setRadians(double aRadian)
      {
         radians = normalize(aRadian);
      }

      void setUp()
      {
         // 0°
         setDegrees(0.0);
      }

      void setRight()
      {
         // 90°
         setDegrees(90.0);
      }

      void setLeft()
      {
         // 270°
         setDegrees(270.0);
      }

      void setDown() 
      {
         // 180°
         setDegrees(180.0);
      }

      void reverse() 
      {
         radians += M_PI;
      }

	   Angle& add(double delta) 
      {
		   radians += delta;

         // Normalize the angle after addition
		   radians = normalize(radians);  

		   return *this;
	   }

   private:
      double normalize(double radians);

      double radians;
      // 360 degrees equals 2 PI radians
};

