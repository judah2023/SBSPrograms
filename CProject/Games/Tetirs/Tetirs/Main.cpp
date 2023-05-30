#include "Main.h"

#include "Double_Buffering.h"

char gameMap[HEIGTH][WIDTH + 1];
char tetrominos[7][4][4][5] = {
	// J Block
	{
		{
			"0000",
			"4000",
			"4440",
			"0000"
		},{
			"0000",
			"0440",
			"0400",
			"0400"
		},{
			"0000",
			"0000",
			"4440",
			"0040",
		},{
			"0000",
			"0400",
			"0400",
			"4400"
		},
	},

	// L Block
	{
		{
			"0000",
			"0040",
			"4440",
			"0000"
		},{
			"0000",
			"0400",
			"0400",
			"0440"
		},{
			"0000",
			"0000",
			"4440",
			"4000"
		},{
			"0000",
			"4400",
			"0400",
			"0400"
		},
	},

	// S Block
	{
		{
			"0000",
			"0440",
			"4400",
			"0000"
		},{
			"0000",
			"0400",
			"0440",
			"0040"
		},{
			"0000",
			"0000",
			"0440",
			"4400"
		},{
			"0000",
			"4000",
			"4400",
			"0400"
		},
	},

	// Z Block
	{
		{
			"0000",
			"4400",
			"0440",
			"0000"
		},{
			"0000",
			"0040",
			"0440",
			"0400"
		},{
			"0000",
			"0000",
			"4400",
			"0440"
		},{
			"0000",
			"0400",
			"4400",
			"4000"
		},
	},

	// T Block
	{
		{
			"0000",
			"0400",
			"4440",
			"0000"
		},{
			"0000",
			"0400",
			"0440",
			"0400"
		},{
			"0000",
			"0000",
			"4440",
			"0400"
		},{
			"0000",
			"0400",
			"4400",
			"0400"
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

char scoreString[100], lineString[100];

Pos iSRSCoord[8][5] = {
	{
		{0,0},{-2,0},{+1,0},{-2,-1},{+1,+2}
	},{
		{0,0},{+2,0},{-1,0},{+2,+1},{-1,-2}
	},{
		{0,0},{-1,0},{+2,0},{-1,+2},{+2,-1}
	},{
		{0,0},{+1,0},{-2,0},{+1,-2},{-2,+1}
	},{
		{0,0},{+2,0},{-1,0},{+2,+1},{-1,-2}
	},{
		{0,0},{-2,0},{+1,0},{-2,-1},{+1,+2}
	},{
		{0,0},{+1,0},{-2,0},{+1,-2},{-2,+1}
	},{
		{0,0},{-1,0},{+2,0},{-1,+2},{+2,-1}
	}
};
Pos otherSRSCoord[8][5] = {
	{
		{0,0},{-1,0},{-1,+1},{0,-2},{-1,-2}
	},{
		{0,0},{+1,0},{+1,-1},{0,+2},{+1,+2}
	},{
		{0,0},{+1,0},{+1,-1},{0,+2},{+1,+2}
	},{
		{0,0},{-1,0},{-1,+1},{0,-2},{-1,-2}
	},{
		{0,0},{+1,0},{+1,+1},{0,-2},{+1,-2}
	},{
		{0,0},{-1,0},{-1,-1},{0,+2},{-1,+2}
	},{
		{0,0},{-1,0},{-1,-1},{0,+2},{-1,+2}
	},{
		{0,0},{+1,0},{+1,+1},{0,-2},{+1,-2}
	}
};
Pos holdMapPos = { 1, 1 }, gameMapPos = { 6, 1 }, nextMapPos = { 17, 1 }, scorePos = { 22, 1 }, blockStartPos = { 4, 0 };

clock_t prevClock, currClock, dropDelay = 1;

unsigned score, lines;
bool isGameOver;

std::queue<Player> nextTetris;

int main()
{
	// 게임 초기화
	GameInit();

	Player player = CreateNewTetris();

	clock_t dropTimer = 0;

	while (true)
	{
		while (isGameOver)
		{
			Keyboard(player);
		}
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
	Tetris newTetris = { CreateBType(), 0 };
	Player newPlayer = { blockStartPos, newTetris };
	return newPlayer;
}


void GameInit()
{
	ScreenInit();
	srand((unsigned)time(NULL));

	isGameOver = score = lines = 0;

	for (int i = 0; i < HEIGTH; i++)
		strcpy_s(gameMap[i], "33333333333333333333333333333333333333");

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			gameMap[holdMapPos.x + i][holdMapPos.y + j] = EMPTY;
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			gameMap[gameMapPos.y + i][gameMapPos.x + j] = EMPTY;
		}
	}

	for (int i = 0; i < SCORE_HEIGHT; i++)
	{
		for (int j = 0; j < SCORE_WIDTH; j++)
		{
			gameMap[scorePos.y + i][scorePos.x + j] = EMPTY;
		}
	}

	for (int n = 0; n < NEXT_MAX; n++)
	{
		Player newTetris = CreateNewTetris();
		nextTetris.push(newTetris);

		for (int i = 0; i < TETRIS_DRAW; i++)
		{
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				gameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j] = tetrominos[newTetris.status.bType][newTetris.status.bRotate][i][j];
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
			cell = gameMap[i][j];

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
			if (tetrominos[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
			{
				ScreenPrint(gameMapPos.x + player.pos.x + j, gameMapPos.y + player.pos.y + i, "■");
			}
		}
	}

	TextColor(WHITE);
	sprintf_s(scoreString, "%d", score);
	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL, " Score\t:");
	ScreenPrint(scorePos.x +BEZEL + 7, scorePos.y + BEZEL, scoreString);

	sprintf_s(lineString, "%d", lines);
	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL + 1, " Line\t:");
	ScreenPrint(scorePos.x + BEZEL + 7, scorePos.y + BEZEL + 1, lineString);

	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL + 3, "  00 : 00 : 00");

}

