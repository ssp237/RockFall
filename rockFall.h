#include "gameObject.h"
/* 
*   Implementation of an abstract class to control different game modes. 
*   Must provide certain base functionality that I have not yet decided in order
*   to allow the necessary switching behavior. 
*/
class Controller
{
public:
  Obstacle *objects;
  virtual void render();
  virtual void update(float dt);
  virtual void preUpdate();
  virtual void draw(GameBoard &board);

private:
  GameBoard board;
};

/**
 * Implementation of Controller to run the main game.
 */
class GameController : public Controller
{
public:
  Player *player;
  void render();
  void update(float dt);
  void preUpdate();
  void draw(GameBoard &board);
  GameController(GameBoard &board_ref);

private:
  GameBoard board;
	int objectSize; 
};

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
  RockFall();

private:
  GameController *game; 
  GameBoard *board;
};