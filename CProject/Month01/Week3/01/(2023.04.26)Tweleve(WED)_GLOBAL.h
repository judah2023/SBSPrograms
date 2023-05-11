#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SoundManager.h"

#pragma region Global

/*

	// 함수 외부에서 선언된 변수로 프로그램 어디에서나 접근 가능
	// 프로그램 종료시에만 메모리에서 해제

int  globalVar = 5;

void Function()
{
	int count = 0;
	globalVar += 1;
	count += 1;

	printf("count의 값 : %d\n", count);
	printf("globalVar의 값 : %d\n", globalVar);
}

*/

#pragma endregion

#pragma region Static

/*

static int attack;

	// 지역 변수와 전역 변수의 특징을 가지고 있다.
	// BSS : 초기화하지 않은 전역, 정적 변수가 있는 공간
	// 프로그램 크기에 포함되지 않는다.

void Calculator()
{
	static int value = 1;
	value += 1;

	printf("static 변수value의 값 : %d\n", value);
}

*/

#pragma endregion

#pragma region Divisor_Function

/*

void PrintDivisor(int x)
{
	printf("%d의 약수 : ", x);
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
		{
			printf("%d, ", i);
		}
	}
	printf("%d\n", x);
}

int IsPrime(int x)
{
	if (x % 2 == 0)
	{
		if (x == 2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

*/

#pragma endregion

void main()
{
#pragma region Local

	/*

	// A 지역
	int data = 100;

	{	// B 지역
		int data = 20;
		printf("B 지역 data의 값 : %d\n", data);
	}
	printf("A 지역 data의 값 : %d\n", data);

	*/

#pragma endregion

#pragma region Void_Pointer

	/*

	// 자료형이 정해지지 않은 상태로
	// 모든 자료형을 저장 할 수 있는 포인터

	char cData = 'X';
	int nData = 10;

	// 범용 포인터는 메모리 주소에 접근해서
	// 값을 변경할 수 없다
	void* vPtr = NULL;

	vPtr = &cData;
	printf("%c\n", *(char*)vPtr);

	// 범용 포인터로 변수의 메모리에 접근하려면
	// 범용 포인터가 참조하는 변수의 자료형으로
	// 형 변환 해주어야 한다
	*(char*)vPtr = 'D';
	printf("%c\n\n", *(char*)vPtr);


	vPtr = &nData;
	printf("%d\n", *(int*)vPtr);

	*(int*)vPtr = 100;
	printf("%d\n\n", *(int*)vPtr);

	*/

#pragma endregion

#pragma region Divisor

	/*

	// 문제) 내가 입력한 숫자의 약수를 출력하세요.
	// 12 -> 1, 2, 3, 4, 6, 12

	int x = 0;
	printf("자연수를 입력해주세요 : ");
	scanf_s("%d", &x);

	PrintDivisor(x);

	printf("%d의 소인수 분해 결과 : ", x);
	for (int i = 2; x != 1; i += 2)
	{
		int baseCount = 0;

		while (IsPrime(i) && x % i == 0)
		{
			baseCount++;
			x /= i;
		}

		if (baseCount > 0)
		{
			printf("%d^%d ", i, baseCount);
		}

		if (i == 2)
		{
			i--;
		}
	}

	*/

#pragma endregion

#pragma region Short_Circuit

	/*

	// 논리 연산에서 두 피연산자 중 어는 한쪽만 '참'이면
	// 우측의 피연산자의 값은 평가하지 않고 바로 결과를 얻는 행위

	// &&, ||	(논리 연산자)
	// &, |		(비트 연산자)

	int x = 0;
	int y = 1;

	if (x == -1 && ++y == 2) {}

	printf("x의 값 : %d, y의 값 : %d\n", x, y);

	if (x == 0 || ++y == 2) {}

	printf("x의 값 : %d, y의 값 : %d\n", x, y);

	*/


#pragma endregion

}