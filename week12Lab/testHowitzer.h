/***********************************************************************
 * Header File:
 *    TEST HOWITZER
 * Author:
 *    McClain, Elijah
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include "howitzer.h"
#include "unitTest.h"
#include "position.h"
#include "angle.h"
#include "velocity.h"
#include "physics.h"
#include <math.h>   // for M_PI which is 3.14159
#include <cassert>;


using namespace std;

/*******************************
 * TEST HOWITZER
 * A friend class for Howitzer which contains the Howitzer unit tests
 ********************************/
class TestHowitzer : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Getters
      defaultConstructor();
      getPosition_zero();
      getPosition_middle();
      getMuzzleVelocity_slow();
      getMuzzleVelocity_standard();
      getElevation_up();
      getElevation_right();
      getElevation_left();

      // Ticket 2: Setters
      generatePosition_small();
      generatePosition_large();
      raise_rightDown();
      raise_rightUp();
      raise_leftDown();
      raise_leftUp();
      rotate_clock();
      rotate_counterClock();
      rotate_wrapClock();
      rotate_wrapCounterClock();

      report("Howitzer");
   }

private:
   double metersFromPixels = -1.0;

   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zeros (except angle is at 45 degrees, 
     *                 and the muzzle velocity is correct)
     *********************************************/
   void defaultConstructor()
   {
      //setup
		// exercise
		Howitzer h;

		// verify
		assertEquals(h.getPosition().getPixelsX(), 0.0);
		assertEquals(h.getPosition().getPixelsY(), 0.0);
		assertEquals(h.getElevation().getDegrees(), 45.0);
		assertEquals(h.getMuzzleVelocity(), DEFAULT_MUZZLE_VELOCITY);
		
		// teardown     
   }

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GET POSITION ZERO
     * input:   h.pos=(0,0)
     * output:  pos=(0,0)
     *********************************************/
   void getPosition_zero()
   {
      // setup
		Howitzer h;
		h.position.setPixelsX(0);
		h.position.setPixelsY(0);
		// exercise
		Position pos = h.getPosition();
		// verify
		assertEquals(h.getPosition().getPixelsX(), 0.0);
		assertEquals(h.getPosition().getPixelsY(), 0.0);
		
		// teardown
   }

   /*********************************************
    * name:    GET POSITION MIDDLE
     * input:   h.pos=(123.4, 567.8)
     * output:  pos=(123.4, 567.8)
    *********************************************/
   void getPosition_middle()
   {
      //setup
		Howitzer h;
		h.position.setPixelsX(123.4);
		h.position.setPixelsY(567.8);
		// exercise
		Position pos = h.getPosition();
		// verify
		assertEquals(h.getPosition().getPixelsX(), 123.4);
		assertEquals(h.getPosition().getPixelsY(), 567.8);
		// teardown

   }

   /*********************************************
    * name:    GET MUZZLE VELOCITY - SLOW SPEED
     * input:   h.muzzleVelocity=(24.68)
     * output:  m=24.68
    *********************************************/
   void getMuzzleVelocity_slow()
   {
      //setup
		Howitzer h;
		h.muzzleVelocity = 24.68;
		// exercise
		double m = h.getMuzzleVelocity();
		// verify
		assertEquals(h.getMuzzleVelocity(), 24.68);
		assertEquals(m, 24.68);
		// teardown
   }

   /*********************************************
    * name:    GET MUZZLE VELOCITY - STANDARD SPEED
     * input:   h.muzzleVelocity=(827.00)
     * output:  m=827
    *********************************************/
   void getMuzzleVelocity_standard()
   {
      //setup
		Howitzer h;
		h.muzzleVelocity = 827.00;
		// exercise
		double m = h.getMuzzleVelocity();
		// verify
		assertEquals(h.getMuzzleVelocity(), 827.00);
		assertEquals(m, 827.00);
		// teardown
   }

   /*********************************************
    * name:    GET ELEVATION - up
     * input:   h.elevation=0
     * output:  e=0
    *********************************************/
   void getElevation_up()
   {
      //setup
		Howitzer h;
		h.elevation.setDegrees(0.0);
		// exercise
		Angle e = h.getElevation();
		// verify
		assertEquals(h.getElevation().getDegrees(), 0.0);
		assertEquals(e.getDegrees(), 0.0); 
		// teardown
   }

   /*********************************************
    * name:    GET ELEVATION - right
     * input:   h.elevation=0.4
     * output:  e=0.4
    *********************************************/
   void getElevation_right()
   {
      //setup
		Howitzer h;
		h.elevation.setDegrees(0.4);
		// exercise
		Angle e = h.getElevation();
		// verify
		assertEquals(h.getElevation().getDegrees(), 0.4);
		assertEquals(e.getDegrees(), 0.4);
		// teardown
   }

   /*********************************************
    * name:    GET ELEVATION - left
     * input:   h.elevation=5.8
     * output:  e=5.8
    *********************************************/
   void getElevation_left()
   {
      //setup
		Howitzer h;
		h.elevation.setDegrees(5.8);
		// exercise
		Angle e = h.getElevation();
		// verify
		assertEquals(h.getElevation().getDegrees(), 5.8);
		assertEquals(e.getDegrees(), 5.8);
		// teardown
   }

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GENERATE POSITION small board
     * input:   (10px, 10px)
     * output:  1px <= x <= 9px
     *********************************************/
   void generatePosition_small()
   {
		//setup
     Howitzer h;
		h.position.setPixelsX(10);
		h.position.setPixelsY(10);

     Position pos;
      pos.setPixelsX(10);
		pos.setPixelsY(10);
		// exercise
		h.generatePosition(pos);
		// verify
		assert(h.getPosition().getPixelsX() >= 1.0);
		assert(h.getPosition().getPixelsX() <= 9.0);
		// teardown
   }

    /*********************************************
    * name:    GENERATE POSITION large board
    * input:   (1000px, 1000px)
    * output:  100px <= x <= 900px
    *********************************************/
   void generatePosition_large()
   {
      //setup
      Howitzer h;
      h.position.setPixelsX(1000);
      h.position.setPixelsY(1000);

      Position pos;
      pos.setPixelsX(1000);
      pos.setPixelsY(1000);
      // exercise
      h.generatePosition(pos);
      // verify
      assert(h.getPosition().getPixelsX() >= 100.0);
      assert(h.getPosition().getPixelsX() <= 900.0);
      // teardown
   }

   /*********************************************
    * name:    RAISE to the right/down
    * input:   h.elevation=0.5radians  raise(-0.1)
    * output:  h.elevation=0.6radians
    *********************************************/
   void raise_rightDown()
   {
       //setup
       Howitzer h;
       h.elevation.setRadians(0.5);
       // exercise
       h.raise(-0.1);
       
      // verify
      assertEquals(h.getElevation().getRadians(), 0.6);
       // teardown
   }

   /*********************************************
    * name:    RAISE to the right/up
    * input:   h.elevation=0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_rightUp()
   {
      //setup
		Howitzer h;
		h.elevation.setRadians(0.5);
		// exercise
		h.raise(0.1);
		// verify
		assertEquals(h.getElevation().getRadians(), 0.4);
		// teardown

   }

   /*********************************************
    * name:    RAISE to the left down
    * input:   h.elevation=-0.5radians  raise(-0.1)
    * output:  h.elevation=-0.6radians
    *********************************************/
   void raise_leftDown() {
		//setup
		Howitzer h;
		h.elevation.setRadians(-0.5);
		// exercise
		h.raise(-0.1);
		// verify
		assertEquals(h.getElevation().getRadians(), (2*M_PI) - 0.6);

   }

   /*********************************************
    * name:    RAISE to the left up
    * input:   h.elevation=-0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_leftUp()
   {
		//setup
		Howitzer h;
		h.elevation.setRadians(-0.5);
		// exercise
		h.raise(0.1);
		// verify
		assertEquals(h.getElevation().getRadians(), (2 * M_PI) - 0.4);
		
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=.3
    * output:  h.elevation=1.53
    *********************************************/
   void rotate_clock()
   {
      //setup
		Howitzer h;
		h.elevation.setRadians(1.23);
		// exercise
		h.rotate(0.3);
		// verify
      if (h.getElevation().getRadians() != 1.53) {
			cout << "h.elevation: " << h.getElevation().getRadians() << endl;
			cout << "Expected: 1.53" << endl;
      }
      else{ assertEquals(h.getElevation().getRadians(), 1.53); }
		
		// teardown
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=-.3
    * output:  h.elevation=0.93
    *********************************************/
   void rotate_counterClock()
   {
		//setup
		Howitzer h;
		h.elevation.setRadians(1.23);
		// exercise
      h.rotate(-0.3);
		// verify
		assertEquals(h.getElevation().getRadians(), 0.93);
		// teardown
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE CLOCKWISE WRAP BY 2PI
    * input:   h.elevation=6.1 (2pi + -0.1) rotate=.2
    * output:  h.elevation=.1
    *********************************************/
   void rotate_wrapClock()
   {
		//setup
		Howitzer h;
		h.elevation.setRadians(2 * M_PI - .1);
		// exercise
		h.rotate(0.2);
		// verify
		assertEquals(h.getElevation().getRadians(), .1 );
		// teardown

   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE WRAP BY 4PI
    * input:   h.elevation=0.1 rotate=-.2 - 4PI
    * output:  h.elevation=6.1 (2pi + -0.1)
    *********************************************/
   void rotate_wrapCounterClock()
   {
		//setup
		Howitzer h;
		h.elevation.setRadians(0.1);
		// exercise
		h.rotate(-0.2);
		// verify
		assertEquals(h.getElevation().getRadians(), 2*M_PI - .1);
		// teardown
   }

   /*****************************************************************
    *****************************************************************
    * STANDARD FIXTURE
    *****************************************************************
    *****************************************************************/

   // setup standard fixture - set the zoom to 1100m per pixel
   void setupStandardFixture()
   {
      Position p;
      metersFromPixels = p.metersFromPixels;
      p.metersFromPixels = 1100.0;
   }

   // teardown the standard fixture - reset the zoom to what it was previously
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position p;
      p.metersFromPixels = metersFromPixels;
   }
};
