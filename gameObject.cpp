#include "gameObject.h"
#include "math.h"

float max(float a, float b) {
	return a > b ? a : b;
}

float min(float a, float b) {
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
  b.draw(floor(x), floor(y), ORANGE);
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