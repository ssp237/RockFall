#include "stdint.h"
/*
*   Enumeration of possible colors
*/
enum Color
{
  RED,
  GREEN,
  YELLOW
};

/*
*   An instance represents the game board, with the bottom left corner indexed *   at (0,0). Indices are bounded by [0,7] in the x direction and [0,15] in 
*   the y direction. Positions above (x,7) (e.g (5,9)) are drawn on the upper
*   board. 
*   Provides drawing methods to abstract out drawing. 
*/
class GameBoard
{
public:
  uint8_t * board;
  void draw(int x, int y, Color c);
  void pushToBoard();
  void resetBoard();
	GameBoard();

private:
  void drawGreen(int x, int y);
  void drawYellow(int x, int y);
  void drawRed(int x, int y);
};