#pragma once

/* 
*   Implementation of an abstract class to control different game modes. 
*   Must provide certain base functionality that I have not yet decided in order
*   to allow the necessary switching behavior. 
*/
virtual class Controller
{
public:
  virtual void render();
  virtual void update();
  virtual void preUpdate();
  virtual void draw();

private:
}

/* 
*   Implementation of a class (rockFall) to run the main game. This class
*   assigns controllers to write output to the board, and processes requests
*   to switch controllers.
*/
class RockFall
{
public:
  void exitScreen(Controller screen, int exitcode);
  void setScreen(Controller c);
  void run();

private:
  Controller[] controllers;
}