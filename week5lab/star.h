/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

/*****************************************************
 * STAR
 * A star that twinkles
 *****************************************************/
class Star
{
public:
   Star() : phase(0) {}

   // Set the location and phase of the star randomly.
   void reset(double width, double height)
   {
      pos.setX(random(0.0, height));
      pos.setY(random(0.0, height));
      phase = random(0, 255);
   }

   void draw(ogstream & gout)
   {
      gout.drawStar(pos, phase++);
   }


private:
   Position pos;
   unsigned char phase;

   };
