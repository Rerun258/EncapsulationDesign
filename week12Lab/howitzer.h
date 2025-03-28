/**********************************************************************
 * Header File:
 *    HOWITZER
 * Author:
 *    McClain, Elijah
 * Summary:
 *    Everything we need to know about a howitzer (aka the gun)
 ************************************************************************/

#pragma once

#include <list>
#include "angle.h"
#include "position.h"
#include "velocity.h"
#include "physics.h"
#include "uiDraw.h"


#pragma once

#define DEFAULT_MUZZLE_VELOCITY   827.00     // m/s


class TestHowitzer;

 /*********************************************
  * Howitzer
  * Everything we need to know about a howitzer (aka the gun)
  *********************************************/
class Howitzer
{
   public:
      // For unit tests
      friend::TestHowitzer;

      // Constructor
      Howitzer() : muzzleVelocity(DEFAULT_MUZZLE_VELOCITY), elevation(45.0) {}

      // Draw
      void draw(ogstream& gout, double flightTime) const
      {
         gout.drawHowitzer(position,
            elevation.getRadians(),
            flightTime);
      }

      // Where is the howitzer at right now?
      Position & getPosition() { return position; }

      // Generate a new position for the howitzer.
      void generatePosition(const Position& posUpperRight)
      {
         double xPixels = random(posUpperRight.getPixelsX() * 0.1,
            posUpperRight.getPixelsX() * 0.9);
         position.setPixelsX(xPixels);
         position.setPixelsY(0);
      }

      // Get the muzzle velocity.
      double getMuzzleVelocity() const { return muzzleVelocity; }

      // Move the angle of the howitzer.
      void rotate(double radian) { elevation.add(radian); }

      // Raise (or lower) the howitzer.
      void raise(double radian)
      {
         elevation.add(elevation.isRight() ? -radian : radian);
      }

      // Get the elevation.
      const Angle & getElevation() const { return elevation; }

   private:
      Position position;      // initial position of the projectile
      double muzzleVelocity;  // muzzle velocity, defaults to 827.0 m/s
      Angle elevation;        // the elevation of the howitzer where 0 is up and positive is right.
};