#include "Main.h"

#include "Double_Buffering.h"

char GameMap[HEIGTH][WIDTH + 1];
char Tetrises[7][4][4][5] = {
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
			"0400",
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

clock_t prevClock, currClock, dropDelay = 1;

std::queue<Tetris> nextTetris;

int main()
{
	// 게임 초기화
	GameInit();

	Player player = CreateNewTetris();

	clock_t dropTimer = 0;

	while (true)
	{
		dropTimer += DeltaTime();
		MoveTetris(player, dropTimer);
		GamePrint(player);
	

		// 버퍼 교체
		ScreenFlipping();

		// 교체된 버퍼 비우기
		ScreenClear();
	}

	// 종료 시, 버퍼를 해제
	ScreenRelease();
	return 0;
}

int CreateBType()
{
	return rand() % 7;
}

Player CreateNewTetris()
{
	Pos blockStart = { 4, 1 };
	Tetris newTetris = { CreateBType(), 0 };
	Player newPlayer = { blockStart, newTetris };
	return newPlayer;
}

clock_t DeltaTime()
{
	clock_t deltaTime = currClock - prevClock;
	prevClock = currClock;
	currClock = clock();

	return deltaTime;
}

void MoveTetris(Player& player, clock_t& dropTimer)
{
	Pos prevPos = player.pos;
	int prevRotate = player.status.bRotate;
	Keyboard(player);

	if (player.status.bRotate != prevRotate)
	{
		SRSSystem(player, prevRotate);
	}
	else
	{
		if (isCollide(player))
		{
			player.pos = prevPos;
			if (player.pos.y > prevPos.y)
			{
				StopTetris(player);
			}
		}
	}

	if (dropTimer >= dropDelay * 1000)
	{
		DropTetris(player);
		dropTimer = 0;
	}
}

void DropTetris(Player& player)
{
	Pos prevPos = player.pos;

	player.pos.y++;

	if (isCollide(player))
	{
		player.pos = prevPos;
		StopTetris(player);
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
			RotationTetris(player.status.bRotate);
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

bool isCollide(Player player)
{
	Pos collidePos = { gameMapPos.x + player.pos.x - BEZEL ,gameMapPos.y + player.pos.y - BEZEL };
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (Tetrises[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE && GameMap[collidePos.y + i][collidePos.x + j] > EMPTY)
			{
				return true;
			}
		}
	}
	return false;
}

void StopTetris(Player &player)
{
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (Tetrises[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
			{
				GameMap[gameMapPos.y + player.pos.y + i - 1][gameMapPos.x + player.pos.x + j - 1] = BLOCK_STOP;
			}
		}
	}

	player = CreateNewTetris();
}

void RotationTetris(int& rotate)
{
	rotate = ++rotate % 4;
}

void SRSSystem(Player& player, int prevRotate)
{
	if (isCollide(player))
	{
		player.status.bRotate = prevRotate;
	}
}

void GameInit()
{
	ScreenInit();
	srand((unsigned)time(NULL));

	for (int i = 0; i < HEIGTH; i++)
		strcpy_s(GameMap[i], "33333333333333333333333333333333333333");

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			GameMap[holdMapPos.x + i][holdMapPos.y + j] = EMPTY;
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			GameMap[gameMapPos.y + i][gameMapPos.x + j] = EMPTY;
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			GameMap[nextMapPos.y + i][nextMapPos.x + j] = EMPTY;
		}
	}

	for (int n = 0; n < NEXT_MAX; n++)
	{
		Tetris newTetris = { CreateBType(), 0 };
		
		for (int i = 0; i < TETRIS_DRAW; i++)
		{
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				GameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j] = Tetrises[newTetris.bType][newTetris.bRotate][i][j];
			}
		}
	}

	currClock = clock();
}

void GamePrint(Player player)
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

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (Tetrises[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
			{
				ScreenPrint(gameMapPos.x + player.pos.x + j, gameMapPos.y + player.pos.y + i, "■");
			}
		}
	}
}