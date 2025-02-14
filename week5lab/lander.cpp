/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"


 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   angle.setUp();
   status = PLAYING;
   fuel = 5000.0;
   velocity.setDX(random(-10.0, -4.0));
   velocity.setDY(random(-2.0, 2.0));
   pos.setX(posUpperRight.getX() - 1.0);
   pos.setY(random((posUpperRight.getY() * 0.75), (posUpperRight.getY() * 0.95)));
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   gout.drawLander(pos, angle.getRadians());
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander::input(const Thrust& thrust, double gravity)
{
   double ax = 0.0;
   double ay = 0.0;

   // Use the public method to check if the main engine is active
   if (thrust.isMain() && fuel > 0)
   {
      // Calculate thrust components using angle
      ax = thrust.mainEngineThrust() * cos(angle.getRadians());
      ay = thrust.mainEngineThrust() * sin(angle.getRadians()) - gravity;

      // Reduce fuel
      fuel -= 10.0;
      if (fuel < 0)
      {
         fuel = 0;  // Prevent negative fuel
      }
   }
   else
   {
      // When the main engine is off, only gravity affects the vertical acceleration
      ay = -gravity;
   }

   Acceleration acceleration(ax, ay);
   return acceleration;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander :: coast(Acceleration & acceleration, double time)
{
   // Update position based on current velocity and acceleration
   pos.setX(pos.getX() + velocity.getDX() * time + 0.5 * acceleration.getDDX() * time * time);
   pos.setY(pos.getY() + velocity.getDY() * time + 0.5 * acceleration.getDDY() * time * time);

   // Update velocity based on acceleration
   velocity.setDX(velocity.getDX() + acceleration.getDDX() * time);
   velocity.setDY(velocity.getDY() + acceleration.getDDY() * time);
}
