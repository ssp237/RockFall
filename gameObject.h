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
  virtual void draw();
  virtual void update();

private:
}

/* 
*   Implementation of Obstacle: player
*/
class Player : public Obstacle
{
public:
  ObstacleType getType();
  void draw();
  void update();

private:
}