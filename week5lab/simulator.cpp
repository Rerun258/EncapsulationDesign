/**********************************************************************
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

#define MOON_GRAVITY = 1.625

/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) 
   : ground(posUpperRight), lander(posUpperRight)
   {
      for (int i = 0; i < 50; ++i)
      {
         stars.push_back(Star());
      }
   }

   Ground ground;
   vector<Star> stars;
   Angle angle;
   Thrust thrust;
   Lander lander;
   
};



/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator * pSimulator = (Simulator *)p;

   ogstream gout;

   // twinkle twinkle little stars (thank you chatgpt, you did nothing for me)
   for (Star& star : pSimulator->stars)
   {
      star.draw(gout);
   }

   // draw the ground
   pSimulator->ground.draw(gout);
   if (pUI->isRight())
   {
      pSimulator->thrust.isClock();
      
      pSimulator->lander.input(pSimulator->thrust, -1.625);
   }

   if (pUI->isLeft())
   {
      pSimulator->thrust.isCounter();
      pSimulator->lander.input(pSimulator->thrust, -1.625);
   }

   if (pUI->isUp())
   {
      pSimulator->thrust.mainEngineThrust();
      
      pSimulator->lander.input(pSimulator->thrust, -1.625);
   }

   if (pUI->isDown())
   {
      
   }

   pSimulator->lander.draw(pSimulator->thrust, gout);

   //Acceleration acceleration = pSimulator->lander.input(pSimulator->thrust, -9.8); // Gravity
   //pSimulator->lander.coast(acceleration, 0.1); // Assume time step of 0.1s

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
