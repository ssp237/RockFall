#ifndef gameObject_h
#define gameObject_h

#include "gameboard.h"

const float g = 5;

/*
*   Enumeration of possible obstacle types (used to resolve collisions and 
*   set behavior)
*/
enum ObstacleType
{
  PLAYER,
  COIN,
  ROCK
};

/* 
*   Abstract class to serve as a header class for all game objects
*/
class Obstacle
{
public:
  // Velocity
  float dx;
  float dy;
  //Position
  float x;
  float y;

  virtual ObstacleType getType() = 0;
  virtual void draw(GameBoard &b) = 0;
  virtual void update(float dt) = 0;

private:
};

/* 
*   Implementation of Obstacle: player
*/
class Player : public Obstacle
{
public:
  Player(float init_x, float init_y);
  ObstacleType getType();
  void draw(GameBoard &b);
  void update(float dt);

private:
};

/**Implementation of Obstacle : rock */
class Rock : public Obstacle
{
public:
  Rock(float init_x, float init_y);
  ObstacleType getType();
  void draw(GameBoard &b);
  void update(float dt);

private:
};
#endif
