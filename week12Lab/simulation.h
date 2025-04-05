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
       this->projectileXKM = 0.0;
       this->projectileYKM = 0.0;
       this->targetXKM = 0.0;
       this->targetYKM = 0.0;
       this->simTime = 0.0;
       this->timeIncrement = 0.1;
   }

   void reset();

   void display();
   void displayStatus();

   void gamePlay();

   void input(const Interface* pUI);
   

private:
    Howitzer howitzer;
    Ground ground;
    Projectile projectile;
    Position posUpperRight;
    double projectileXKM;
    double projectileYKM;
    double targetXKM;
    double targetYKM;
    double simTime;
    double timeIncrement;
};