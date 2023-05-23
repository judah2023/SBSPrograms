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
	ENEMY_SIZE = 30,

	MAZE_ROAD = L'0',
	MAZE_WALL,
	MAZE_START,
	MAZE_EXIT
};

enum Arrows
{
	UP		= 72,
	LEFT	= 75,
	RIGHT	= 77,
	DOWN	= 80
};

int map[MAZE_HEITH][MAZE_WIDTH] = { 0 };

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

// 좌표 이동 함수
void GotoXY(int x, int y);

void TextColor(int clolrCode);

void OutputMaze(Player player, Enemy enemys[], int idxSize);

void DropEnemy(Enemy(*enemys)[ENEMY_SIZE], int idxSize);

void Keyboard(Player* ptrPlayer);

COORD RandomPos();


int main()
{
	system("mode con cols=62 lines=35 | title 똥피하기");
	srand((unsigned)time(NULL));

	const COORD playerStart = { MAZE_WIDTH / 2, MAZE_HEITH };
	clock_t dropDelayTime = 0, spawnDelayTime = 0;
	clock_t firstTime = 0, lastTime = 0;
	Player player = { playerStart, "＠"};
	bool isGameOver = 0;
	
	Enemy enemy = { RandomPos(), "■", 1 };
	Enemy enemys[ENEMY_SIZE];
	int enemyIdx = 0;

	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		enemys[i].pos = RandomPos();
		enemys[i].shape = "■";
	}

	while (!isGameOver)
	{
		if (enemy.pos.X == player.pos.X &&
			enemy.pos.Y == player.pos.Y)
		{
			isGameOver = 1;
		}

		lastTime = clock();
		dropDelayTime += (lastTime - firstTime);
		spawnDelayTime += (lastTime - firstTime);

		if (spawnDelayTime > 500 && enemyIdx < ENEMY_SIZE)
		{
			enemys[enemyIdx].enabled = 1;
			spawnDelayTime = 0;
			enemyIdx++;
		}

		if (dropDelayTime > 50)
		{
			DropEnemy(&enemys, enemyIdx);
			dropDelayTime = 0;
		}

		Keyboard(&player);
		OutputMaze(player, enemys, enemyIdx);
		Sleep(17);
		system("cls");
		firstTime = lastTime;
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

void DropEnemy(Enemy (*enemys)[ENEMY_SIZE], int idxSize)
{
	for (int i = 0; i < idxSize; i++)
	{
		if (enemys[i]->pos.Y < MAZE_HEITH)
		{
			enemys[i]->pos.Y++;
		}
		else
		{
			enemys[i]->pos.X = rand() % MAZE_WIDTH;
			enemys[i]->pos.Y = 0;
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
			if ( ptrPlayer->pos.X < MAZE_WIDTH)
			{
				pos->X++;
			}
			break;
		default:
			break;
		}
	}
}

COORD RandomPos()
{
	COORD pos = { rand() % MAZE_WIDTH, 0 };
	return pos;
}