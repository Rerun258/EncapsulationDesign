/***********************************************************************
 * Header File:
 *    Thrust : Represents activation of thrusters
 * Author:
 *    Br. Helfrich
 * Summary:
 *    down, clockwise, and counterclockwise
 ************************************************************************/

#pragma once

#include "uiInteract.h"  // for Interface

class TestLander;
class TestThrust;

 /*****************************************************
  * THRUST
  * Represents activation of thrusters
  *****************************************************/
class Thrust
{
   friend TestLander;
   friend TestThrust;
   
public:
   // Thrust is initially turned off
   Thrust() : mainEngine(false), clockwise(false), counterClockwise(false) {}

   // Get rotation in radians per second
   double rotation() const
   {
      if (clockwise && counterClockwise)
      {
         return 0.0;  // No rotation if both are true
      }
      else if (clockwise)
      {
         return 0.1;  // Rotation value when clockwise is true
      }
      else if (counterClockwise)
      {
         return -0.1;  // Rotation value when counterClockwise is true
      }

      return 0.0;  // No rotation
   }

   // get main engine thrust in  m / s ^ 2
   double mainEngineThrust() const
   {
      const double force = 45000.0;  // Force in Newtons
      const double mass = 15103.0;   // Mass in kilograms
      return force / mass;           // Acceleration in m/s^2
   }

   // reflect what is firing
   bool isMain()    const { return mainEngine; }
   bool isClock()   const { return clockwise; }
   bool isCounter() const { return counterClockwise; }

   // set the thrusters
   void set(const Interface * pUI)
   {
      mainEngine       = true;
      clockwise        = true;
      counterClockwise = true;
   }

private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
};
