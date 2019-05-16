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
	if (x < 1 || y < 1 || x > 8 || y > 16)
		return;
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
	if (y > 8)
	{
		topBuff[(2 * (y - 8)) - 1] |= (128 >> (x - 1));
	}
	else
	{
		botBuff[(2 * y) - 1] |= (128 >> (x - 1));
	}
}

void GameBoard::drawRed(int x, int y)
{
	{
		if (y > 8)
		{
			topBuff[(2 * (y - 8))] |= (128 >> (x - 1));
		}
		else
		{
			botBuff[(2 * y)] |= (128 >> (x - 1));
		}
	}
}

void GameBoard::drawOrange(int x, int y)
{
	drawRed(x, y);
	drawGreen(x, y);
}

void GameBoard::deathScreen()
{
	topBuff[16] |= 56;
	topBuff[14] |= 40;
	topBuff[12] |= 48;
	topBuff[10] |= 40;
	topBuff[8] |= 36;
	topBuff[4] |= 56;
	topBuff[2] |= 16;
	botBuff[16] |= 16;
	botBuff[14] |= 56;
	botBuff[10] |= 56;
	botBuff[8] |= 40;
	botBuff[6] |= 56;
	botBuff[4] |= 32;
	botBuff[2] |= 32;
}

void GameBoard::scoreScreen(uint8_t s)
{
	uint8_t d1 = s % 10;
	uint8_t d2 = floor(s / 10) % 10;
	switch (d1)
	{
	case 0:
		displayZero(botBuff);
	}
	switch (d2)
	{
	case 0:
		displayZero(topBuff);
	}
}

void displayZero(uint8_t *b)
{
	b[15] |= 56;
	b[13] |= 68;
	b[11] |= 76;
	b[9] |= 84;
	b[7] |= 100;
	b[5] |= 68;
	b[3] |= 56;
}
