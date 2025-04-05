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
#include "angle.h"
#include "acceleration.h"
#include "cassert"
#include "unitTest.h"
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
      if (!flying())
         return;

      PositionVelocityTime pvt = flightPath.back();
      double speed = pvt.v.getSpeed();
      double altititude = pvt.pos.getMetersY();
      double interval = simulationTime - currentTime();
      assert(interval > 0.0);

      double density = densityFromAltitude(altititude);
      double speedSound = speedSoundFromAltitude(altititude);
      double mach = speed / speedSound;
      double dragCoefficient = dragFromMach(mach);
      double windResistence = forceFromDrag(density, dragCoefficient, radius, speed);
      double magnitudeWind = accelerationFromForce(windResistence, mass);
      //pvt.v.reverse();
      
      Acceleration aWind(-pvt.v.getAngle(), magnitudeWind);

      double magnitudeGravity = gravityFromAltitude(altititude);
      Angle angleGravity;
      angleGravity.setDown();
      Acceleration aGravity(angleGravity, magnitudeGravity);
      
      Acceleration aTotal = aGravity + aWind;
      std::cout << std::fixed << std::setprecision(7);
      
      //cout << "\n\nBefore";
      //cout << "aTotal.ddx: " << aTotal.getDDX() << endl;
      //cout << "aTotal.ddy: " << aTotal.getDDY() << endl;
      //cout << "aGravity: " << aGravity.getDDX() << endl;
      //cout << "aGravity: " << aGravity.getDDY() << endl;
      //cout << "aWind: " << aWind.getDDX() << endl;
      //cout << "aWind: " << aWind.getDDX() << endl;
      //cout << "\n\n";

      pvt.pos.add(aTotal, pvt.v, interval);
      pvt.v.add(aTotal, interval);
      pvt.t = simulationTime;


      //cout << "\n\nAfter";
      //cout << "aTotal.ddx: " << aTotal.getDDX() << endl;
      //cout << "aTotal.ddy: " << aTotal.getDDY() << endl;
      //cout << "aGravityX: " << aGravity.getDDX() << endl;
      //cout << "aGravityY: " << aGravity.getDDY() << endl;
      //cout << "aWindX: " << aWind.getDDX() << endl;
      //cout << "aWindY: " << aWind.getDDY() << endl;
      //cout << "\n\n";

      flightPath.push_back(pvt);
   }

   void fire(const Position& pos, double simulationTime, const Angle& elevation, double muzzleVelocity)
   {
      reset();

      PositionVelocityTime pvt;
      pvt.pos = pos;
      pvt.t = simulationTime;
      pvt.v.set(elevation, muzzleVelocity);
      flightPath.push_back(pvt);
   }

   void reset()
   {
      flightPath.clear();
      mass = DEFAULT_PROJECTILE_WEIGHT;
      radius = DEFAULT_PROJECTILE_RADIUS;
   }

   void draw(ogstream& gout)
   {
      for (auto it = flightPath.cbegin(); it != flightPath.cend(); ++it)
         gout.drawProjectile(it->pos, currentTime() - it->t);
   }

   bool flying() const { return !flightPath.empty(); }

   double getAltitude() const { return flying() ? flightPath.back().pos.getMetersY() : 0.0; }

   Position getPosition() const { return flying() ? flightPath.back().pos : Position(); }

   double getFlightTime() const
   {
      return (flightPath.size() >= 2) ? flightPath.back().t - flightPath.front().t : 0.0;
   }

   double getFlightDistance() const
   {
      return (flightPath.size() >= 2) ?
         abs(flightPath.front().pos.getMetersX() - flightPath.back().pos.getMetersX()) : 0.0;
   }

   double getSpeed() const { return flying() ? flightPath.back().v.getSpeed() : 0.0; }

   double currentTime() const { return flying() ? flightPath.back().t : 0.0; }

   void setMass(double mass) { this->mass = mass; }

   void setRadius(double radius) { this->radius = radius; }

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