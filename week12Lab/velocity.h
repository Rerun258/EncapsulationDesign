/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Elijah, McClain
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once
#include "acceleration.h"
#include "angle.h"

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestProjectile;

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
   friend TestProjectile;


public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   Velocity(const Velocity& rhs) : dx(rhs.dx), dy(rhs.dy) {}
   Velocity& operator = (const Velocity& rhs)
   {
      dx = rhs.dx;
      dy = rhs.dy;
      return *this;
   }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;
   Angle  getAngle()    const;

   // setters
   void set(const Angle& angle, double magnitude);
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void setDXDY(double dx, double dy) { this->dx = dx; this->dy = dy; }
   void addDX(double dx) { setDX(getDX() + dx); }
   void addDY(double dy) { setDY(getDY() + dy); }
   void add(const Acceleration& acceleration, double time);
   void addV(const Velocity& rhs)
   {
      this->dx += rhs.getDX();
      this->dy += rhs.getDY();
   }

   Velocity& operator +=(const Velocity& rhs)
   {
      addV(rhs);
      return *this;
   }

   void reverse()
   {
      dx *= -1.0;
      dy *= -1.0;
   }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

