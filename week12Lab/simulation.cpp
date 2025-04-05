/**********************************************************************
 * Suurce File:
 *    SIMULATION
 * Author:
 *    McClain, Elijah
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

 #include "simulation.h"  // for SIMULATION
#include "position.h"
#include "howitzer.h"
#include "projectile.h"
#include "ground.h"
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <cmath>
#include <vector>
#include <cassert>

// Reset variables
void Simulator::reset()
{
   howitzer.generatePosition(posUpperRight);
   ground.reset(howitzer.getPosition());
   projectile.reset();
   simTime = 0.0;
   targetXKM = ground.getTarget().getMetersX() / 1000.0;
   targetYKM = ground.getTarget().getMetersY() / 1000.0;
}

// Display items
void Simulator::display()
{
   ogstream gout;

   ground.draw(gout);
   howitzer.draw(gout, 50.0);
   projectile.draw(gout);

   displayStatus();
}

// Display stats
void Simulator::displayStatus()
{
   ogstream gout;

   Position goutPos;
	goutPos.setPixelsX(450.0);
	goutPos.setPixelsY(450.0);
   gout.setPosition(goutPos);

   gout << "Target: " << targetXKM << ", " << targetYKM << " (KM)" << endl;
   gout << "Altitude: " << projectile.getAltitude() << endl;
   gout << "Speed: " << projectile.getSpeed() << " (M/S)" << endl;
   gout << "Hang time: " << projectile.getFlightTime() << endl;
   gout << "Distance: " << projectile.getFlightDistance() << " (M)" << endl;
}

void Simulator::gamePlay()
{
   // Check flight status
   if (projectile.flying())
   {  
      simTime += timeIncrement;

      // Does the projectile hit within the range? (50m)
      if (((projectile.getPosition().getMetersX() <= ground.getTarget().getMetersX() + 50.0)
            && (projectile.getPosition().getMetersX() >= ground.getTarget().getMetersX() - 50.0))
            && (projectile.getPosition().getMetersY() <= ground.getTarget().getMetersY() + 50.0)
            && (projectile.getPosition().getMetersY() >= ground.getTarget().getMetersY() - 50.0))
         {
            reset(); 
         }
         

      // If projectile goes out of bounds (either x, below y)
      if (projectile.getPosition().getMetersX() > 28000.00
            || projectile.getPosition().getMetersX() < 0.0
            || projectile.getPosition().getMetersY() < 0.0)
      {
         reset();
      }

      
      projectile.advance(simTime);
   }

}

// Accept user input
void Simulator::input(const Interface* pUI)
{
   // Fire!
   if (pUI->isSpace() && !projectile.flying())
   {
      projectile.fire(howitzer.getPosition(),
         simTime,
         howitzer.getElevation(),
         howitzer.getMuzzleVelocity());
   }

   // Rotate
   if (pUI->isRight() || pUI->isUp())
      howitzer.rotate(+0.05);

   if (pUI->isLeft() || pUI->isDown())
      howitzer.rotate(-0.05);

   // Quit
   if (pUI->isQ())
      exit(0);
      
}