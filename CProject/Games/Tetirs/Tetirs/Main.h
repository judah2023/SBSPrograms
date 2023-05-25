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

struct Pos
{
	int x;
	int y;
};

void Keyboard(Pos* ptrPlayer);