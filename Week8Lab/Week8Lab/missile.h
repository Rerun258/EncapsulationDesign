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
public:
   #define MASS 46.70               // kg
   #define INITIAL_VELOCITY 827.00  // m/s
   #define DIAMETER 0.15489         // m
   #define RADIUS 0.077445          // m
   #define AREA 0.018842            // m^2
   #define TIME_UNIT 1           // seconds

   Missile() : altitude(0.0), diameter(0.0), mass(0.0) {}
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
      double mass;
		double diameter;



   
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