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
#include <cmath>
using namespace std;

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
      friend TestAngleRadian;
      friend ostream& operator<<(ostream& out, const Angle& rhs);
      friend istream& operator>>(istream& in, const Angle& rhs);
      friend Angle& operator++(Angle& rhs);
      friend Angle& operator--(Angle& rhs);

      // Constructors
      Angle() : radians(0.0) {}

      Angle(const Angle& rhs) : radians(rhs.getRadians()) {}

      Angle(double degrees)
      {
         setDegrees(degrees);
      }

      Angle operator +(const Angle& rhs) const { return Angle(radians + rhs.radians); }
      Angle operator -(const Angle& rhs) const { return Angle(radians - rhs.radians); }

      Angle& operator +=(const Angle& rhs)
      {
         radians += rhs.radians;

         // Normalize the angle after addition
         radians = normalize(radians);

         return *this;
      }

      Angle& operator -=(const Angle& rhs)
      {
         radians -= rhs.radians;

         // Normalize the angle after addition
         radians = normalize(radians);

         return *this;
      }

      Angle& operator =(const Angle& rhs)
      {
         radians = rhs.radians;
         return *this;
      }

      // Why not just ==? Oh well, 2 less errors.
      bool operator ==(const Angle& rhs) const { return radians == rhs.radians; }
      bool operator !=(const Angle& rhs) const { return radians != rhs.radians; }

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
         // 0°
         radians = 0.0;
      }

      void setRight()
      {
         // 90°
         radians = M_PI * 0.5;
      }

      void setLeft()
      {
         // 270°
         radians = M_PI * 1.5;
      }

      void setDown()
      {
         // 180°
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
   double normalize(double aRadian) const
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

   // 360 degrees equals 2 PI radians
   double radians;
};

ostream& operator<<(ostream& out, const Angle& rhs)
{
   out << rhs.radians;
   return out;
}

istream& operator>>(istream& in, const Angle& rhs)
{
   in >> rhs.radians;
   rhs.normalize(rhs.radians);
   return in;
}

Angle& operator++(Angle& rhs)
{
   rhs.radians += 1.0;
   rhs.normalize(rhs.radians);
   return rhs;
}

Angle& operator--(Angle& rhs)
{
   rhs.radians -= 1.0;
   rhs.normalize(rhs.radians);
   return rhs;
}


/************************************
 * ANGLE RADIANS
 ************************************/
class AngleRadians : public Angle
{
   friend TestAngle;

   public:
      AngleRadians() : Angle() {}
      AngleRadians(double radians) { setRadians(radians); }
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