void UpdateNextTetris()
{
	for (int n = 1; n < NEXT_MAX; n++)
		for (int i = 0; i < TETRIS_DRAW; i++)
			for (int j = 0; j < TETRIS_DRAW; j++)
				gameMap[nextMapPos.y + 4 * (n - 1) + i][nextMapPos.x + j] = gameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j];

	nextTetris.pop();
	Player newTetris = CreateNewTetris();
	nextTetris.push(newTetris);
	for (int i = 0; i < TETRIS_DRAW; i++)
		for (int j = 0; j < TETRIS_DRAW; j++)
			gameMap[nextMapPos.y + 4 * (NEXT_MAX - 1) + i][nextMapPos.x + j] = tetrominos[newTetris.status.bType][newTetris.status.bRotate][i][j];
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

		if (!isGameOver)
		{
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
		else
		{
			switch (key)
			{
			case 'r':
			case 'R':
				isGameOver = 0;
				while (!nextTetris.empty())
					nextTetris.pop();

				GameInit();
				player = CreateNewTetris();
				break;
			default:
				break;
			}
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
	Player testPlayer;
	if (player.status.bType < 5)
	{
		for (int i = 0; i < 5; i++)
		{
			testPlayer = player;
			testPlayer.pos.x += otherSRSCoord[player.status.bRotate * 2][i].x;
			testPlayer.pos.y += otherSRSCoord[player.status.bRotate * 2][i].y;
			if (!isCollide(testPlayer))
			{
				player.pos.x = testPlayer.pos.x;
				player.pos.y = testPlayer.pos.y;
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			testPlayer = player;
			testPlayer.pos.x += iSRSCoord[player.status.bRotate * 2][i].x;
			testPlayer.pos.y += iSRSCoord[player.status.bRotate * 2][i].y;
			if (!isCollide(testPlayer))
			{
				player.pos.x = testPlayer.pos.x;
				player.pos.y = testPlayer.pos.y;
				return;
			}

		}
	}

	player.status.bRotate = prevRotate;
}


bool isCollide(Player player)
{
	Pos collidePos = { gameMapPos.x + player.pos.x - BEZEL ,gameMapPos.y + player.pos.y - BEZEL };
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (tetrominos[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE && gameMap[collidePos.y + i][collidePos.x + j] > EMPTY)
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
			if (tetrominos[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
				gameMap[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + player.pos.x + j - BEZEL] = BLOCK_STOP;


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
	if (player.pos.y == blockStartPos.y)
	{
		isGameOver = 1;
		TextColor(RED);
		ScreenPrint(gameMapPos.x + 5, gameMapPos.y + 10, "Game Over...");
		TextColor(RED);
		ScreenPrint(gameMapPos.x + 2, gameMapPos.y + 11, "Press R Key To Restart");
	}
}

void LineClearCheck(Player player)
{
	int cnt, lineCnt = 0;
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		cnt = 0;
		for (int j = 0; j < GAME_WIDTH; j++)
			if (gameMap[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + j] == BLOCK_STOP)
				++cnt;

		if (cnt == 10)
		{
			++lineCnt;
			for (int k = 1; k < GAME_HEIGHT; k++)
			{
				cnt = 0;
				for (int j = 0; j < GAME_WIDTH; j++)
					if (gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x  + j] == EMPTY)
						++cnt;

				if (cnt != 10)
				{
					for (int j = 0; j < GAME_WIDTH; j++)
						if (gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j] < FLOOR)
							gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] =
								gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j];
				}
				else
				{
					for (int j = 0; j < GAME_WIDTH; j++)
						gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] = EMPTY;
					break;
				}
			}
		}
	}

	score += lineCnt * lineCnt;
	lines += lineCnt;
}

void GameLogic(Player player)
{
	GameOverCheck(player);
	LineClearCheck(player);
}