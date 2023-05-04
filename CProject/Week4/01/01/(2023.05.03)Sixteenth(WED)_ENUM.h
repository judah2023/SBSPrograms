#pragma once

#include <stdio.h>

#pragma region Enum

/*

// 요소, 멤버라 불리는 명명된 값의 집합을 이루는 자료형

// enum 선언
enum Color
{
	// 열거형은 초기값을 설정할 수 있으며,
	// 그 다음 상수 값은 1씩 증가합니다.
	BLACK = 10,
	RED,
	BLUE
};

enum State
{
	IDLE,
	ATTACK,
	DIE
};

*/

#pragma endregion

int main()
{
#pragma region Multidimensional_Array

	/*

	// 배열의 요소로 또 다른 배열을 가지는 배열

	// 2차원 배열은 행과 열로 구분되며
	// 앞의 번호는 행의 갯수를 의미하고, 뒤의 번호는 열의 갯수를 의미한다.
	int array2D[4][3] =
	{
		{ 10,	 20,	 30 },
		{ 40,	 50,	 60 },
		{ 70,	 80,	 90 },
		{ 100,	 110,	 120 }
	};

	printf("array2D의 값		: %p\n", array2D);
	printf("array2D[0][0]의 주소	: %p\n", &array2D[0][0]);

	int* ptr = NULL;
	ptr = &array2D[0][0];

	// 배열 포인터
	// 특정 사이즈의 배열'만' 가리킬 수 있는 하나의 포인터
	int (*arrPtr)[3] = NULL;
	arrPtr = array2D;

	printf("ptr이 가리키는 값 : %d\n", *ptr);
	printf("arrPtr이 가리키는 값 : %d\n", (*arrPtr)[0]);

	*/

#pragma endregion

	return 0;
}