#include "gameboard.h"
#include "stdint.h"

//Constructor
GameBoard::GameBoard()
{
  topBuff = new uint8_t[17];
  botBuff = new uint8_t[17];
}

void GameBoard::draw(int x, int y, Color c)
{
  switch (c)
  {
  case RED:
    drawRed(x, y);
    break;
  case YELLOW:
    drawYellow(x, y);
    break;
  case GREEN: drawGreenx, y);
    break;
  }
}

void GameBoard::pushToBoard()
{
}

void GameBoard::resetBoard()
{
  for (uint8_t i = 0; i <= 16; i++)
  {
    topBuff[i] = 0;
    botBuff[i] = 0;
  }
}

void GameBoard::drawGreen(int x, int y)
{
}

void GameBoard::drawYellow(int x, int y)
{
}

void GameBoard::drawRed(int x, int y)
{
}