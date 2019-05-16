#include "rockFall.h"
extern "C"
{
#include "board_accelerometer.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "Driver_I2C.h"
#include "fsl_i2c_hal.h"
  int32_t Accelerometer_Initialize();
  int32_t Accelerometer_GetState(ACCELEROMETER_STATE *);
  int fastTurn = 500;
  int slowTurn = 200;
}
ACCELEROMETER_STATE state;

/**
 * Create a GameController with player at (0,0) and space for 10 
 * additional objects
 */
GameController::GameController(GameBoard &board_ref)
{
  player = new Player(4, 1);
  objectSize = 1;
  board = board_ref;
}

RockFall::RockFall()
{
  board = new GameBoard;
  game = new GameController(*board);
}

void RockFall::run()
{
  game->render();
}

void GameController::draw(GameBoard &board)
{
  player->draw(board);
  for (int i = 0; i < objectSize; i++)
  {
  }
}

void GameController::render()
{
  preUpdate();
  update(0);
  draw(board);
}

void GameController::preUpdate()
{
}

/**
 * Process the update loop for this GameController
 */
void GameController::update(float dt)
{
  Accelerometer_GetState(&state);
  if (state.x > fastTurn)
  { //Big right move
    player->dx = 0.1;
  }
  else if (state.x > slowTurn)
  { //Small right move
    player->dx = 0.01;
  }
  else if (state.x < (-1 * fastTurn))
  { //Big left move
    player->dx = -0.1;
  }
  else if (state.x < (-1 * slowTurn))
  { //Small left move
    player->dx = -0.01;
  }
  else
  {
    player->dx = 0;
  }
  player->update(dt);
  for (int i = 0; i < objectSize; i++)
  {
  }
}