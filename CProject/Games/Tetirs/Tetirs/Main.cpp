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

bool isGameOver;

std::queue<Player> nextTetris;

int main()
{
	// 게임 초기화
	GameInit();

	Player player = CreateNewTetris();

	clock_t dropTimer = 0;

	while (!isGameOver)
	{
		dropTimer += DeltaTime();
		GamePrint(player);
		MoveTetris(player, dropTimer);
	

		// 버퍼 교체
		ScreenFlipping();

		// 교체된 버퍼 비우기
		ScreenClear();
	}

	// 종료 시, 버퍼를 해제
	ScreenRelease();
	return 0;
}

clock_t DeltaTime()
{
	clock_t deltaTime = currClock - prevClock;
	prevClock = currClock;
	currClock = clock();

	return deltaTime;
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


void GameInit()
{
	ScreenInit();
	srand((unsigned)time(NULL));

	isGameOver = 0;

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

	/*for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			GameMap[nextMapPos.y + i][nextMapPos.x + j] = EMPTY;
		}
	}*/

	for (int n = 0; n < NEXT_MAX; n++)
	{
		Player newTetris = CreateNewTetris();
		nextTetris.push(newTetris);

		for (int i = 0; i < TETRIS_DRAW; i++)
		{
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				GameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j] = Tetrises[newTetris.status.bType][newTetris.status.bRotate][i][j];
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
				TextColor(PURPLE);
				ScreenPrint(j + BEZEL, i + BEZEL, "■");
				break;
			case FLOOR:
			case WALL:
				TextColor(10);
				ScreenPrint(j + BEZEL, i + BEZEL, "▣");
				break;
			default:
				break;
			}
		}
	}

	TextColor(JADE);
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

void UpdateNextTetris()
{
	for (int n = 1; n < NEXT_MAX; n++)
		for (int i = 0; i < TETRIS_DRAW; i++)
			for (int j = 0; j < TETRIS_DRAW; j++)
				GameMap[nextMapPos.y + 4 * (n - 1) + i][nextMapPos.x + j] = GameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j];

	nextTetris.pop();
	Player newTetris = CreateNewTetris();
	nextTetris.push(newTetris);
	for (int i = 0; i < TETRIS_DRAW; i++)
		for (int j = 0; j < TETRIS_DRAW; j++)
			GameMap[nextMapPos.y + 4 * (NEXT_MAX - 1) + i][nextMapPos.x + j] = Tetrises[newTetris.status.bType][newTetris.status.bRotate][i][j];
}

void UpdateTetris(Player& player)
{
	player = nextTetris.front();
	UpdateNextTetris();
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

void MoveTetris(Player& player, clock_t& dropTimer)
{
	Player prevStatus = player;
	Keyboard(player);

	CollideCheck(player, prevStatus);

	if (dropTimer >= dropDelay * 1000)
	{
		DropTetris(player);
		dropTimer = 0;
	}
}

void DropTetris(Player& player)
{
	Player prevStatus = player;
	Pos prevPos = player.pos;

	player.pos.y++;

	CollideCheck(player, prevStatus);
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
		for (int j = 0; j < TETRIS_DRAW; j++)
			if (Tetrises[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
				GameMap[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + player.pos.x + j - BEZEL] = BLOCK_STOP;


	GameLogic(player);
	UpdateTetris(player);
}

void CollideCheck(Player& player, Player prevStatus)
{
	Pos prevPos = prevStatus.pos;
	int prevRotate = prevStatus.status.bRotate;

	if (player.status.bRotate != prevRotate)
	{
		SRSSystem(player, prevRotate);
	}
	else
	{
		if (isCollide(player))
		{
			if (player.pos.y > prevPos.y)
			{
				player.pos = prevPos;
				StopTetris(player);
			}
			else
			{
				player.pos = prevPos;
			}
		}
	}
}


void GameOverCheck(Player player)
{
	if (player.pos.y == 1)
		isGameOver = 1;
}

void LineClearCheck(Player player)
{
	int cnt, lineCnt = 0;
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		cnt = 0;
		for (int j = 0; j < GAME_WIDTH; j++)
			if (GameMap[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + j] == BLOCK_STOP)
				++cnt;

		if (cnt == 10)
		{
			++lineCnt;
			for (int k = 1; k < GAME_HEIGHT; k++)
			{
				cnt = 0;
				for (int j = 0; j < GAME_WIDTH; j++)
					if (GameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x  + j] == EMPTY)
						++cnt;

				if (cnt != 10)
				{
					for (int j = 0; j < GAME_WIDTH; j++)
						if (GameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j] < FLOOR)
							GameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] =
								GameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j];
				}
				else
				{
					for (int j = 0; j < GAME_WIDTH; j++)
						GameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] = EMPTY;
					break;
				}
			}
		}
	}
}

void GameLogic(Player player)
{
	GameOverCheck(player);
	LineClearCheck(player);
}