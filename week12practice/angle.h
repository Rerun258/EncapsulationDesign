/*************************************************************
 * 1. Name:
 *      -your name-
 * 2. Module
 *      ANGLE
 * 3. Assignment Description:
 *      A class to represent an angle
 **************************************************************/

#pragma once

#define M_PI 3.14159265358979323846
#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include <cmath>
using namespace std;

class TestAngle;

/*****************************************
  * ANGLE
*****************************************/
class Angle
{
   friend TestAngle;

   // Angle, stored in radians.
   double radians;

public:

   double getDegrees()
   {
      double degrees = radians * (180 / M_PI);
      return degrees;
   }

   double getRadians()
   {
      return radians;
   }

   void setDegrees(double aDegree)
   {
      radians = normalize(convertToRadians(aDegree));
   }

   void setRadians(double aRadian)
   {
      radians = normalize(aRadian);
   }

   void display(ostream& out)
   {
      out.setf(ios::fixed);     // "fixed" means don't use scientific notation.
      out.setf(ios::showpoint); // "showpoint" means always show the decimal point.
      out.precision(1);         // Set the precision to 1 decimal place of accuracy.
      //cout << getDegrees() << endl; test code
      out << getDegrees() << "degrees";
   }

private:

   double normalize(double aRadian)
   {
      while (aRadian > TWO_PI)
      {
         aRadian -= TWO_PI;
      }

      while (aRadian < 0)
      {
         aRadian += TWO_PI;
      }

      return aRadian;
   }

   double convertToDegrees(double aRadian)
   {
      double degrees = round(normalize(aRadian) * (180 / M_PI));
      return degrees;
   }

   double convertToRadians(double aDegree)
   {
      double radians = aDegree * (M_PI / 180);
      return normalize(radians);
   }

};
