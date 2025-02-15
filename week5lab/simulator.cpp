/**********************************************************************
 * McClain and Elijah 
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "acceleration.h"// for ACCELERATION
#include "lander.h"      // for LANDER
#include "star.h"        // for STAR
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include <vector>        // for VECTORS

using namespace std;

const double MOON_GRAVITY = 1.625;


/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) 
   : ground(posUpperRight), lander(posUpperRight), running(true)
   {
      for (int i = 0; i < 50; ++i)
      {
         Star star;
         star.reset(400, 400);
         stars.push_back(star);
      }
   }

   Ground ground;
   vector<Star> stars;
   Angle angle;
   Thrust thrust;
   Lander lander;
   bool running;
   
};



/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulator* pSimulator = (Simulator*)p;
   ogstream gout;

   // Draw the stars
   for (Star& star : pSimulator->stars)
   {
      star.draw(gout);
   }

   // Once Lander has landed or crashed, only update the current status and exit.
   if (!pSimulator->running)
   {
      pSimulator->lander.draw(pSimulator->thrust, gout);
      pSimulator->ground.draw(gout);

      // Draw final stats.
      Position goutPos;
      goutPos.setX(20.0);
      goutPos.setY(370.0);
      gout.setPosition(goutPos);
      gout << "FUEL: " << pSimulator->lander.getFuel() << " LBS" << endl;
      gout << "ALTITUDE: " << pSimulator->lander.getPosition().getY() << " METERS" << endl;
      gout << "SPEED: " << pSimulator->lander.getSpeed() << " M/S" << endl;

      //Draw ending message.
      goutPos.setX(100.0);
      goutPos.setY(200.0);
      gout.setPosition(goutPos);

      if (pSimulator->lander.isDead())
      {
         gout << "HOUSTON, WE HAVE A FRIGGIN PROBLEM.";
      }

      if (pSimulator->lander.isLanded())
      {
         gout << "THE EAGLE HAS LANDED. RAHHH.";
      }

      if (pSimulator->lander.isFlying())
      {
         gout << "UH, HOUSTON? TIME HAS STOPPED.";
      }

      // User presses SPACE, play new game.
      if (pUI->isSpace())
      { 
         pSimulator->lander.reset(Position(400,400));
         pSimulator->ground.reset();
         pSimulator->running = true;
      }

      // User presses Q, exit game.
      if (pUI->isQ())
      {
         exit(0);
      }

      return;
      
   }

   // User presses Q mid-flight, set game to freeze.
   if (pUI->isQ())
      pSimulator->running = false;


   // Draw the ground
   pSimulator->ground.draw(gout);

   // Handle user input
   pSimulator->thrust.set(pUI);

   // Lander crashes
   if (pSimulator->ground.hitGround(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
   {
      pSimulator->lander.crash();
      pSimulator->running = false;
   }

   // Lander lands
   if (pSimulator->ground.onPlatform(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
   {
      // If lands above max speed, they're dead.
      if (pSimulator->lander.getSpeed() > pSimulator->lander.getMaxSpeed())
      {
         pSimulator->lander.crash();
         pSimulator->running = false;
      }

      else
      {
         pSimulator->lander.land();
         pSimulator->running = false;
      }
   }

   // If the lander is still playing, update as usual.
   if (pSimulator->running)
   {
      // Compute acceleration and update lander
      Acceleration acceleration = pSimulator->lander.input(pSimulator->thrust, -MOON_GRAVITY); // Gravity
      pSimulator->lander.coast(acceleration, 0.1); // Update with a time step of 0.1s
   }
   
   // Continually update stats in top left corner.
   Position goutPos;
   goutPos.setX(20.0);
   goutPos.setY(370.0);
   gout.setPosition(goutPos);
   gout << "FUEL: " << pSimulator->lander.getFuel() << " LBS" << endl;
   gout << "ALTITUDE: " << pSimulator->lander.getPosition().getY() << " METERS" << endl;
   gout << "SPEED: " << pSimulator->lander.getSpeed() << " M/S" << endl;


   // Draw the lander
   pSimulator->lander.draw(pSimulator->thrust, gout);


}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run the unit tests
   testRunner();

   
   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   // set everything into action
   ui.run(callBack, (void *)&simulator);

   return 0;
}
