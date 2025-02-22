#include "acceleration.h" // Add this line to include the Acceleration header

// Week8Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
// McClain, Elijah

#include <iostream>
#include <cmath>
#include "angle.h"
#include "velocity.h"

using namespace std;

#include <cassert>





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

int main() {

   //********McClain's Code********

// initalV = 8.2m/s

//find find inital velocity
//Dx i need the angle
   Angle a = 10.0; // inital angel
	Velocity v = Velocity(8.2, a); // inital velocity
	Acceleration acc; 
	acc.set(a, 8.2); // inital acceleration



   
   return 0;
}
