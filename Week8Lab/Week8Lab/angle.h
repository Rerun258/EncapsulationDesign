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


/************************************
 * ANGLE
 ************************************/
class Angle
{
public:

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
      return normalize(aRadian) * (180.0 / M_PI);
   }

   double convertToRadians(double aDegree) const
   {
      return normalize(aDegree * (M_PI / 180.0));
   }


private:
   double normalize(double aRadian) const;
   double radians;
};
