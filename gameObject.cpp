#include "gameObject.h"

/*
*   Create a player with initial position (init_x, init_y) and velocity 0.
*/
Player::Player(int init_x, int init_y)
{
  x = init_x;
  y = init_y;
  dx = 0;
  dy = 0;
}

Player::draw(Board b)
{
  b.draw(x, y, YELLOW)
}