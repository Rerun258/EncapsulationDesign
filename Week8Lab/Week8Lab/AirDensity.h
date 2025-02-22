#include <iostream>
#include <map>
#include <stdexcept>
#pragma once
class AirDensity
{
private:
   std::map<int, double> altitudeDensityTable{
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

   double calLinearInterpolationHeight(double d0, double r0, double d1, double r1, double d)
   {
      return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0)));
   }

public:
   double getAirDensity(int altitude)
   {
      auto lower = altitudeDensityTable.lower_bound(altitude);
      if (lower != altitudeDensityTable.end() && lower->first == altitude)
      {
         return lower->second;
      }
      else if (lower == altitudeDensityTable.begin())
      {
         throw std::out_of_range("Altitude is below the minimum range of the table.");
      }
      else if (lower == altitudeDensityTable.end())
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
         return calLinearInterpolationHeight(d0, r0, d1, r1, altitude);
		}
	}
};
