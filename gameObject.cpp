#include "gameObject.h"
#include "cmath"

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

void Player::draw(Board b)
{
  b.draw(floor(x), floor(y), YELLOW)
}