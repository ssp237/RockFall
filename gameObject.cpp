#include "gameObject.h"
#include "math.h"

float max(float a, float b)
{
  return a > b ? a : b;
}

float min(float a, float b)
{
  return a < b ? a : b;
}

/*
*   Create a player with initial position (init_x, init_y) and velocity 0.
*/
Player::Player(float init_x, float init_y)
{
  x = init_x;
  y = init_y;
  dx = 0;
  dy = 0;
}

void Player::draw(GameBoard &b)
{
  b.draw(floor(x), floor(y), GREEN);
}

void Player::update(float dt)
{
  x += dx;
  x = max(1, min(8, x));
  y += dy;
  y = max(1, min(16, y));
}

ObstacleType Player::getType()
{
  return PLAYER;
}

Rock::Rock() {
	x = -1;
	y = -1;
	dx = 0;
	dy = 0;
}

/**
 * Create a rock with position init_x, init_y and velocity 0
 */
Rock::Rock(float init_x, float init_y)
{
  x = init_x;
  y = init_y;
  dx = 0;
  dy = 0;
}

/**
 * Draw this rock to the game board
 */
void Rock::draw(GameBoard &board)
{
  board.draw(floor(x), floor(y), RED);
}

/**
 * Update this rock's position
 */
void Rock::update(float dt)
{
  dy -= g;
  y = max(1, y + dy);
}

ObstacleType Rock::getType()
{
  return ROCK;
}

Coin::Coin() {
	x = -1; 
	y = -1;
	dx = 0;
	dy = 0;
	fall_speed = 0.01;
}

/**
 * Create a coin with position init_x, init_y and velocity 0
 */
Coin::Coin(float init_x, float init_y)
{
  x = init_x;
  y = init_y;
  dx = 0;
  dy = 0;
	fall_speed = 0.01;
}

/**
 * Draw this rock to the game board
 */
void Coin::draw(GameBoard &board)
{
  board.draw(floor(x), floor(y), ORANGE);
}

/**
 * Update this coin's position
 */
void Coin::update(float dt)
{
  y = max(1, y - fall_speed);
}

ObstacleType Coin::getType()
{
  return COIN;
}