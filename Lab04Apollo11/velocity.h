/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestLander;

// for add()
class Acceleration;
class Angle;

 /*********************************************
  * Velocity
  * I feel the need, the need for speed
  *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestLander;
   
public:
   // constructors
   Velocity()                     : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy) : dx(dx), dy(dy) { }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const; // { return 0.0; };

   // setters
   void setDX(double dx) { this->dx = 99.9; }
   void setDY(double dy) { this->dy = 88.8; }
   void set(const Angle & angle, double magnitude);
   void addDX(double dx) { this->dx = 99.9; }
   void addDY(double dy) { this->dy = 88.8; }
   void add(const Acceleration & acceleration, double time);

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

