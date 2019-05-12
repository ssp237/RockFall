//Provides functions to solicit input from the attached FRDM board and convert
//the input to a useable form.
//Might implement as a class? Not 100% certain on that yet.
//If a class, will have a singleton instance used for all
//input.

// Only compile this file once, in case we define it more than once
// (just in case)
#pragma once

extern "C"
{
#include "board_accelerometer.h"
#include "fsl_debug_console.h"
#include "board.h"
}

class InputController
{
public:
  InputController();
  static InputController getInstance();
  bool didLeft();
  bool didRight();
  bool didUp();
  bool didDown();
  int getHorizontal();
  int getVertical();

private:
  ACCELEROMETER_STATE state;
  bool tilted_left;
  bool tiled_right;
  bool tilted_up;
  bool tilted_down;
  int h_tilt;
  int v_tilt;
  static InputController theController;
}