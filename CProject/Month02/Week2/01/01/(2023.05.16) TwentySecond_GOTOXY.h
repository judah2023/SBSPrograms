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

// 좌표이동 함수
void GotoXY(int x, int y)
{
	COORD position = { x + x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{

#pragma region Coordinate_Movement

	/*

	int currX = 10, currY = 10;
	int prevX = 10, prevY = 10;

	while (1)
	{
		system("cls");
		GotoXY(currX, currY);
		printf("☆");

		prevX = currX;
		prevY = currX;

		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			currY--;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			currX--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			currX++;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			currY++;
		}

		if (currY < 0)
		{
			currY = 0;
		}
		if (currX < 0)
		{
			currX = 0;
		}

		Sleep(16);
	}

	char key;
	GotoXY(currX, currY);
	printf("☆");
	while (1)
	{
		if (_kbhit())
		{
			system("cls");

			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP:
				if (currY > 0)
				{
					currY--;
				}
				break;
			case LEFT:
				if (currX > 0)
				{
					currX--;
				}
				break;
			case RIGHT:
				if (currX < 25)
				{
					currX++;
				}
				break;
			case DOWN:
				if (currY < 25)
				{
					currY++;
				}
				break;
			default:
				break;
			}


			GotoXY(currX, currY);
			printf("☆");
		}
	}

	*/

#pragma endregion

#pragma region strlen()

	/*

	// 문자열의 크기를 반환하는 함수
	// 문자열의 끝인 NULL 문자를 포함하지 않는 크기가 나온다
	char* string = "Count";

	size_t strSize = strlen(string);

	printf("strSize : %llu\n", strSize);

	*/

#pragma endregion

#pragma region Palindrome

	/*

	char data[101] = { 0 };
	scanf_s("%s", data, 101);
	size_t size = strlen(data);

	char* newData = (char*)malloc(sizeof(char) * (size + 1));
	if (newData == NULL)
	{
		printf("ERROR : Failed to Create string!!!\n");
		return -1;
	}
	strcpy_s(newData, size + 1, data);

	for (int i = 0; i < size; i++)
	{
		if (newData[i] >= 'a' && newData[i] <= 'z')
		{
			newData[i] -= 'a' - 'A';
		}
	}

	int flag = 1;
	for (int i = 0; i < size / 2; i++)
	{
		if (newData[size - i -1] != newData[i])
		{
			flag = 0;
			break;
		}
	}

	if (flag == 1)
	{
		printf("회문\n");
	}
	else
	{
		printf("회문 아님\n");
	}

	free(newData);

	*/

#pragma endregion

	return 0;
}