#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#pragma comment (lib,"winmm.lib")
#include <mmsystem.h>

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

enum ARROW_KEYS
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

// HANDLE 인덱스에 접근해서 버퍼를 교체시키는 변수
int screenIndex = 0;

// 버퍼의 크기
const int width = 100 * 2;
const int height = 60;

// 버퍼 생성 (2개)
HANDLE Screen[2];	// [0] front buffer
					// [1] back buffer

typedef struct _Player
{
	int x, y;
	const char* shape;
}Player;

// 버퍼 초기화 함수
void ScreenInit()
{
	CONSOLE_CURSOR_INFO cursor;

	// 버퍼의 가로 사이즈, 세로 사이즈
	COORD size = { width, height };

	// Left, Top, Right, Bottom
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

	// 화면 2개 생성

	// front buffer
	Screen[0] = CreateConsoleScreenBuffer(GENERIC_READ	  | GENERIC_WRITE,
										  FILE_SHARE_READ | FILE_SHARE_WRITE,
										  nullptr,
										  CONSOLE_TEXTMODE_BUFFER,
										  nullptr);
	SetConsoleScreenBufferSize(Screen[0], size);
	SetConsoleWindowInfo(Screen[0], true, &rect);

	// front buffer
	Screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
										  FILE_SHARE_READ | FILE_SHARE_WRITE,
										  nullptr,
										  CONSOLE_TEXTMODE_BUFFER,
										  nullptr);
	SetConsoleScreenBufferSize(Screen[1], size);
	SetConsoleWindowInfo(Screen[1], true, &rect);

	// 커서의 활성화 여부
	// false : 거짓
	// true  : 참
	cursor.dwSize = 1;
	cursor.bVisible = false;

	SetConsoleCursorInfo(Screen[0], &cursor);
	SetConsoleCursorInfo(Screen[1], &cursor);
}

// 버퍼를 교체하는 함수
void ScreenFlipping()
{
	// 버퍼는 하나만 활성화 가능
	SetConsoleActiveScreenBuffer(Screen[screenIndex]);
	screenIndex = !screenIndex;
}

// 교체된 버퍼를 지워주는 함수
void ScreenClear()
{
	COORD coord{ 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(Screen[screenIndex], 
							   L' ', 
							   width * height, 
							   coord, 
							   &dw);
}

// 버퍼를 해제하는 함수
void ScreenRelease()
{
	CloseHandle(Screen[0]);
	CloseHandle(Screen[1]);
}

// 더블 버퍼링을 이용해서 출력하는 함수
void ScreenPrint(int x, int y, const char* string)
{
	COORD cursorPosition = { x, y };
	DWORD dw;

	SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);
	WriteFile(Screen[screenIndex], 
			  string, 
			  strlen(string), 
			  &dw, 
			  nullptr);
}

// 플레이어 위치 이동 함수
void SetPlayerMove(Player* player, int diffX, int diffY)
{
	player->x += diffX * 2;
	player->y += diffY;

	if (player->x < 0)
	{
		player->x = 0;
	}
	else if (player->x > width - 2)
	{
		player->x = width - 2;
	}

	if (player->y < 0)
	{
		player->y = 0;
	}
	else if (player->y > height - 1)
	{
		player->y = height - 1;
	}
}

int main()
{
	// PlaySound(TEXT("Sound.wav"), nullptr, SND_ASYNC);				// 일반 재생
	PlaySound(TEXT("Sound.wav"), nullptr, SND_ASYNC | SND_LOOP);	// 반복 재생
	
	Player player = { 5 * 2, 5, "＠" };
	char key = 0;

	// 색상을 설정하는 함수
	// 0 = 검정
	// 1 = 블루
	// 2 = 초록
	// 3 = 옥색
	// 4 = 빨강
	// 5 = 자주
	// 6 = 노랑
	// 7 = 회색
	// 8 = 흰색
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);

	// 1. 버퍼 초기화
	ScreenInit();

	while (true)
	{
		ScreenPrint(player.x, player.y, player.shape);

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
				SetPlayerMove(&player, 0, -1);
				break;
			case LEFT:
				SetPlayerMove(&player, -1, 0);
				break;
			case RIGHT:
				SetPlayerMove(&player, 1, 0);
				break;
			case DOWN:
				SetPlayerMove(&player, 0, 1);
				break;
			default:
				break;
			}
			
		}

		// 2. 버퍼 교체
		ScreenFlipping();

		// 3. 교체된 버퍼 비우기
		ScreenClear();
	}

	// 종료 시, 버퍼를 해제
	ScreenRelease();
	return 0;
}
