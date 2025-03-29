/**********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    Elijah, McClain
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include <list>
#include "position.h"
#include "velocity.h"
#include "physics.h"
#include "uiDraw.h"

#define DEFAULT_PROJECTILE_WEIGHT 46.7       // kg
#define DEFAULT_PROJECTILE_RADIUS 0.077545   // m

// Forward declaration for the unit test class.
class TestProjectile; 

 /**********************************************************************
  * Projectile
  *    Everything we need to know about a projectile
  ************************************************************************/
class Projectile
{
public:
   // Friend the unit test class
   friend::TestProjectile;

   // Create a new projectile with the default settings.
   Projectile() : mass(DEFAULT_PROJECTILE_WEIGHT), radius(DEFAULT_PROJECTILE_RADIUS) {}

   Projectile(double mass, double radius) { this->mass = mass; this->radius = radius; }

   // Advance the round forward until the next unit of time.
   void advance(double simulationTime) 
   {
      if (flightPath.empty())
         flightPath.push_back(PositionVelocityTime());

      PositionVelocityTime lastState = flightPath.back();

      Acceleration a;

      PositionVelocityTime newState;
      newState.t = lastState.t + simulationTime;
      newState.v = lastState.v;
      newState.pos.add(a, newState.v, newState.t);

      flightPath.push_back(newState);
      
   }

   void fire()
   {

   }

   void reset() 
   {
       mass = DEFAULT_PROJECTILE_WEIGHT;
       radius = DEFAULT_PROJECTILE_RADIUS;
       flightPath.clear();
   }




private:

   // Keep track of one moment in the path of the projectile.
   struct PositionVelocityTime
   {
      PositionVelocityTime() : pos(), v(), t(0.0) {}
      Position pos;
      Velocity v;
      double t;
   };

   double mass;           // weight of the M795 projectile. Defaults to 46.7 kg
   double radius;         // radius of M795 projectile. Defaults to 0.077545 m
   std::list<PositionVelocityTime> flightPath;
};