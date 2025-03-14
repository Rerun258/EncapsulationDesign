/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    Elijah, McClain
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   for (int i = 0; i < numMapping - 1; ++i) {
      if (domain >= mapping[i].domain && domain <= mapping[i + 1].domain) {
         double d0 = mapping[i].domain;
         double r0 = mapping[i].range;
         double d1 = mapping[i + 1].domain;
         double r1 = mapping[i + 1].range;

         double r = r0 + (r1 - r0) * (domain - d0) / (d1 - d0);
         return r;
      }
   }
   // If domain is outside the range of provided mappings
   return -99.9;
}


/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   return -99.9;
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   return -99.9;
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   return -99.9;
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   return -99.9;
}

