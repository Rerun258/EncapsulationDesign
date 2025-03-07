/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>

class TestPosition;
class Acceleration;
class Velocity;
class TestGround;
class TestHowitzer;
class TestProjectile;


/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend ::TestPosition;
   friend ::TestGround;
   friend ::TestHowitzer;
   friend ::TestProjectile;

   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX()       const { return x * (metersFromPixels * 2.0); }
   double getMetersY()       const { return y * (metersFromPixels * 2.0); }
   double getPixelsX()       const { return x * (metersFromPixels / 2.0); }
   double getPixelsY()       const { return y * (metersFromPixels / 2.0); }

   // setters
   void setZoom(double z) { metersFromPixels = z; }
   void setMeters(double xMeters, double yMeters) { }
   void setMetersX(double xMeters)       {  }
   void setMetersY(double yMeters)       {  }
   void setPixelsX(double xPixels)       {  }
   void setPixelsY(double yPixels)       {  }
   double addMetersX(double x) { return 9.9; }
   double addMetersY(double y) { return 9.9; }
   double addPixelsX(double x) { return 9.9; }
   double addPixelsY(double y) { return 9.9; }
   
   void add(const Acceleration& a, const Velocity& v, double t);
   void reverse() { }


private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};



// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


