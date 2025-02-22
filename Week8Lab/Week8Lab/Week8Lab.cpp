#include "acceleration.h" // Add this line to include the Acceleration header

// Week8Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
// McClain, Elijah

#include <iostream>
#include <cmath>
#include <cassert>
#include "angle.h"
#include "velocity.h"
#include "AirDensity.h"
#include "MachSpeed.h"

using namespace std;

#define MASS 46.70               // kg
#define INITIAL_VELOCITY 827.00  // m/s
#define DIAMETER 0.15489         // m
#define RADIUS 0.077445          // m
#define AREA 0.018842            // m^2
#define TIME_UNIT 1           // seconds

//********McClain's Code********





//******************************
//********* Elijahs Code********



//******************************





double calLienearInterpolationDistance(double r1, double r0, double d1, double d0, double r)
{
    return ((r1 - r0) / ((d1 - d0) * (r - r0))) + d0;
}

double calLienearInterpolationHeight(double d0, double r0, double d1, double r1, double d) {
   return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0)));
}

void testcalLienearInterpolationHeight() {
   double tolerance = 1e-4; // Tolerance value for approximation
   double expected = 1.2024;
   double result = calLienearInterpolationHeight(0, 1.225, 1000, 1.112, 200);

   assert(std::abs(result - expected) < tolerance);
   std::cout << "Test passed! Result is approximately " << expected << std::endl;
}

int main() 
{
   testcalLienearInterpolationHeight();
   std::cout << "calLienearInterpolationHeight(0, 1.225, 1000, 1.112, 200): " << calLienearInterpolationHeight(0, 1.225, 1000, 1.112, 200) << std::endl;

   double userAngle;

   cout << "What is the angle? ";
   //cin >> userAngle;


   //********McClain's Code********

   // initalV = 8.2m/s

   //find find inital velocity
   //Dx i need the angle

   Angle a; // inital angel
   a.setDegrees(75.0);
	Velocity v = Velocity(INITIAL_VELOCITY, a); // inital velocity
	Acceleration acc; 
	acc.set(a, v.getSpeed()); // inital acceleration

	cout << "new position: " << v.getDX() + (1/2) * acc.getDDX() << endl;

   

   for (int i = 0; i <= 20; i++)
   {
      cout << "new x position: " << v.getDX() * (i) + (1 / 2) * acc.getDDX() << endl;
		cout << "new y position: " << v.getDY() * (i) + (1 / 2) * acc.getDDY() << endl; 
		v.add(acc, TIME_UNIT);
   }

   cout << "Distance: " << acc.getDDX() << "m  Altitude: " << acc.getDDY() << "m" << endl;

	AirDensity airDensity;

	cout << endl << endl << "air density: " << airDensity.getAirDensity(500) << endl;

	cout << "\n\nSpeed of sound:" << MachSpeed().getMachSpeed(0) << endl;
	cout << "Mach speed: " << 827 / MachSpeed().getMachSpeed(0)  << endl;


   return 0;
}
