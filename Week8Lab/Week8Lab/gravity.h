#pragma once
#include <iostream>
#include <map>
#include <stdexcept>

class Gravity
{
private:
   std::map<int, double> altitudeGravityTable{
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

   double calLinearInterpolationGravity(double d0, double r0, double d1, double r1, double d)
   {
      return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0)));
   }

public:
   double getGravity(int altitude)
   {
      auto lower = altitudeGravityTable.lower_bound(altitude);
      if (lower != altitudeGravityTable.end() && lower->first == altitude)
      {
         return lower->second;
      }
      else if (lower == altitudeGravityTable.begin())
      {
         throw std::out_of_range("Altitude is below the minimum range of the table.");
      }
      else if (lower == altitudeGravityTable.end())
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
         return calLinearInterpolationGravity(d0, r0, d1, r1, altitude);
      }
   }
};
