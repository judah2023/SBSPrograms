#include "Main.h"

#include "DoubleBuffering.h"

#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>

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
char gameMap[HEIGTH][WIDTH + 1];
int  gameMapColor[HEIGTH][WIDTH];

char scoreString[21], stringBuffer[50];

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
Pos holdMapPos = { 1, 1 }, gameMapPos = { 6, 1 }, nextMapPos = { 17, 1 }, 
	scorePos = { 22, 1 }, blockStartPos = { 4, 0 }, levelPos = { 1, 6 };

clock_t prevClock, currClock, dropDelay = 1;
time_t startTime;

unsigned bestScore, score, lines, level;
bool isGameOver;

std::queue<Player> nextTetris;
Tetris holdTetris;

int main()
{
	// 게임 초기화
	GameInit();

	Player player = CreateNewTetris();

	clock_t dropTimer = 0;

	while (true)
	{
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

		if (isGameOver)
			Keyboard(player);
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

COLORS GetTetrisColor(Player player)
{
	int bType = player.status.bType;
	switch (bType)
	{
	case 0:
		return DARK_BLUE;
	case 1:
		return DARK_YELLOW;
	case 2:
		return GREEN;
	case 3:
		return DARK_RED;
	case 4:
		return DARK_PURPLE;
	case 5:
		return DARK_SKY_BLUE;
	case 6:
		return YELLOW;
	default:
		break;
	}
}

void LoadBestScore(const char* dataFileName)
{
	FILE* file;
	fopen_s(&file, dataFileName, "r");
	if (file == nullptr)
	{
		MakeBestScore(dataFileName);
		fopen_s(&file, dataFileName, "r");
		if (file == nullptr)
			return;
	}

	fscanf_s(file, "%d", &bestScore);

	fclose(file);
}

void MakeBestScore(const char* dataFileName)
{
	FILE* file;
	fopen_s(&file, dataFileName, "w");
	if (file == nullptr)
		return;

	fprintf_s(file, "%d", bestScore);

	fclose(file);

}

void GameInit()
{
	ScreenInit();
	srand((unsigned)time(NULL));

	bestScore = score = lines = isGameOver = 0;
	level = 1;
	LoadBestScore("BestScore\\data.txt");

	for (int i = 0; i < HEIGTH; i++)
	{
		strcpy_s(gameMap[i], "33333333333333333333333333333333333333");
		for (int j = 0; j < WIDTH; j++)
			gameMapColor[i][j] = SKY_BLUE;
	}

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			gameMap[holdMapPos.x + i][holdMapPos.y + j] = EMPTY;
			gameMapColor[holdMapPos.x + i][holdMapPos.y + j] = BLACK;
		}
	}

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			gameMap[gameMapPos.y + i][gameMapPos.x + j] = EMPTY;
			gameMapColor[gameMapPos.y + i][gameMapPos.x + j] = BLACK;
		}
	}

	for (int i = 0; i < SCORE_HEIGHT; i++)
	{
		for (int j = 0; j < SCORE_WIDTH; j++)
		{
			gameMap[scorePos.y + i][scorePos.x + j] = EMPTY;
			gameMapColor[scorePos.y + i][scorePos.x + j] = BLACK;
		}
	}

	for (int n = 0; n < NEXT_MAX; n++)
	{
		Player newTetris = CreateNewTetris();
		nextTetris.push(newTetris);
		int color = GetTetrisColor(newTetris);

		for (int i = 0; i < TETRIS_DRAW; i++)
		{
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				gameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j] = tetrominos[newTetris.status.bType][newTetris.status.bRotate][i][j];
				gameMapColor[nextMapPos.y + 4 * n + i][nextMapPos.x + j] = color;
			}
		}
	}

	holdTetris = { -1, 0 };

	startTime = time(NULL);
	currClock = clock();
	PlaySound(TEXT("Sound\\tetrismusic.wav"), nullptr, SND_ASYNC | SND_LOOP);	// 반복 재생
}

void GamePrint(Player player)
{

	UpdataGameMap();
	UpdataPlayer(player);
	UpdateText();
}

void UpdataGameMap()
{
	char cell;
	int color;
	for (int i = 0; i < HEIGTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			cell = gameMap[i][j];
			color = gameMapColor[i][j];

			TextColor(color);
			switch (cell)
			{
			case EMPTY:
				ScreenPrint(j + BEZEL, i + BEZEL, " ");
				break;
			case BLOCK_STOP:
			case BLOCK_MOVE:
				ScreenPrint(j + BEZEL, i + BEZEL, "▣");
				break;
			case FLOOR:
			case WALL:
				ScreenPrint(j + BEZEL, i + BEZEL, "■");
				break;
			default:
				break;
			}
		}
	}
}

void UpdataPlayer(Player player)
{
	int color = GetTetrisColor(player);
	TextColor(color);
	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (tetrominos[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
			{
				ScreenPrint(gameMapPos.x + player.pos.x + j, gameMapPos.y + player.pos.y + i, "▣");
			}
		}
	}
}

