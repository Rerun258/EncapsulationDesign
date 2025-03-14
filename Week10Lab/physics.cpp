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
   // Define the mapping array
   const Mapping mapping[] =
   {
       {0, 1.2250000},
       {1000, 1.1120000},
       {2000, 1.0070000},
       {3000, 0.9093000},
       {4000, 0.8194000},
       {5000, 0.7364000},
       {6000, 0.6601000},
       {7000, 0.5900000},
       {8000, 0.5258000},
       {9000, 0.4671000},
       {10000, 0.4135000},
       {15000, 0.1948000},
       {20000, 0.0889100},
       {25000, 0.0400800},
       {30000, 0.0184100},
       {40000, 0.0039960},
       {50000, 0.0010270},
       {60000, 0.0003097},
       {70000, 0.0000828},
       {80000, 0.0000185}
   };

   const int numMapping = sizeof(mapping) / sizeof(mapping[0]);

   // Use linear interpolation to find the density
   return linearInterpolation(mapping, numMapping, altitude);
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

