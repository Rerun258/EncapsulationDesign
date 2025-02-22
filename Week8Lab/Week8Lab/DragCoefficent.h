#pragma once
#include <iostream>
#include <map>
#include <stdexcept>

class DragCoefficient
{
private:
   std::map<double, double> machDragTable{
       {0.300, 0.1629},
       {0.500, 0.1659},
       {0.700, 0.2031},
       {0.890, 0.2597},
       {0.920, 0.3010},
       {0.960, 0.3287},
       {0.980, 0.4002},
       {1.000, 0.4258},
       {1.020, 0.4335},
       {1.060, 0.4483},
       {1.240, 0.4064},
       {1.530, 0.3663},
       {1.990, 0.2897},
       {2.870, 0.2297},
       {2.890, 0.2306},
       {5.000, 0.2656}
   };

   double calLinearInterpolationMach(double d0, double r0, double d1, double r1, double d)
   {
      return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0)));
   }

public:
   double getDragCoefficient(double mach)
   {
      auto lower = machDragTable.lower_bound(mach);
      if (lower != machDragTable.end() && lower->first == mach)
      {
         return lower->second;
      }
      else if (lower == machDragTable.begin())
      {
         throw std::out_of_range("Mach number is below the minimum range of the table.");
      }
      else if (lower == machDragTable.end())
      {
         throw std::out_of_range("Mach number is above the maximum range of the table.");
      }
      else
      {
         auto upper = lower;
         --lower;
         double d0 = lower->first;
         double r0 = lower->second;
         double d1 = upper->first;
         double r1 = upper->second;
         return calLinearInterpolationMach(d0, r0, d1, r1, mach);
      }
   }
};

class DragCoefficent
{
};
