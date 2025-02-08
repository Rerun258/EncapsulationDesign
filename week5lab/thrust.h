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
      if (Interface::isLeft())
      {
         return -0.1;  // Rotation value when the left key is pressed
      }
      else if (Interface::isRightPress())
      {
         return 0.1;  // Rotation value when the right key is pressed
      }

      return 0.0;  // No rotation
   }

   // get main engine thrust in  m / s ^ 2
   double mainEngineThrust() const
   {
      return 99.9;
   }

   // reflect what is firing
   bool isMain()    const { return true; }
   bool isClock()   const { return true; }
   bool isCounter() const { return true; }

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
