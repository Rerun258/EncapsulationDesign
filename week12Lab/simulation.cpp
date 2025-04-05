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
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <cmath>
#include <vector>
#include <cassert>


void Simulator::reset()
{
   howitzer.generatePosition(posUpperRight);
   ground.reset(howitzer.getPosition());
   projectile.reset();
   simTime = 0.0;
}

void Simulator::display()
{
   ogstream gout;

   ground.draw(gout);
   howitzer.draw(gout, 50.0);
   projectile.draw(gout);

   displayStatus();
}

void Simulator::displayStatus()
{
   ogstream gout;

   Position goutPos;
	goutPos.setPixelsX(450.0);
	goutPos.setPixelsY(500.0);
   gout.setPosition(goutPos);

   projectileXKM = projectile.getPosition().getMetersX() / 1000.0;
   projectileYKM = projectile.getPosition().getMetersY() / 1000.0;

   targetXKM = ground.getTarget().getMetersX() / 1000.0;
   targetYKM = ground.getTarget().getMetersY() / 1000.0;

   gout << "Altitude: " << projectile.getAltitude() << endl;
   gout << "Target: " << targetXKM << ", " << targetYKM << " (KM)" << endl;
   gout << "Projectile (POS): " << projectileXKM << ", " << projectileYKM << " (KM)" << endl;
   gout << "Projectile (SPEED): " << projectile.getSpeed() << " (M/S)" << endl;
}

void Simulator::gamePlay()
{
   if (projectile.flying())
   {  
      simTime += timeIncrement;

      if ((projectile.getPosition().getMetersX() == ground.getTarget().getMetersX()) && 
            (projectile.getPosition().getMetersY() == ground.getTarget().getMetersY()))
      { 
         reset(); 
      }

      if (projectile.getPosition().getMetersX() > 30000.00
            || projectile.getPosition().getMetersX() < 0.0
            || projectile.getPosition().getMetersY() < 0.0)
      {
         reset();
      }

      projectile.advance(simTime);
   }

}

void Simulator::input(const Interface* pUI)
{
   if (pUI->isSpace() && !projectile.flying())
   {
      projectile.fire(howitzer.getPosition(),
         simTime,
         howitzer.getElevation(),
         howitzer.getMuzzleVelocity());
   }

   if (pUI->isRight() || pUI->isUp())
      howitzer.rotate(+0.05);

   if (pUI->isLeft() || pUI->isDown())
      howitzer.rotate(-0.05);

   if (pUI->isQ())
      exit(0);
      
}