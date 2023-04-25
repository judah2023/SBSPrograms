#ifndef WEEK03_H
#define WEEK03_H

#include <stdio.h>
#include <stdlib.h>

#define ADD(x,y)		(x + y)
#define SWAP(T, x, y)	{T temp = x; x = y; y = temp;}

#pragma region Function

/*

// ï¿½Ï³ï¿½ï¿½ï¿½ Æ¯ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Û¾ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï±ï¿½ ï¿½ï¿½ï¿½ï¿½
// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿?ï¿½Úµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½

// void : ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½È¯ï¿½ï¿½ï¿½ï¿½ ï¿½Ê´ï¿½ ï¿½Ú·ï¿½ï¿½ï¿½ ( 0ï¿½ï¿½ï¿½ï¿½Æ®ï¿½ï¿½ ï¿½Ø¼ï¿½ï¿½Ï´ï¿½ ï¿½Ú·ï¿½ï¿½ï¿½)
void Attack()
{
	for (int i = 0; i < 9; i++)
	{
		if (i < 9 && i % 4 == 0)
		{
			printf(" ï¿½ï¿½ï¿½ï¿½");
		}
		else
		{
			printf(" !!!!");
		}

		if (i % 3 == 2)
		{
			printf("\n");
		}
	}
	printf("\n");
}

// ï¿½ï¿½È¯ï¿½ï¿½ : ï¿½Ô¼ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Ç¾ï¿½ï¿½ï¿?ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½È¯ï¿½ï¿½ï¿½Ö´ï¿½ ï¿½ï¿½ï¿½ï¿½
int Function()
{
	return 100;
}

// ï¿½Ô¼ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿?ï¿½Ú·ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½È¯ï¿½Ï´ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Â°ï¿½ ï¿½ï¿½Ä¡ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½.
int ProcessInt()
{
	return 67.5f;
}

// Cï¿½ï¿½î¿¡ï¿½ï¿? ï¿½Ô¼ï¿½ ï¿½Ì¸ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½. (ï¿½ßºï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ò°ï¿½ï¿½ï¿½)

*/

#pragma endregion

#pragma region Parameter

/*

// ï¿½Ô¼ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ç¿ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Þ¹ï¿½ï¿½ï¿½ ï¿½Î¼ï¿½ï¿½ï¿½
// ï¿½Ô¼ï¿½ ï¿½ï¿½ï¿½Î·ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï±ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Ï´ï¿?ï¿½ï¿½ï¿½ï¿½

void Calculator(int x)
{
	printf("ï¿½Å°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ : %d\n", x);
}

int Add(int x, int y)
{
	return x + y;
}

*/

#pragma endregion

// ÂüÁ¶¿¡ ÀÇÇÑ Àü´Þ (ÇÔ¼ö)
void SwapReference(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// °ª¿¡ ÀÇÇÑ Àü´Þ (ÇÔ¼ö)
void Swap(int x, int y)
{
	printf("ÁÖ¼Ò °ª : [&x, &y] = [%p, %p]\n", &x, &y);
	printf("¿ø·¡ °ª : [x, y] = [%d, %d]\n", x, y);

	int temp;
	temp = x;
	x = y;
	y = temp;

	printf("°á°ú °ª : [x, y] = [%d, %d]\n\n", x, y);

}

void main()
{
#pragma region Call_Function(None Parameter)

	/*
	//Attack();
	//Attack();

	printf("Function() : %d\n\n", Function());
	printf("ProcessFloat() : %d\n\n", ProcessInt());
	*/

#pragma endregion

#pragma region Call_Function(Using Parameter)

	/*

	// ï¿½Î¼ï¿½(Arguement)?
	// ï¿½Ô¼ï¿½ï¿½ï¿½ È£ï¿½ï¿½ï¿?ï¿½ï¿½ ï¿½Å°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ÞµÇ´ï¿½ ï¿½ï¿½
	Calculator(100);

	// ï¿½Î¼ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ê¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Å°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Þµï¿½
	printf("Add() ï¿½Ô¼ï¿½ï¿½ï¿½ ï¿½ï¿½ : %d\n", Add(10, 20));
	// printf("ADD() ï¿½Ô¼ï¿½ï¿½ï¿½ ï¿½ï¿½ : %d\n", ADD(10, 20));

	*/

#pragma endregion

#pragma region Call_by_Value_And_Call_by_Reference

	/*

	printf("¿ø·¡ °ª : [a, b] = [%d, %d]\n\n", a, b);

	// Call by value
	Swap(a, b);

	printf("°á°ú °ª : [a, b] = [%d, %d]\n\n", a, b);

	printf("\n\n\n");

	int a = 100;
	int b = 200;

	printf("¿ø·¡ °ª : [a, b] = [%d, %d]\n\n", a, b);

	// Call by Reference
	// ÇÔ¼ö¸¦ È£ÃâÇÒ ¶§ º¯¼öÀÇ ÁÖ¼Ò¸¦ ÀÎ¼ö·Î Àü´ÞÇÏ°Ô µÇ¸é
	// Àü´ÞÇÑ º¯¼öÀÇ ÁÖ¼Ò°¡ ÂüÁ¶µÇ¾î ÀÎ¼ö·Î Àü´ÞÇÑ °ªÀÌ
	// ÇÔ¼ö ³»¿¡¼­ ÀÏ¾î³­ ¿¬»ê¿¡ ´ëÇØ ¿µÇâÀ» ¹Þ´Â´Ù.
	SwapReference(&a, &b);

	printf("°á°ú °ª : [a, b] = [%d, %d]\n\n", a, b);

	*/

#pragma endregion

}

#endif // !WEEK3_H


