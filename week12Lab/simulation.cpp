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

   //gout.precision(2);
   gout << "Altitude: " << projectile.getAltitude() << endl;
   gout << "Target: " << ground.getTarget().getMetersX() << ", " << ground.getTarget().getMetersY() << endl;
   gout << "Projectile (POS): " << projectile.getPosition().getMetersX() << ", " << projectile.getPosition().getMetersY() << endl;
	gout << "Projectile (SPEED): " << projectile.getSpeed() << endl;
}

void Simulator::gamePlay()
{
   if (projectile.flying())
   { 
      static double simTime = 0.0;
      double timeIncrement = 0.1;
      simTime += timeIncrement;

      if ((projectile.getPosition().getMetersX() == ground.getTarget().getMetersX()) && 
            (projectile.getPosition().getMetersY() == ground.getTarget().getMetersY()))
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
         0.0,
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