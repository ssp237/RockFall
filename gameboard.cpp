#include "gameboard.h"
#include "stdint.h"

//Constructor
GameBoard::GameBoard()
{
  topBuff = new uint8_t[17];
  botBuff = new uint8_t[17];
	resetBoard();
}

void GameBoard::draw(int x, int y, Color c)
{
  switch (c)
  {
  case RED:
    drawRed(x, y);
    break;
  case ORANGE:
    drawOrange(x, y);
    break;
  case GREEN:
    drawGreen(x, y);
    break;
  }
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
	if(y>8){
		topBuff[(2*(y-8))-1] |= (128 >> (x-1));
	}
	else{
		botBuff[(2*y)-1] |= (128 >> (x-1));
	}
}

void GameBoard::drawRed(int x, int y)
{
	{
	if(y>8){
		topBuff[(2*(y-8))] |= (128 >> (x-1));
	}
	else{
		botBuff[(2*y)] |= (128 >> (x-1));
	}
}
}

void GameBoard::drawOrange(int x, int y)
{
	drawRed(x, y);
	drawGreen(x, y);
}
