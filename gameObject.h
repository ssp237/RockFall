#include "board.h"

#pragma once

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
  virtual void draw(Board b);
  virtual void update();

private:
}

/* 
*   Implementation of Obstacle: player
*/
class Player : public Obstacle
{
public:
  Player(int init_x, int init_y);
  ObstacleType getType();
  void draw(Board b);
  void update();

private:
}