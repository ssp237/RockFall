#include "inputController.h"
extern "C"
{
#include "board_accelerometer.h"
#include "fsl_debug_console.h"
#include "board.h"
  int32_t Accelerometer_Initialize();
  int32_t Accelerometer_GetState(ACCELEROMETER_STATE *);
}

InputController::InputController()
{
  hardware_init();
  Accelerometer_Initialize();
  tiled_right = false;
  tilted_down = false;
  tilted_left = false;
  tilted_up = false;
  h_tilt = 0;
  v_tilt = 0;
  state = new ACCELEROMETER_STATE;
}

InputController::didDown()
{
  return false;
}
