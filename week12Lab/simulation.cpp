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
   goutPos.setPixelsX(200.0);
   goutPos.setPixelsY(370.0);
   gout.setPosition(goutPos);

   gout.precision(2);
   gout << "Altitude: " << projectile.getAltitude() << endl;
   gout << "Target: " << ground.getTarget().getPixelsX() << ", " << ground.getTarget().getPixelsY() << endl;
   gout << "Projectile : " << projectile.getPosition().getPixelsX() << ", " << projectile.getPosition().getPixelsY() << endl;

}

void Simulator::gamePlay()
{
   if (projectile.flying())
   { 
      static double simTime = 0.0;
      double timeIncrement = 0.1; // or whatever delta you want
      simTime += timeIncrement;

      if ((projectile.getPosition().getPixelsX() == ground.getTarget().getPixelsX()) && 
            (projectile.getPosition().getPixelsY() == ground.getTarget().getPixelsY()))
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

   if (pUI->isRight())
      howitzer.rotate(+0.05); // tweak value

   if (pUI->isLeft())
      howitzer.rotate(-0.05);

   if (pUI->isQ())
      exit(0);
}