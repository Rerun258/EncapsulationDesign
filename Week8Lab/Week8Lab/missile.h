#pragma once
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "gravity.h"

#define MASS 46.70               // kg
#define INITIAL_VELOCITY 827.00  // m/s
#define DIAMETER 0.15489         // m
#define RADIUS 0.077445          // m
#define AREA 0.018842            // m^2
#define TIME_UNIT 1              // seconds

class Missile
{
   public:

      Missile() : altitude(0.0), mass(MASS), diameter(DIAMETER), distance(0) {}

      Missile(double altitude, Acceleration& acc, Velocity& v)
      {
         this->altitude = altitude;
         this->v = v;
         this->acc = acc;
         this->diameter = DIAMETER;
         this->mass = MASS;
         this->distance = 0;
      }


<<<<<<< HEAD

private:
   double altitude;
   Acceleration acc;
   Velocity v;
   Angle a;
   double mass;
   double diameter;
   double distance;
   double Altitude;
   


public:
	double getAltitude()
	{
		return altitude;
	}
	void setAltitude(double altitude)
	{
		this->altitude = altitude;
	}
	double getDistance() {
		return distance;
	}
	void setDistance(double distance) {
		this->distance = distance;
	}
   double getArea()
   {
      return AREA;
   }
=======
   private:
      double altitude;
      Acceleration acc;
      Velocity v;
      double mass;
      double diameter;
      double distance;
>>>>>>> 18783a49ab6034aac6208e523b14cdefb53eef64


   public:

<<<<<<< HEAD
   void displayPos()
   {
      
   }
=======
      // Getters
	   double getAltitude()
	   {
		   return altitude;
	   }
>>>>>>> 18783a49ab6034aac6208e523b14cdefb53eef64

	   double getDistance() 
      {
		   return distance;
	   }

      double getArea()
      {
         return AREA;
      }

      // Setters
	   void setAltitude(double altitude)
	   {
		   this->altitude = altitude;
	   }

	   void setDistance(double distance) 
      {
		   this->distance = distance;
	   }
	
};