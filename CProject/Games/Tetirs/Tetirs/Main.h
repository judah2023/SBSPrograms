#pragma once

#include "Double_Buffering.h"

enum COLORS
{
	BLACK,
	BLUE,
	GREEN,
	JADE,
	RED,
	PURPLE,
	YELLOW,
	GRAY,
	WHITE
};

enum ARROW_KEYS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

enum SIZE_CONSTANTS
{
	BEZEL = 1,
	WIDTH = 38,
	HEIGTH = 22,
	GAME_WIDTH = 10,
	GAME_HEIGHT = 20,
	TETRIS_DRAW = 4
};

enum TETRIS_STATUS
{
	EMPTY = '0',
	BLOCK_STOP,
	FLOOR,
	WALL,
	BLOCK_MOVE,
};

enum MOVE_STATUS
{
	ROTATING = 0,
	MOVING = 1
};

struct Pos
{
	int x;
	int y;
};

struct Player
{
	Pos pos;
	int bType;
	int bRotate;
};

char GameMap[HEIGTH][WIDTH + 1];

char Tetris[7][4][4][5] = {
	// J Block
	{
		{
			"4000",
			"4440",
			"0000",
			"0000"
		},{
			"0440",
			"0400",
			"0400",
			"0000"
		},{
			"0000",
			"4440",
			"0040",
			"0000"
		},{
			"0400",
			"0400",
			"4400",
			"0000"
		},
	},

	// L Block
	{
		{
			"0040",
			"4440",
			"0000",
			"0000"
		},{
			"0400",
			"0400",
			"0440",
			"0000"
		},{
			"0000",
			"4440",
			"4000",
			"0000"
		},{
			"4400",
			"0400",
			"0400",
			"0000"
		},
	},

	// S Block
	{
		{
			"0440",
			"4400",
			"0000",
			"0000"
		},{
			"0400",
			"0440",
			"0040",
			"0000"
		},{
			"0000",
			"0440",
			"4400",
			"0000"
		},{
			"4000",
			"4400",
			"0400",
			"0000"
		},
	},

	// Z Block
	{
		{
			"4400",
			"0440",
			"0000",
			"0000"
		},{
			"0040",
			"0440",
			"0440",
			"0000"
		},{
			"0000",
			"4400",
			"0440",
			"0000"
		},{
			"0400",
			"4400",
			"4000",
			"0000"
		},
	},

	// T Block
	{
		{
			"0400",
			"4440",
			"0000",
			"0000"
		},{
			"0400",
			"0440",
			"0400",
			"0000"
		},{
			"0000",
			"4440",
			"0400",
			"0000"
		},{
			"0400",
			"4400",
			"0400",
			"0000"
		},
	},

	// I Block
	{
		{
			"0000",
			"4444",
			"0000",
			"0000"
		},{
			"0040",
			"0040",
			"0040",
			"0040"
		},{
			"0000",
			"0000",
			"4444",
			"0000"
		},{
			"0400",
			"0400",
			"0400",
			"0400"
		},
	},
				
	// O Block
	{
		{
			"0000",
			"0440",
			"0440",
			"0000"
		},{
			"0000",
			"0440",
			"0440",
			"0000"
		},{
			"0000",
			"0440",
			"0440",
			"0000"
		},{
			"0000",
			"0440",
			"0440",
			"0000"
		},
	},
};

Pos holdMapPos = { 1, 1 }, gameMapPos = { 6, 1 }, nextMapPos = { 17, 1 };
Pos blockStart = { 4,0 };

void MoveTetris(Player &player);

void Keyboard(Player& player);

void RotationTetris(int &rotate);

void GameInit();

void GamePrint();
