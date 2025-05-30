/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/


#pragma once

#include <math.h>   // for M_PI which is 3.14159
#include <ostream>
#include <iostream>

using namespace std;

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define TWO_PI 6.28318530718

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
   Angle() : radians(0.0) {}

   Angle(const Angle& rhs) : radians(rhs.getRadians()) {}

   Angle(double degrees) 
   {
      setDegrees(degrees);
   }

   Angle& add(double delta)
   {
      radians += delta;

      // Normalize the angle after addition
      radians = normalize(radians);

      return *this;
   }

   // Getters
   double getDegrees() const { return radians * (180.0 / M_PI); }
   double getRadians() const { return radians; }


   // Setters
   void setDegrees(double degrees)
   {
      degrees = (degrees * (2.0 * M_PI)) / 360.0;
      radians = normalize(degrees);
   }

   void setRadians(double aRadian) { radians = normalize(aRadian); }


   // Converters
   double convertToDegrees(double aRadian) const
   {
      double degrees = round(normalize(aRadian) * (180.0 / M_PI));
      return degrees;
   }

   double convertToRadians(double aDegree) const
   {
      double radians = aDegree * (M_PI / 180.0);
      return normalize(radians);
   }

   void setUp()
   {
      // 0�
      radians = 0.0;
   }

   void setRight()
   {
      // 90�
      radians = M_PI * 0.5;
   }

   void setLeft()
   {
      // 270�
      radians = M_PI * 1.5;
   }

   void setDown()
   {
      // 180�
      radians = M_PI;
   }

   void reverse()
   {
      radians += M_PI;
   }

   void display(ostream& out) const
   {
      out.setf(ios::fixed);     // "fixed" means don't use scientific notation.
      out.setf(ios::showpoint); // "showpoint" means always show the decimal point.
      out.precision(1);         // Set the precision to 1 decimal place of accuracy.
      //cout << getDegrees() << endl; test code
      out << getDegrees() << "degrees";
   }


private:
   double normalize(double aRadian) const;

   double radians;
   // 360 degrees equals 2 PI radians
};


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