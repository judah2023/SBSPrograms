#pragma once

#include <time.h>
#include "FrameWork/LoadManager.h"

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

enum ARROWS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

enum CONSTANTS
{
	SPACING = 5,
};

struct Select
{
	int x, y;
	const char* shape;
};

clock_t prevTime = 0, currTime = 0;

// 좌표 이동 함수
void GotoXY(const int x, const int y);
void TextColor(const int clolrCode);
void TimePass();
clock_t DeltaTime();

void Typing(const char* content, unsigned int speed);
void Keyboard(Select* selectPtr);

int main()
{
	// 파일 읽기
	// ReadTextFile("Resources/Scenario/test.txt");

	int stage = 0;

	Select selects = { 5, 30, "→" };

	while (true)
	{
		Keyboard(&selects);
		GotoXY(selects.x, selects.y);
		printf("%s", selects.shape);
		switch (stage)
		{
		case 1:	Typing("Resources/Scenario/test.txt", 1);
			break;
		default:
			break;
		}
		system("cls");
	}

	return 0;
}

void GotoXY(const int x, const int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void TextColor(const int colorCode)
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

void Typing(const char* content, unsigned int speed)
{
	if (speed > 1000)
		speed = 1000;
	else if (speed < 0)
		speed = 0;

	ReadTextFile(speed, content);
}

void Keyboard(Select* selectPtr)
{
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
			if (selectPtr->y < 5)
			{
			}
			else
			{
				selectPtr->y -= SPACING;
			}
			break;
		case DOWN:	selectPtr->y += SPACING;
			break;
		default:
			break;
		}
	}
}
