#pragma once

#include <time.h>
#include <queue>

enum COLORS
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKY_BLUE,
	DARK_RED,
	DARK_PURPLE,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKY_BLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
};

enum ARROW_KEYS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	SPACE = 32,

	KEY_R = 'R',
	KEY_r = 'r',
};

enum SIZE_CONSTANTS
{
	BEZEL = 1,
	WIDTH = 38,
	HEIGTH = 22,
	GAME_WIDTH = 10,
	GAME_HEIGHT = 20,
	TETRIS_DRAW = 4,
	NEXT_MAX = 5,
	SCORE_WIDTH = 15,
	SCORE_HEIGHT = 5
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

struct Tetris
{
	int bType;
	int bRotate;
};

struct Player
{
	Pos pos;
	Tetris status;
};

clock_t DeltaTime();
int CreateBType();
Player CreateNewTetris();
COLORS GetTetrisColor(Player player);

void LoadBestScore(const char * dataFileName);
void MakeBestScore(const char* dataFileName);

void GameInit();
void GamePrint(Player player);
void UpdataGameMap();
void UpdataPlayer(Player player);
void UpdateText();
void UpdateNextTetris();
void UpdateTetris(Player& player);

void Keyboard(Player& player);
void MoveTetris(Player &player, clock_t &dropTimer);
void DropTetris(Player& player);

void RotationTetris(int &rotate);
void SRSSystem(Player& player, int prevrotate);

void HoldTetris(Player& player);

bool isCollide(Player player);
void StopTetris(Player &player);
void CollideCheck(Player& player, Player prevStatus);

void GameOverCheck(Player player);
void LineClearCheck(Player player);
void GameLogic(Player player);