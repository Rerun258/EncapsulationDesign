#pragma once
#include <iostream>
#include <map>
#include <stdexcept>

class MachSpeed
{
private:
   std::map<int, double> altitudeSpeedTable{
       {0, 340},
       {1000, 336},
       {2000, 332},
       {3000, 328},
       {4000, 324},
       {5000, 320},
       {6000, 316},
       {7000, 312},
       {8000, 308},
       {9000, 303},
       {10000, 299},
       {15000, 295},
       {20000, 295},
       {25000, 295},
       {30000, 305},
       {40000, 324},
       {50000, 337},
       {60000, 319},
       {70000, 289},
       {80000, 269}
   };

   double calLinearInterpolationSpeed(double d0, double r0, double d1, double r1, double d)
   {
      return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0)));
   }

public:
   double getMachSpeed(int altitude)
   {
      auto lower = altitudeSpeedTable.lower_bound(altitude);
      if (lower != altitudeSpeedTable.end() && lower->first == altitude)
      {
         return lower->second;
      }
      else if (lower == altitudeSpeedTable.begin())
      {
         throw std::out_of_range("Altitude is below the minimum range of the table.");
      }
      else if (lower == altitudeSpeedTable.end())
      {
         throw std::out_of_range("Altitude is above the maximum range of the table.");
      }
      else
      {
         auto upper = lower;
         --lower;
         double d0 = lower->first;
         double r0 = lower->second;
         double d1 = upper->first;
         double r1 = upper->second;
         return calLinearInterpolationSpeed(d0, r0, d1, r1, altitude);
      }
   }
};
