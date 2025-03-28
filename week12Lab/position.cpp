#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>

// Initialize the static member
//double Position::metersFromPixels = 1.0; // Default value

// Constructor implementation
Position::Position(double x, double y) : x(x), y(y) {}

// Assignment operator implementation
Position& Position::operator=(const Position& posRHS)
{
   if (this != &posRHS)
   {
      x = posRHS.x;
      y = posRHS.y;
   }
   return *this;
}

/************************************************************************
 * UPDATE POSITION
 * Update the current position based on the impulse of velocity
 * taking into account time dilation:
 *
 *   s = s_0 + vt + 1/2 at^2
 *
 *   INPUT  POSITION     The location of the item
 *          VELOCITY     The velocity of the item
 *          ACCELERATION The acceleration of the item
 *          TIME         How much time are we talking about?
 *   OUTPUT POSITION     The location, updated
 *
 *
 *  x = x + dx t + 1/2 ddx t^2
 *  y = y + dy t + 1/2 ddy t^2
 *************************************************************************/
void Position::add(const Acceleration& a, const Velocity& v, double t)
{
   x += v.getDX() * t + 0.5 * a.getDDX() * t * t;
   y += v.getDY() * t + 0.5 * a.getDDY() * t * t;
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator<<(std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m, " << pt.getMetersY() << "m)";
   return out;
}

/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator>>(std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}

// Setter methods implementation
void Position::setMeters(double xMeters, double yMeters)
{
   x = xMeters;
   y = yMeters;
}

void Position::setMetersX(double xMeters)
{
   x = xMeters;
}

void Position::setMetersY(double yMeters)
{
   y = yMeters;
}

void Position::setPixelsX(double xPixels)
{
   x = xPixels * metersFromPixels;
}

void Position::setPixelsY(double yPixels)
{
   y = yPixels * metersFromPixels;
}

// Add methods implementation
double Position::addMetersX(double x)
{
   this->x += x;
   return this->x;
}

double Position::addMetersY(double y)
{
   this->y += y;
   return this->y;
}

double Position::addPixelsX(double x)
{
   this->x += x * metersFromPixels;
   return this->x;
}

double Position::addPixelsY(double y)
{
   this->y += y * metersFromPixels;
   return this->y;
}
