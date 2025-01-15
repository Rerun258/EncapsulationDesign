/*************************************************************
 * 1. Name:
 *      McCain, Elijah
 *
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 *
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 *
 * 4. What was the hardest part? Be as specific as possible.
 *      Figuring out what main() was doing, and how we were supposed
 *       to complete it, fitting together all the functions together 
 *       like a puzzle.
 *
 * 5. How long did it take for you to complete the assignment?
 *      ~3 hours, with the assistance of ChatGPT.
 *
 **************************************************************/

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
   double newStart = start + velocity * time + (1.0 / 2.0) * acceleration * (time * time);
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
   double powered = pow(x, 2.0) + pow(y, 2.0);
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

/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{

   // Prompt for input and variables to be computed
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double y = prompt("What is your altitude (m)? ");
   double x = prompt("What is your position (m)? ");
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
   double t = prompt("What is the time interval (s)? ");


   //cout << "\n\n-------test code -------- \n\n";
   //double aRadiansTest = radiansFromDegrees(aDegrees); // Should be -0.785398 (since -45 degrees is PI/4)
   //cout << aRadiansTest << " should be -0.785398\n";

   //double accelerationThrustTest = computeAcceleration(THRUST, WEIGHT); // Should be approximately 2.979 (from THRUST/WEIGHT)
   //cout << accelerationThrustTest << " should be 2.979\n";

   //double ddxThrustTest = computeHorizontalComponent(aRadiansTest, accelerationThrustTest); // Should be approximately -2.106
   //cout << ddxThrustTest << " should be -2.106\n";
   //double ddyThrustTest = computeVerticalComponent(aRadiansTest, accelerationThrustTest);   // Should be approximately 2.106
   //cout << ddyThrustTest << " should be 2.106\n";


   //double ddxTest = 0;//computeHorizontalComponent(aRadiansTest, dx);       // Approximately 2.106
   //cout << ddxTest << "should be 2.106\n";
   //double ddyTest = ddyThrustTest + GRAVITY;  // Approximately -3.731 (since GRAVITY is -1.625)
   //cout << ddyTest << "should be -1.625\n";


   //cout << "\n\n-------test code -------- \n\n";

  
   double aRadians;
   double accelerationThrust;
	double ddxThrust;
	double ddyThrust;
	double ddx;
	double ddy;
   double v;

   // Go through the simulator five times
   for (int i = 0; i < 5; i++)
   {
		aRadians = radiansFromDegrees(aDegrees);                                // Angle in radians
		accelerationThrust = computeAcceleration(THRUST, WEIGHT);               // Acceleration due to thrust 
		ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);   // Horizontal acceleration due to thrust
		ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);     // Vertical acceleration due to thrust
      ddx = ddxThrust;                                                        // Total horizontal acceleration
		ddy = ddyThrust + GRAVITY;                                              // Total vertical acceleration
		v = computeTotalComponent(dx, dy);                                      // Total velocity


      // Update the position before updating the velocity
      x = computeDistance(x, dx, ddx, t);
      y = computeDistance(y, dy, ddy, t);

      // Update the velocity
      dx = computeVelocity(dx, ddx, t);
      dy = computeVelocity(dy, ddy, t);
      v = computeTotalComponent(dx, dy); // Update total velocity

      // Output
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "\tNew position:   (" << x << ", " << y << ") m\n";
      cout << "\tNew velocity:   (" << dx << ", " << dy << ") m/s\n";
      cout << "\tTotal velocity:  " << v << " m/s\n\n";
   }


   return 0;
}