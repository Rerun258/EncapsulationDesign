/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
using namespace std;


/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   // set up the simulator
   Simulator(const Position & posUpperRight) : ground(posUpperRight) {}
       
   // display stuff on the screen
   void display();
  
   unsigned char phase;
   Angle a;
   Ground ground;
   Position posLander;
   Position posStar;
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display()
{
   ogstream gout;

   // draw the ground
   ground.draw(gout);

   // draw the lander
   posLander.setX(200.0);
   posLander.setY(300.0);
   gout.drawLander(posLander, a.getRadians());

   // draw a star
   posStar.setX(150.0);
   posStar.setY(375.0);
   
   gout.drawStar(posStar, phase);
}


/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator * pSimulator = (Simulator *)p;

   // draw the game
   pSimulator->display();

   // twinkle twinkle little star
   pSimulator->phase = (pSimulator->phase + 3) % 256;

   // handle input
   if (pUI->isRight())
      pSimulator->a.add(-0.1);   // rotate right here
   if (pUI->isLeft())
      pSimulator->a.add(0.1);    // rotate left here


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
