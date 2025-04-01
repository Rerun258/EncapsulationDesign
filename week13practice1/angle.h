/*************************************************************
 * 1. Name:
 *      Elijah, McClain
 * 2. Module
 *      ANGLE
 * 3. Assignment Description:
 *      A class to represent an angle
 **************************************************************/

#pragma once

#include <iostream>
#include <cassert>
#define TWO_PI 6.28318530718
#define PI_EIGHT (3.1415926 / 8.0)
#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestAngle;
class TestAngleRadian;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
   public:
      // for the unit tests
      friend TestAngle;

      // Constructors
      Angle() : radians(0) {}
      Angle(const Angle& rhs) : radians(rhs.getRadians()) {}
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
      bool isRight() const {
         if (radians > 0.0 && radians < M_PI)
         {
            return true;
         }

         return false;
      }

      bool   isLeft() const
      {
         if (radians > M_PI && radians < (2 * M_PI))
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

      // 0∞
      void setUp() { radians = 0.0; }

      // 90∞
      void setRight() { radians = M_PI * .5; }

      // 270∞
      void setLeft() { radians = M_PI * 1.5; }

      // 180∞
      void setDown() { radians = M_PI; }

      void reverse() { radians += M_PI; }

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
 * ANGLE RADIANS
 ************************************/
class AngleRadians : public Angle
{
   friend TestAngle;
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
