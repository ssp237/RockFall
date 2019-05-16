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
  b.draw(floor(x), floor(y), ORANGE);
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