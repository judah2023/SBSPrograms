#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

enum Maze
{
	MAZE_SIZE = 12,

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

// 플레이어 구조체
struct Player
{
	COORD pos;			// 좌표
	const char* shape;	// 모양
};

// 미로 맵 데이터
TCHAR maze[MAZE_SIZE][MAZE_SIZE];

// 좌표 이동 함수
void GotoXY(int x, int y);

bool isEqualCoord(COORD playerPos, COORD destination);

// 미로 맵 생성
void InitGame();

void Renderer();

void OutputMaze(Player player);

void Keyboard(TCHAR maze[MAZE_SIZE][MAZE_SIZE], Player *ptrPlayer);

int main()
{
	const COORD destination = { 0, 1 };
	const COORD start = { 9, 9 };
	Player player = { start, "＠"};
	bool isGameClear = 1;

	InitGame();
	while (isGameClear)
	{
		if (isEqualCoord(player.pos, destination))
		{
			isGameClear = 0;
		}
		Keyboard(maze, &player);

		OutputMaze(player);
		Sleep(17);
		system("cls");
	}

	printf("미로를 탈출했습니다!!!\n");
	system("pause");

	return 0;
}

void GotoXY(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool isEqualCoord(COORD playerPos, COORD destination)
{
	if (playerPos.X == destination.X)
		if (playerPos.Y == destination.Y)
			return true;

	return false;
}

// 미로 맵 생성
void InitGame()
{
	// 0 : 통로, 1 : 벽, 2 : 탈출구, 3 : 시작 점
	wcscpy_s(maze[0], L"1111111111");
	wcscpy_s(maze[1], L"3000010001");
	wcscpy_s(maze[2], L"1111011011");
	wcscpy_s(maze[3], L"1010010001");
	wcscpy_s(maze[4], L"1011011011");
	wcscpy_s(maze[5], L"1001000001");
	wcscpy_s(maze[6], L"1011001111");
	wcscpy_s(maze[7], L"1011101001");
	wcscpy_s(maze[8], L"1010101101");
	wcscpy_s(maze[9], L"10000000002");
	wcscpy_s(maze[10],L"1111111111");
	wcscpy_s(maze[11],L"");
	
	CONSOLE_CURSOR_INFO cursor = {0, };
	cursor.dwSize = 1;
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void Renderer()
{
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			switch (maze[i][j])
			{
			case MAZE_ROAD:
				printf("  ");
				break;
			case MAZE_WALL:
				printf("■");
				break;
			case MAZE_EXIT:
				printf("☆");
				break;
			case MAZE_START:
				printf("←");
				break;
			case '\0':
				printf("\n");
				break;
			default:
				break;
			}
		}
	}
}

void OutputMaze(Player player)
{
	Renderer();
	GotoXY(player.pos.X, player.pos.Y);
	printf("%s", player.shape);
}

void Keyboard(TCHAR maze[MAZE_SIZE][MAZE_SIZE], Player* ptrPlayer)
{
	COORD *pos = &ptrPlayer->pos;
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
		case UP:
			if (maze[pos->Y - 1][pos->X] != MAZE_WALL && ptrPlayer->pos.Y > 0)
			{
				pos->Y--;
			}
			break;
		case LEFT:
			if (maze[pos->Y][pos->X - 1] != MAZE_WALL && ptrPlayer->pos.X > 0)
			{
				pos->X--;
			}
			break;
		case RIGHT:
			if (maze[pos->Y][pos->X + 1] != MAZE_WALL && ptrPlayer->pos.X < MAZE_SIZE - 3)
			{
				pos->X++;
			}
			break;
		case DOWN:
			if (maze[pos->Y + 1][pos->X] != MAZE_WALL && ptrPlayer->pos.Y < MAZE_SIZE - 2)
			{
				pos->Y++;
			}
			break;
		default:
			break;
		}
	}
}