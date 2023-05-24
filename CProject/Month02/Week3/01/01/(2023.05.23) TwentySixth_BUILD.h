#pragma once

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

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

enum Maze
{
	MAZE_HEITH = 30,
	MAZE_WIDTH = 30,
	ENEMY_MAX = 30,
	SPAWN_TIME = 500,
	DROP_TIME = 50,

	MAZE_ROAD = L'0',
	MAZE_WALL,
	MAZE_START,
	MAZE_EXIT
};

enum ARROWS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

// 플레이어 구조체
struct Player
{
	COORD pos;			// 좌표
	const char* shape;	// 모양
};

struct Enemy
{
	COORD pos;			// 좌표
	const char* shape;	// 모양
	int enabled;		// 출력여부
};

struct EnemyPool
{
	Enemy enemy[ENEMY_MAX];
	int currentSize;
};

clock_t prevTime = 0, currTime = 0;
unsigned BestScore = 0, Score = 0;
bool isGameOver = 0;


// 좌표 이동 함수
void GotoXY(int x, int y);
void TextColor(int clolrCode);
void TimePass();
clock_t DeltaTime();

// 게임 초기화
COORD RandomPos();
void InitGame(Player* ptrPlayer, EnemyPool* ptrEnemyPool);
bool IsGameOver(Player ptrPlayer, EnemyPool ptrEnemyPool);
void OutputMaze(Player player, Enemy enemys[], int idxSize);
void DropEnemy(Enemy* ptrEnemys, int idxSize);
void Keyboard(Player* ptrPlayer);



int main()
{
	system("mode con cols=62 lines=35 | title 똥피하기");
	srand((unsigned)time(NULL));


	clock_t dropDelayTime = 0, spawnDelayTime = 0;

	Player player;
	EnemyPool enemyPool;

	InitGame(&player, &enemyPool);
	Enemy* enemys = enemyPool.enemy;
	int* enemyIdx = &enemyPool.currentSize;

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemys[i].pos = RandomPos();
		enemys[i].shape = "♥";
	}

	while (true)
	{
		if (IsGameOver(player, enemyPool))
		{
			break;
		}

		dropDelayTime += DeltaTime();
		spawnDelayTime += DeltaTime();

		if (spawnDelayTime > SPAWN_TIME && *enemyIdx < ENEMY_MAX)
		{
			(*enemyIdx)++;
			enemys[*enemyIdx].enabled = 1;
			spawnDelayTime = 0;
		}

		if (dropDelayTime > DROP_TIME)
		{
			DropEnemy(enemys, *enemyIdx);
			dropDelayTime = 0;
		}

		Keyboard(&player);
		OutputMaze(player, enemys, *enemyIdx);

		TimePass();
	}

	TextColor(RED);
	printf("\n\nGame Over!!!\n\n");

	return 0;
}

void GotoXY(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void TextColor(int colorCode)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

void TimePass()
{
	prevTime = currTime;
	currTime = clock();
}

clock_t DeltaTime()
{
	return (currTime - prevTime);
}


COORD RandomPos()
{
	COORD pos = { rand() % MAZE_WIDTH, 0 };
	return pos;
}

void InitGame(Player* ptrPlayer, EnemyPool* ptrEnemyPool)
{
	prevTime = 0, currTime = 0;
	Score = 0;

	const COORD playerStart = { MAZE_WIDTH / 2, MAZE_HEITH };
	ptrPlayer->pos = playerStart;
	ptrPlayer->shape = "＠";

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		ptrEnemyPool->enemy[i].pos = RandomPos();
		ptrEnemyPool->enemy[i].shape = "♥";
	}
	ptrEnemyPool->currentSize = -1;
}

bool IsGameOver(Player ptrPlayer, EnemyPool ptrEnemyPool)
{
	for (int i = 0; i < ptrEnemyPool.currentSize; i++)
	{
		if (ptrEnemyPool.enemy[i].pos.Y == ptrPlayer.pos.Y &&
			ptrEnemyPool.enemy[i].pos.X == ptrPlayer.pos.X)
		{
			return true;
		}
	}

	return false;
}

void DropEnemy(Enemy* enemys, int idxSize)
{
	for (int i = 0; i < idxSize; i++)
	{
		if (enemys[i].enabled)
		{
			if (enemys[i].pos.Y < MAZE_HEITH + 2)
			{
				enemys[i].pos.Y++;
			}
			else
			{
				enemys[i].pos.X = rand() % MAZE_WIDTH;
				enemys[i].pos.Y = 0;
			}
		}
	}
}

void OutputMaze(Player player, Enemy enemys[], int idxSize)
{
	for (int i = 0; i < idxSize; i++)
	{
		if (enemys[i].enabled)
		{
			GotoXY(enemys[i].pos.X, enemys[i].pos.Y);
			TextColor(YELLOW);
			printf("%s", enemys[i].shape);
		}
	}

	GotoXY(player.pos.X, player.pos.Y);
	TextColor(BLUE);
	printf("%s", player.shape);

	GotoXY(0, 32);
	TextColor(GREEN);
	printf("==============================================================\n");

	Sleep(17);
	system("cls");
}

void Keyboard(Player* ptrPlayer)
{
	COORD* pos = &ptrPlayer->pos;
	char key = 0;
	if (_kbhit())
	{
		key = _getch();
		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case LEFT:
			if (ptrPlayer->pos.X > 0)
			{
				pos->X--;
			}
			break;
		case RIGHT:
			if (ptrPlayer->pos.X < MAZE_WIDTH)
			{
				pos->X++;
			}
			break;
		default:
			break;
		}
	}
}