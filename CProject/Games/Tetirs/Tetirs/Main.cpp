#include "Main.h"



int main()
{
	// 게임 초기화
	GameInit();

	Player player = { {3, 1}, 0, 0 };

	while (true)
	{
		GamePrint();
		//Keyboard(player.pos);
		MoveTetris(player);

		for (int i = 0; i < TETRIS_DRAW; i++)
		{
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				if (Tetris[player.bType][player.bRotate][i][j] == '4')
				{
					ScreenPrint(gameMapPos.x + player.pos.x + j, gameMapPos.y + player.pos.y + i, "■");
				}
			}
		}

		// 버퍼 교체
		ScreenFlipping();

		// 교체된 버퍼 비우기
		ScreenClear();
	}

	// 종료 시, 버퍼를 해제
	ScreenRelease();
	return 0;
}

void MoveTetris(Player &player)
{
	Pos prevPos = player.pos;
	int prevrotate = player.bRotate;
	if (Keyboard(player) == ROTATING)
	{

	}
	else
	{

	}


}

void Keyboard(Player& player)
{
	Pos &playerPos = player.pos;
	char key = 0;
	if (_kbhit())
	{
		key = _getch();
		if (key == -32)
			key = _getch();

		switch (key)
		{
		case UP:
			RotationTetris(player.bRotate);
			break;
		case LEFT:
			playerPos.x--;
			break;
		case RIGHT:
			playerPos.x++;
			break;
		case DOWN:
			playerPos.y++;
			break;
		default:
			break;
		}
	}
}

void RotationTetris(int& rotate)
{
	rotate = ++rotate % 4;
}

void GameInit()
{
	ScreenInit();
	for (int i = 0; i < HEIGTH; i++)
		strcpy_s(GameMap[i], "33333333333333333333333333333333333333");

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			GameMap[holdMapPos.x + i][holdMapPos.y + j] = '0';
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			GameMap[gameMapPos.y + i][gameMapPos.x + j] = '0';
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			GameMap[nextMapPos.y + i][nextMapPos.x + j] = '0';
		}
	}
}

void GamePrint()
{
	char cell;
	for (int i = 0; i < HEIGTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			cell = GameMap[i][j];

			switch (cell)
			{
			case EMPTY:
				ScreenPrint(j + BEZEL, i + BEZEL, " ");
				break;
			case BLOCK_STOP:
			case BLOCK_MOVE:
				ScreenPrint(j + BEZEL, i + BEZEL, "■");
				break;
			case FLOOR:
			case WALL:
				ScreenPrint(j + BEZEL, i + BEZEL, "▣");
				break;
			default:
				break;
			}
		}
	}
}