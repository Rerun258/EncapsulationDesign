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

class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;

   // Constructors
   Angle() : radians(0.0) {}
   Angle(const Angle& rhs) : radians(rhs.getRadians()) {}
   Angle(double degrees) { setDegrees(degrees); }

   Angle& add(double delta)
   {
      radians += delta;
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
      return round(normalize(aRadian) * (180.0 / M_PI));
   }

   double convertToRadians(double aDegree) const
   {
      return normalize(aDegree * (M_PI / 180.0));
   }

   void setUp() { radians = 0.0; }
   void setRight() { radians = M_PI * 0.5; }
   void setLeft() { radians = M_PI * 1.5; }
   void setDown() { radians = M_PI; }
   void reverse() { radians += M_PI; }

   void display(ostream& out) const
   {
      out.setf(ios::fixed);
      out.setf(ios::showpoint);
      out.precision(1);
      out << getDegrees() << " degrees";
   }

private:
   double normalize(double aRadian) const;
   double radians;
};
