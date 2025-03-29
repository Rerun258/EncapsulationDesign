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
   // Define the mapping array
   const Mapping mapping[] =
   {
       {0, 9.807},
       {1000, 9.804},
       {2000, 9.801},
       {3000, 9.797},
       {4000, 9.794},
       {5000, 9.791},
       {6000, 9.788},
       {7000, 9.785},
       {8000, 9.782},
       {9000, 9.779},
       {10000, 9.776},
       {15000, 9.761},
       {20000, 9.745},
       {25000, 9.730},
       {30000, 9.715},
       {40000, 9.684},
       {50000, 9.654},
       {60000, 9.624},
       {70000, 9.594},
       {80000, 9.564}
   };
   const int numMapping = sizeof(mapping) / sizeof(mapping[0]);

   // Use linear interpolation to find the gravity
   return linearInterpolation(mapping, numMapping, altitude);
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

