#pragma once

#include <stdio.h>
#include <math.h>

enum State
{
	IDLE,
	BE_ATTACK,
	DIE
};

struct Player
{
	int		x, y;	// Position

	int		hp;
	float	attack;
	enum State state;
};

struct Enemy
{
	int		x, y;	// Position

	int		hp;
	float	attack;
	enum State state;
};

int main()
{
#pragma region Structure_Pointer

	/*

	struct Player player = { 1, 0.1f };
	struct Player *ptrPlayer = NULL;

	ptrPlayer = &player;

	(*ptrPlayer).hp = 100;
	(*ptrPlayer).attack = 12.5f;

	printf("%d\n", (*ptrPlayer).hp);
	printf("%.2f\n\n", (*ptrPlayer).attack);

	ptrPlayer->hp = 250;
	ptrPlayer->attack = 22.75f;

	printf("%d\n", ptrPlayer->hp);
	printf("%.2f\n\n", ptrPlayer->attack);

	*/

#pragma endregion

#pragma region Distance

	/*

	// 제곱근 (sqrt)
	printf("sprt(49) : %lf\n", sqrt(49));

	// 거듭제곱
	printf("2^3 : %lf\n", pow(2, 3));

	int a_0 = 1;
	int d = 2;

	int n = 0;

	printf("d, n : ");
	scanf_s("%d %d", &d, &n);

	for (int i = 0; i <= n; i++)
	{
		printf("a_%d = %d\n", i, a_0 + i * d);
	}

	struct Player player1;
	player1.x = 0;
	player1.y = 0;

	struct Enemy emeny1;
	emeny1.x = 5;
	emeny1.y = 7;

	int xDistance = emeny1.x - player1.x;
	int yDistance = emeny1.y - player1.y;

	float distance = sqrt(xDistance * xDistance + yDistance * yDistance);

	if (distance >= 5.0f)
	{
		printf("주변에 적이 없습니다.\n");
	}
	else
	{
		printf("근처에 적이 있습니다!\n");
		printf("distance : %lf\n", distance);
	}

	*/

#pragma endregion

#pragma region Rounding_Error

	/*

	// 부동 소수점
	// 소수점의 위치를 고정하지 않고 소수를 나타내는 방법

	// 고정 소수점
	// 소수점의 위치를 고정하여 소수를 나타내는 방법

	// 12.375

	// float (4Byte)
	float fData = 12.3f;
	printf("fData = %.20f\n", fData);

	// double (8Byte)
	double dData = 1.3123;
	printf("dData = %.20lf\n\n", dData);

	if (fData == 12.3e-0)
	{
		printf("Equal\n");
	}
	else
	{
		printf("Not Equal\n");
	}

	*/

#pragma endregion


	return 0;
}