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
using namespace std;

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

   // Advance the round forward until the next unit of time.
   void advance(double simulationTime)
   {
      // Ensure flightPath has at least one initial state
      if (flightPath.empty())
         flightPath.push_back(PositionVelocityTime());

      PositionVelocityTime lastState = flightPath.back();
      double t = lastState.t; // Start from the last recorded time
      const double timeStep = 1.0; // Define time step for clarity

      // Iterate through each time step up to simulationTime
      for (; t < simulationTime ; t += timeStep)
      {
         // Initialize new state for the next time step
         PositionVelocityTime newState;

         // Calculate density based on the current altitude
         double density = densityFromAltitude(lastState.pos.getMetersY());

         // Compute drag forces in x and y directions
         double dragForceX = forceFromDrag(density, 0.047, radius, lastState.v.getDX());
         double dragForceY = forceFromDrag(density, 0.047, radius, lastState.v.getDY());

         // Compute accelerations from drag forces
         double accelerationX = accelerationFromForce(dragForceX, mass);
         double accelerationY = accelerationFromForce(dragForceY, mass);

         // Update position
         double newX = lastState.pos.getMetersX() + lastState.v.getDX() * timeStep + 0.5 * accelerationX * timeStep * timeStep;
         double newY = lastState.pos.getMetersY() + lastState.v.getDY() * timeStep + 0.5 * accelerationY * timeStep * timeStep;

         // Update velocity
         double newDX = lastState.v.getDX() + accelerationX * timeStep;
         double newDY = lastState.v.getDY() + accelerationY * timeStep;

         // Assign updated values to newState
         newState.pos.setMetersX(newX);
         newState.pos.setMetersY(newY);
         newState.v.setDX(newDX);
         newState.v.setDY(newDY);
         newState.t = lastState.t + timeStep;
         // Add the new state to the flight path
         flightPath.push_back(newState);


         

         // Update lastState for the next iteration
         lastState = flightPath.back();
      }
      
   }

   void fire(const Position& pos, double simulationTime, const Angle& elevation, double muzzleVelocity)
   {
      flightPath.clear();

      PositionVelocityTime pvt;
      pvt.t = simulationTime;
      pvt.v = muzzleVelocity;
      pvt.pos = pos;

      flightPath.push_back(pvt);
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