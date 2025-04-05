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
   Simulator(const Position & posUpperRight) : ground(posUpperRight), howitzer(), projectile()
   {
       howitzer.generatePosition(posUpperRight);
       ground.reset(howitzer.getPosition());
       this->posUpperRight = posUpperRight;
       this->targetXKM = ground.getTarget().getMetersX() / 1000.0;
       this->targetYKM = ground.getTarget().getMetersY() / 1000.0;
       this->simTime = 0.0;
       this->timeIncrement = 0.1;
   }

   void display();

   void displayStatus();

   void gamePlay();

   void input(const Interface* pUI);

private: 
   void reset();
    Howitzer howitzer;
    Ground ground;
    Projectile projectile;
    Position posUpperRight;

    double targetXKM;
    double targetYKM;
    double simTime;
    double timeIncrement;
};