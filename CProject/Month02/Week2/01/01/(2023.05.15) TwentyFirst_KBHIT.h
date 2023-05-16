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

	// ���� : A�۾��� �ϴ� �߿��� �ٸ� �۾��� �Ұ���
	// �񵿱� : A�۾��� ���� �߿� �ٸ� �۾��� ����

	char key = 0;
	while (1)
	{
		if (_kbhit())	// Ű���� �Է��� Ȯ���ϴ� �Լ�
		{

			key = _getch();	// ����Ű �Է� �� 224 00�� ������ �ǹǷ� ���� �� 224�� ����
			if (key == -32)
			{
				key = _getch();
			}

			// 224 72 : 11011111 01001000
			// ��ĵ �ڵ�
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

			printf("�ٸ� �۾� ��...\n");
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