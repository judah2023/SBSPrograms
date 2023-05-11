#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>


void Function()
{
	printf("Function() 실행중...\n");
}

void DataList()
{
	printf("DataList() 실행중...\n");
}

int Damage(int x)
{
	return x;
}

void Sort(void (*fPtr)())
{
	fPtr();
}

#pragma region typedef

/*

typedef unsigned int UINT;

typedef struct Player
{
	int x;
	int y;
	char name[10];
}Player;

*/

#pragma endregion


int main()
{
#pragma region Function_Pointer

	/*

	// 함수의 주솟값을 저장하고 가리킬 수 있는 변수
	printf("Function()의 주솟값 : %p\n", Function);

	// type (*name)(parameters)		// 함수 포인터 선언 방법
	void (*fPtr) ();
	int (*newFPtr)(int);

	fPtr = Function;
	newFPtr = Damage;

	fPtr();

	// 함수 포인터는 함수의 반환형과 매개변수의 타입이 일치해야 하므로,
	// 함수 포인터를 사용하여 동적으로 메모리를 할당할 수 없다.
	// fPtr = Damage;
	// printf("fPtr의 값 : %d\n", fPtr(10));		// Error

	printf("newFPtr의 값 : %d\n", newFPtr(10));

	fPtr = DataList;
	fPtr();

	Sort(Function);

	*/

#pragma endregion

	return 0;
}
