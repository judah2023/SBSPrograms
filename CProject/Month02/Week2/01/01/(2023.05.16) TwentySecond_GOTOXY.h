#pragma once


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


	return 0;
}