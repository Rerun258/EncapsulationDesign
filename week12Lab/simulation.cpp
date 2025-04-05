/**********************************************************************
 * Suurce File:
 *    SIMULATION
 * Author:
 *    <your name here>
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
}

void Simulator::displayStatus()
{

}

void Simulator::gamePlay()
{

}