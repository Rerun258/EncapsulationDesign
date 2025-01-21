/*************************************************************
 * 1. Name:
 *      Elijah, McCain
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#pragma once

#define M_PI 3.14159265358979323846
#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
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

      /*****************************************
      * GET RADIANS
      * Takes no parameters and return the angle in degrees.
      *
      * OUTPUT:
      *  angle, in degrees
      ******************************************/
      double getDegrees()
      {
         return convertToDegrees(radians);
      }

      /*****************************************
      * GET RADIANS
      * Takes no parameters and return the angle in radians.
      *
      * OUTPUT:
      *  angle, in radians
      ******************************************/
      double getRadians()
      {
         return radians;
      }

      /*****************************************
      * SET DEGREES
      * Takes a degrees as a parameter and updates the attribute
      * with the passed parameter. If the parameter is above 360 or
      * below zero, then it will "unwrap" so the radians is between
      * 0 and 2PI
      *
      * INPUT:
      *  aDegree: angle in degrees
      ******************************************/
      void setDegrees(double aDegree)
      {
         radians = normalize(convertToRadians(aDegree));
      }

      /*****************************************
      * SET RADIANS
      * Takes a radian as a parameter and updates the attribute
      * with the passed parameter. If the parameter is above 2PI
      * or below zero, then it will "unwrap."
      *
      * INPUT:
      *  aRadian: angle in radians
      ******************************************/
      void setRadians(double aRadian)
      {
         radians = normalize(aRadian);
      }

      /*****************************************
      * DISPLAY
      * Takes a ostream & out as a parameter display the value,
      * in degrees, to 1 decimal place of accuracy.
      *
      * OUTPUT:
      *  Prints to console.
      ******************************************/
      void display(ostream &out)
      {
         cout.setf(ios::fixed);     // "fixed" means don't use scientific notation.
         cout.setf(ios::showpoint); // "showpoint" means always show the decimal point.
         cout.precision(1);         // Set the precision to 1 decimal place of accuracy.

         out << getDegrees();
      }

   private:

      /*****************************************
      * NORMALIZE
      * Takes a radian as a parameter and reduce it to between 0 and 2PI.
      *
      * INPUT:
      *  aRadian: angle in radians
      *
      * OUTPUT:
      *  aRadian: normalized radians
      ******************************************/
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

      /*****************************************
      * CONVERT TO DEGREES
      * Takes a radians as a parameter and returns degrees.
      *
      * INPUT:
      *  aRadian: angle in radians
      *
      * OUTPUT:
      *  degrees: angle in degrees
      ******************************************/
      double convertToDegrees(double aRadian)
      {
         double degrees = aRadian * (180 / M_PI);
         return degrees;
      }

      /*****************************************
      * CONVERT TO RADIANS
      * Takes a degrees as a parameter and returns radians.
      *
      * INPUT:
      *  aDegree: angle in degrees
      *
      * OUTPUT:
      *  radians: angle in radians
      ******************************************/
      double convertToRadians(double aDegree)
      {
         double radians = aDegree * (M_PI / 180);
         return radians;
      }

};