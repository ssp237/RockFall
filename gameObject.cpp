#include "gameObject.h"
#include "math.h"

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
  y += dy;
}

ObstacleType Player::getType()
{
  return PLAYER;
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
 * Create a coin with position init_x, init_y and velocity 0
 */
Coin::Coin(float init_x, float init_y)
{
  x = init_x;
  y = init_y;
  dx = 0;
  dy = 0;
}

/**
 * Draw this rock to the game board
 */
void Coin::draw(GameBoard &board)
{
  board.draw(floor(x), floor(y), ORANGE);
}