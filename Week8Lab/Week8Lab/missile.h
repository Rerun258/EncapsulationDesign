#pragma once
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"

class Missile
{
   public:
      Missile() : altitude(0.0) {}
      Missile(double altitude, Acceleration& acc, Velocity& v) 
      {
         this->altitude = altitude;
         this->v = v;
         this->acc = acc;
      }

   private:
      double altitude;
      Acceleration acc;
      Velocity v;
   
   public:
      double getAltitude()
      {
         return altitude;
      }

      void updateAltitude()
      {
         altitude = v.getDX() + (1 / 2) * acc.getDDX();
      }
};