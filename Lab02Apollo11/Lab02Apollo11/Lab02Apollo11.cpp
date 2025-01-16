/*************************************************************
 * 1. Name:
 *      McCain, Elijah
 *
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 *
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 *
 * 4. What was the hardest part? Be as specific as possible.
 *      Adding the new altitude component to change in the middle of a flight.
 *
 * 5. How long did it take for you to complete the assignment?
 *      ~ 1 hour
 *
 *****************************************************************/

#include <iostream>  // for CIN and COUT
#include <cmath> // for triginomotry
#include <string> // for string to double
using namespace std;
#define M_PI 3.14159265358979323846

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double start, double velocity, double acceleration, double time)
{
   double newStart = start + velocity * time + (.5) * acceleration * (time * time);
   return newStart;
}

/**************************************************
* COMPUTE ACCELERATION
* Find the acceleration given a thrust and mass.
* This will be done using Newton's second law of motion:
*     f = m * a
* INPUT
*     f : force, in Newtons (kg * m / s^2)
*     m : mass, in kilograms
* OUTPUT
*     a : acceleration, in meters/second^2
***************************************************/
double computeAcceleration(double force, double mass)
{
   return force / mass;
}

/***********************************************
* COMPUTE VELOCITY
* Starting with a given velocity, find the new
* velocity once acceleration is applied. This is
* called the Kinematics equation. The
* equation is:
*     v = v + a t
* INPUT
*     v : velocity, in meters/second
*     a : acceleration, in meters/second^2
*     t : time, in seconds
* OUTPUT
*     v : new velocity, in meters/second
***********************************************/
double computeVelocity(double velocity, double acceleration, double time)
{
   return velocity + (acceleration * time);
}


/***********************************************
* COMPUTE VERTICAL COMPONENT
* Find the vertical component of a velocity or acceleration.
* The equation is:
*     cos(a) = y / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     y : the vertical component of the total
***********************************************/
double computeVerticalComponent(double angle, double total)
{
   double vertical = cos(angle) * total;
   return vertical;
}


/***********************************************
* COMPUTE HORIZONTAL COMPONENT
* Find the horizontal component of a velocity or acceleration.
* The equation is:
*     sin(a) = x / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     x : the vertical component of the total
***********************************************/
double computeHorizontalComponent(double angle, double total)
{
   return sin(angle) * total;
}

/************************************************
* COMPUTE TOTAL COMPONENT
* Given the horizontal and vertical components of
* something (velocity or acceleration), determine
* the total component. To do this, use the Pythagorean Theorem:
*    x^2 + y^2 = t^2
* where:
*      x
*    +-----
*    |   /
*  y |  / total
*    | /
*    |/
* INPUT
*    x : horizontal component
*    y : vertical component
* OUTPUT
*    total : total component
***********************************************/
double computeTotalComponent(double x, double y)
{
   double powered = (x * x) + (y * y);
   return sqrt(powered);
}


/*************************************************
* RADIANS FROM DEGEES
* Convert degrees to radians:
*     radians / 2pi = degrees / 360
* INPUT
*     d : degrees from 0 to 360
* OUTPUT
*     r : radians from 0 to 2pi
**************************************************/
double radiansFromDegrees(double degrees)
{
   double radians = (degrees * M_PI) / 180.0;
   return radians;
}

/**************************************************
* PROMPT
* A generic function to prompt the user for a double
* INPUT
*      message : the message to display to the user
* OUTPUT
*      response : the user's response
***************************************************/
double prompt(string message)
{
   string response;
   cout << message;
   cin >> response;
   double responseNum = stod(response); // convert users respons into double
   return responseNum; //double.pharse(responseNum);
}

/**************************************************
* LUNAR POSITION
* Updates lunar position.
* INPUT
*      x : position
*      y : altitude
*      dx : vertical velocity
*      dy : horizontal velocity
*      aDegrees : angle in degrees
*      t : time
*      round: fix for visualization of time
* OUTPUT
*      Lunar position for each second.
* 
* Code Side Effects: Changes variables passed into the function.
***************************************************/
void lunarPosition(double &x, double &y, double &dx, double &dy, double &aDegrees, double &t, int round)
{
	double aRadians;
	double accelerationThrust;
	double ddxThrust;
	double ddyThrust;
	double ddx;
	double ddy;
	double v;

   int printTime = 0;

	// Go through the simulator five times.
	for (double i = 0.0; i < t; i++)
	{
		// Angle in radians.
		aRadians = radiansFromDegrees(aDegrees);

		// Acceleration due to thrust.
		accelerationThrust = computeAcceleration(THRUST, WEIGHT);

		// Horizontal acceleration due to thrust.
		ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);

		// Vertical acceleration due to thrust.
		ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);

		// Total horizontal acceleration.
		ddx = ddxThrust;

		// Total vertical acceleration.
		ddy = ddyThrust + GRAVITY;

      // Total velocity.
		v = computeTotalComponent(dx, dy);


		// Update the position before updating the velocity.
		x = computeDistance(x, dx, ddx, 1);
		y = computeDistance(y, dy, ddy, 1);

		// Update the velocity.
		dx = computeVelocity(dx, ddx, 1);
		dy = computeVelocity(dy, ddy, 1);

		// Update total velocity.
		v = computeTotalComponent(dx, dy);

		// Output.
		cout.setf(ios::fixed | ios::showpoint);
		cout.precision(2);

      printTime++;

		cout << (printTime + round) << "s - x,y:(" << x << ", " << y << ")m  dx,dy:(" << dx << ", " << dy << ")m/s  speed:" << v << "m/s  angle:" << aDegrees << "deg" << endl;

	}
}


/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
   // Prompt for input and variables to be computed.
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double y = prompt("What is your altitude (m)? ");
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");

   // Position.
   double x = 0.0; 

   // Time block.
   double t = 5.0;


   // Passed by refferance changes outside of the function are made.
   lunarPosition(x, y, dx, dy, aDegrees, t, 0); 

   aDegrees = prompt("\nWhat is the New angle of the LM where 0 is up (degrees)? ");
 
	lunarPosition(x, y, dx, dy, aDegrees, t, 5); // Passed by refferance changes outside of the function are made.

   return 0;
}