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

   // The velocity is random.
   velocity.setDX(random(-10.0, -4.0));
   velocity.setDY(random(-2.0, 2.0));

   // The position is at the righthand side of the screen.
   pos.setX(posUpperRight.getX() - 1.0);
   pos.setY(random(posUpperRight.getY() * 0.75, posUpperRight.getY() * 0.95));

   // Status is playing.
   status = PLAYING;

   // Fueled up and ready to go.
   fuel = FUEL_MAX;
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   // Make the lander exist in space.
   gout.drawLander(pos, angle.getRadians());

   // Only fire engines if we are still firing.
   if (isFlying() && fuel > 0.0)
      gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), 
         thrust.isClock(), thrust.isCounter());
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander::input(const Thrust& thrust, double gravity)
{
   Acceleration a;

   a.addDDY(gravity);

   // pffftttttt (we're out of fuel)
   if (fuel == 0.0)
      return a;

   // Main engines.
   if (thrust.isMain())
   {
      double lt = LANDER_THRUST;
      double lw = LANDER_WEIGHT;
      double power = (lt / lw);
      a.addDDX(-sin(angle.getRadians()) * power);
      a.addDDY(cos(angle.getRadians()) * power);
      fuel = FUEL_MAIN_THRUST;
   }

   // Clockwise
   if (thrust.isClock())
   {
      angle.add(0.1);
      fuel -= FUEL_ROTATE;
   }

   // Counter-clockwise
   if (thrust.isCounter())
   {
      angle.add(-0.1);
      fuel -= FUEL_ROTATE;
   }

   if (fuel < 0.0)
      fuel = 0.0;

   return a;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander :: coast(Acceleration & acceleration, double time)
{
   // Update position based on current velocity and acceleration
   pos.add(acceleration, velocity, time);

   // Update velocity based on acceleration
   velocity.add(acceleration, time);
}
