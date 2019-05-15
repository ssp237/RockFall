#include "gameboard.h"

#pragma once

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
virtual class Obstacle
{
public:
  // Velocity
  float dx;
  float dy;
  //Position
  float x;
  float y;

  virtual ObstacleType getType();
  virtual void draw(Board &b);
  virtual void update(float dt);

private:
}

/* 
*   Implementation of Obstacle: player
*/
class Player : public Obstacle
{
public:
  Player(float init_x, float init_y);
  ObstacleType getType();
  void draw(Board &b);
  void update(float dt);

private:
}

/**Implementation of Obstacle : rock */
class Rock : public Obstacle
{
public:
  Rock(float init_x, float init_y);
  ObstacleType getType();
  void draw(Board &b);
  void update(float dt);

private:
}