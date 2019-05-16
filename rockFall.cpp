#include "rockFall.h"
#include "gameObject.h"
#include "stdlib.h"
#include "math.h"
extern "C"
{
#include "board_accelerometer.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "Driver_I2C.h"
#include "fsl_i2c_hal.h"
  int32_t Accelerometer_Initialize();
  int32_t Accelerometer_GetState(ACCELEROMETER_STATE *);
}
ACCELEROMETER_STATE state;
const int fastTurn = 400;
const int slowTurn = 150;
bool isDed = false;

/**
 * Create a GameController with player at (0,0) and space for 10 
 * additional objects
 */
GameController::GameController(GameBoard &board_ref)
{
  player = new Player(4, 1);
  board = board_ref;
	maxRockCount = 4500;
	maxCoinCount = 5000; 
  rocks = new Rock[15];
  rocks[0].x = 8;
	rocks[0].y = 17;
  numRocks = 1;
  coins = new Coin[15];
  numCoins = 0;
  rockCount = rand() % maxRockCount + maxRockCount;
  coinCount = rand() % maxCoinCount + maxCoinCount;
}

RockFall::RockFall()
{
  board = new GameBoard;
  game = new GameController(*board);
}

void RockFall::run()
{
	if (isDed){
		board->deathScreen();
	}
	else{
		game->render();
	}
}

void GameController::draw(GameBoard &board)
{
  player->draw(board);
  for (int i = 0; i < numRocks; i++)
  {
    rocks[i].draw(board);
  }
  for (int i = 0; i < numCoins; i++)
  {
    coins[i].draw(board);
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
  rockCount--;
  if (rockCount <= 0)
  {
    rockCount = rand() % maxRockCount + maxRockCount;
		rocks[numRocks].x = rand() % 7 + 1;
		rocks[numRocks].y = 17;
    numRocks += 1;
  }

  coinCount--;
  if (coinCount <= 0)
  {
    coinCount = rand() % maxCoinCount + maxCoinCount;
		coins[numCoins].x = rand() % 7 + 1;
		coins[numCoins].y = 17;
    numCoins += 1;
  }
}

/**
 * Process the update loop for this GameController
 */
void GameController::update(float dt)
{
  Accelerometer_GetState(&state);
  if (state.x > fastTurn)
  { //Big right move
    player->dx = 0.05;
  }
  else if (state.x > slowTurn)
  { //Small right move
    player->dx = 0.01;
  }
  else if (state.x < (-1 * fastTurn))
  { //Big left move
    player->dx = -0.05;
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
  for (int i = 0; i < numRocks; i++)
  {
    rocks[i].update(dt);
		if ((floor(rocks[i].y)==0) && (floor(player->x) == floor(rocks[i].x))){
			isDed = true;
		}
  }
  for (int i = 0; i < numCoins; i++)
  {
    coins[i].update(dt);
  }
}