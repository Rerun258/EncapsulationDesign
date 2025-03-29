/**********************************************************************
 * Header File:
 *    SIMULATION
 * Author:
 *    Elijah, McClain
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

#pragma once
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


 /*********************************************
  * Simulation
  * Execute one simulation of a projectile being fired.
  *********************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) : ground(posUpperRight), howitzer()
   {
       howitzer.generatePosition(posUpperRight);
       ground.reset(howitzer.getPosition());
       
   }

   void display()
   {
      ogstream gout;

      ground.draw(gout);
      howitzer.draw(gout, 50.0);
   }

private:
    Howitzer howitzer;
    Ground ground;

};