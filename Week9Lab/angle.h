/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    McClain, Elijah
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestHowitzer;
class TestProjectile;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   // for the unit tests
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestHowitzer;
   friend TestProjectile;

   // Constructors
   Angle()                  : radians(0)         {}
   Angle(const Angle& rhs)  : radians(rhs.getRadians())         {}
   Angle(double degrees)
   {
      setDegrees(degrees);
   }

   // Getters
   double getDegrees() const { return radians * (180.0 / M_PI); }
   double getRadians() const { return radians; }

   //         dx
   //    +-------/
   //    |      /
   // dy |     /
   //    |    / 1.0
   //    | a /
   //    |  /
   //    | /
   // dy = cos a
   // dx = sin a
   double getDx() const { return sin(radians); }
   double getDy() const { return cos(radians); }
   bool   isRight() const 
   { 
      if (radians == 1.5 * M_PI) {
			return true;
      }
			
      return false; 
   }
   
   bool   isLeft() const
   {
      if (radians == 0.5 * M_PI)
      {
         return true;
      }

      return false; 
   }


   // Setters
   void setDegrees(double degrees) 
   {
      degrees = (degrees * (2.0 * M_PI)) / 360.0; 
      radians = normalize(degrees); 
   }

   void setRadians(double aRadian) { radians = normalize(aRadian); } 

   // 0°
   void setUp(){ radians = 0.0;}

   // 90°
   void setRight(){ radians = M_PI * 1.5;}

   // 270°
   void setLeft(){ radians = M_PI * .5;}

   // 180°
   void setDown(){ radians = M_PI;}

   void reverse(){ radians += M_PI; }
   
   Angle& add(double delta)
   {
      radians += delta;
		radians = normalize(radians);
      return *this;
   }

   // set based on the components
   //         dx
   //     +-------/
   //     |      /
   //  dy |     /
   //     |    /
   //     | a /
   //     |  /
   //     | /
   void setDxDy(double dx, double dy)  
   {
		radians = atan2(dy, dx);
   }
   
   Angle operator+(double degrees) const { return Angle(); }

private:

   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
   out << rhs.getDegrees() << "degree";
   return out;
}
