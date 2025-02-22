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
#include "DragCoefficent.h" // Add this line to include the DragCoefficient header
#include "missile.h"
#include <iomanip>

using namespace std;

#define MASS 46.70               // kg
#define INITIAL_VELOCITY 827.00  // m/s
#define DIAMETER 0.15489         // m
#define RADIUS 0.077445          // m
#define AREA 0.018842            // m^2
#define TIME_UNIT 1              // seconds

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

	Missile m;
   Angle a; // inital angel
   a.setDegrees(75.0);
	Velocity v = Velocity(INITIAL_VELOCITY, a); // inital velocity
	Acceleration acc; 
	acc.set(a, v.getSpeed()); // inital acceleration

	std::cout << std::fixed << std::setprecision(6); // Set to 6 decimal places, adjust as needed
   
   cout << fixed << setprecision(2);  // Print with 3 decimal places

   for (int i = 0; i <= 20; i++)
   {
		double distance = m.getDistance() + v.getDX() * i + (1 / 2) * acc.getDDX() * i * i; 
		double altitude = m.getAltitude() + v.getDY() * i + (1 / 2) * acc.getDDY() * i * i;
		cout << "Distance: " << distance << " meters      ";
		cout << "Altitude: " << altitude << " meters" << endl;

   }

   return 0;
}
 