#include "Main.h"

int main()
{
	// 버퍼 초기화
	ScreenInit();

	Pos player = { 0, 0 };

	while (true)
	{
		ScreenPrint(player.x, player.y, "＠");

		Keyboard(&player);

		// 버퍼 교체
		ScreenFlipping();

		// 교체된 버퍼 비우기
		ScreenClear();
	}

	// 종료 시, 버퍼를 해제
	ScreenRelease();
	return 0;
}

void Keyboard(Pos* ptrPlayer)
{
	char key = 0;
	if (_kbhit())
	{
		key = _getch();
		if (key == -32)
			key = _getch();

		switch (key)
		{
		case UP:
			if (ptrPlayer->y > 0)
			{
				ptrPlayer->y--;
			}
			break;
		case LEFT:
			if (ptrPlayer->x > 0)
			{
				ptrPlayer->x--;
			}
			break;
		case RIGHT:
			if (ptrPlayer->x < 100)
			{
				ptrPlayer->x++;
			}
			break;
		case DOWN:
			if (ptrPlayer->y < 100)
			{
				ptrPlayer->y++;
			}
			break;
		default:
			break;
		}
	}
}