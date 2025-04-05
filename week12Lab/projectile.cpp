/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    Elijah, McClain
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/


 #include "projectile.h"
 #include "angle.h"
 #include "acceleration.h"
 using namespace std;

 
 // Advance the round forward until the next unit of time.
 void Projectile::advance(double simulationTime)
 {
   if (!flying())
      return;

   PositionVelocityTime pvt            = flightPath.back();
   double speed                        = pvt.v.getSpeed();
   double altitude                     = pvt.pos.getMetersY();
   double interval                     = simulationTime - currentTime();
   assert(interval > 0.0);

   double density                      = densityFromAltitude(altitude);
   double speedSound                   = speedSoundFromAltitude(altitude);
   double mach                         = speed / speedSound;
   double dragCoefficient              = dragFromMach(mach);
   double windResistence               = forceFromDrag(density, dragCoefficient, radius, speed);
   double magnitudeWind                = accelerationFromForce(windResistence, mass);
   Acceleration aWind(-pvt.v.getAngle(), magnitudeWind);

   double magnitudeGravity             = gravityFromAltitude(altitude);
   Angle angleGravity;
   angleGravity.setDown();
   Acceleration aGravity(angleGravity, magnitudeGravity);

   Acceleration aTotal = aGravity + aWind;

   pvt.pos.add(aTotal, pvt.v, interval);
   pvt.v.add(aTotal, interval);
   pvt.t = simulationTime;

   flightPath.push_back(pvt);

 }

