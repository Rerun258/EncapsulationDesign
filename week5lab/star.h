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
   void reset(double width, double height)
   {
       width = random(0, 500);
       height = random(0, 500);
   }

   void draw(ogstream& gout) const;


private:
    Position pos;
    unsigned char phase;
};