void UpdateText()
{
	TextColor(WHITE);

	sprintf_s(scoreString, "%02d", level);
	strcpy_s(stringBuffer, "Level ");
	strcat_s(stringBuffer, scoreString);
	ScreenPrint(levelPos.x + BEZEL, levelPos.y + BEZEL, stringBuffer);

	sprintf_s(scoreString, "%04d", bestScore);
	strcpy_s(stringBuffer, " Best Score : ");
	strcat_s(stringBuffer, scoreString);
	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL, stringBuffer);

	sprintf_s(scoreString, "%04d", score);
	strcpy_s(stringBuffer, " Score\t  : ");
	strcat_s(stringBuffer, scoreString);
	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL + 1, stringBuffer);

	sprintf_s(scoreString, "%04d", lines);
	strcpy_s(stringBuffer, " Line\t  : ");
	strcat_s(stringBuffer, scoreString);
	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL + 2, stringBuffer);

	time_t currTime = time(NULL);
	time_t timer = currTime - startTime;

	strcpy_s(stringBuffer, " Time : ");

	sprintf_s(scoreString, " %02llu", timer / 3600);
	strcat_s(stringBuffer, scoreString);
	strcat_s(stringBuffer, " : ");

	timer %= 3600;
	sprintf_s(scoreString, "%02llu", timer / 60);
	strcat_s(stringBuffer, scoreString);
	strcat_s(stringBuffer, " : ");

	timer %= 60;
	sprintf_s(scoreString, "%02llu", timer);
	strcat_s(stringBuffer, scoreString);

	ScreenPrint(scorePos.x + BEZEL, scorePos.y + BEZEL + 4, stringBuffer);
}

void UpdateNextTetris()
{
	for (int n = 1; n < NEXT_MAX; n++)
		for (int i = 0; i < TETRIS_DRAW; i++)
			for (int j = 0; j < TETRIS_DRAW; j++)
			{
				gameMap[nextMapPos.y + 4 * (n - 1) + i][nextMapPos.x + j] = gameMap[nextMapPos.y + 4 * n + i][nextMapPos.x + j];
				gameMapColor[nextMapPos.y + 4 * (n - 1) + i][nextMapPos.x + j] = gameMapColor[nextMapPos.y + 4 * n + i][nextMapPos.x + j];

			}

	nextTetris.pop();
	Player newTetris = CreateNewTetris();
	nextTetris.push(newTetris);
	int color = GetTetrisColor(newTetris);
	for (int i = 0; i < TETRIS_DRAW; i++)
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			gameMap[nextMapPos.y + 4 * (NEXT_MAX - 1) + i][nextMapPos.x + j] = tetrominos[newTetris.status.bType][newTetris.status.bRotate][i][j];
			gameMapColor[nextMapPos.y + 4 * (NEXT_MAX - 1) + i][nextMapPos.x + j] = color;
		}
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
			case KEY_Z:
			case KEY_z:
				HoldTetris(player);
				break;
			default:
				break;
			}
		}
		else
		{
			switch (key)
			{
			case KEY_R:
			case KEY_r:
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

	if (dropTimer * level >= dropDelay * 1000)
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

void HoldTetris(Player& player)
{
	int color = GetTetrisColor(player);
	if (holdTetris.bType == -1)
	{
		holdTetris = player.status;
		UpdateTetris(player);
	}
	else
	{
		Tetris tempStatus = holdTetris;
		holdTetris = player.status;
		player = { blockStartPos,tempStatus };
	}
	holdTetris.bRotate = 0;

	for (int i = 0; i < TETRIS_DRAW; i++)
	{
		for (int j = 0; j < TETRIS_DRAW; j++)
		{
			if (tetrominos[holdTetris.bType][holdTetris.bRotate][i][j] == BLOCK_MOVE)
			{
				gameMap[holdMapPos.x + i][holdMapPos.y + j] = BLOCK_STOP;
				gameMapColor[holdMapPos.x + i][holdMapPos.y + j] = color;
			}
			else
			{
				gameMap[holdMapPos.x + i][holdMapPos.y + j] = EMPTY;
				gameMapColor[holdMapPos.x + i][holdMapPos.y + j] = BLACK;
			}
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
	int color = GetTetrisColor(player);
	for (int i = 0; i < TETRIS_DRAW; i++)
		for (int j = 0; j < TETRIS_DRAW; j++)
			if (tetrominos[player.status.bType][player.status.bRotate][i][j] == BLOCK_MOVE)
			{
				gameMap[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + player.pos.x + j - BEZEL] = BLOCK_STOP;
				gameMapColor[gameMapPos.y + player.pos.y + i - BEZEL][gameMapPos.x + player.pos.x + j - BEZEL] = color;

			}


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
		MakeBestScore("BestScore\\data.txt");
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
						{
							gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] =
								gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j];
							gameMapColor[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] =
								gameMapColor[gameMapPos.y + player.pos.y + i - k - BEZEL][gameMapPos.x + j];

						}
				}
				else
				{
					for (int j = 0; j < GAME_WIDTH; j++)
					{
						gameMap[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] = EMPTY;
						gameMapColor[gameMapPos.y + player.pos.y + i - k - BEZEL + 1][gameMapPos.x + j] = BLACK;
					}
					break;
				}
			}
		}
	}

	score += lineCnt * lineCnt;
	lines += lineCnt;
	if (bestScore < score)
		bestScore = score;

	level = lines / 10 + 1;
}

void GameLogic(Player player)
{
	GameOverCheck(player);
	LineClearCheck(player);
}