#pragma once

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

enum ARROW_KEYS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

void gotoxy(int x, int y)
{
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

int main()
{
#pragma region _kbhit()

	/*

	// 동기 : A작업을 하는 중에는 다른 작업이 불가능
	// 비동기 : A작업이 쉬는 중에 다른 작업이 가능

	char key = 0;
	while (1)
	{
		if (_kbhit())	// 키보드 입력을 확인하는 함수
		{

			key = _getch();	// 방향키 입력 시 224 00이 들어오게 되므로 앞의 값 224를 삭제
			if (key == -32)
			{
				key = _getch();
			}

			// 224 72 : 11011111 01001000
			// 스캔 코드
			// UP		== 72
			// LEFT		== 75
			// RIGHT	== 77
			// DOWN		== 80
			switch (key)
			{
			case UP :
				printf("UP\n");
				break;
			case LEFT :
				printf("LEFT\n");
				break;
			case RIGHT :
				printf("RIGHT\n");
				break;
			case DOWN :
				printf("DOWN\n");
				break;
			default :
				printf("ERROR!\n");
				break;
			}

			printf("다른 작업 중...\n");
		}
	}

	*/

#pragma endregion

#pragma region GetAsyncKeyState()

	/*

	int x = 0;
	int y = 0;

	while (1)
	{
		gotoxy(x, y);
		printf("@");
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			y--;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			x--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x++;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y++;
		}

		if (y < 0)
		{
			y = 0;
		}

		if (x < 0)
		{
			x = 0;
		}

		system("cls");
	}

	*/

#pragma endregion

	return 0;
}