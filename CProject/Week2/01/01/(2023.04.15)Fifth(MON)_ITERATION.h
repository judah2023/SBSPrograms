#pragma once

#include <stdio.h>

void main()
{
#pragma region Switch
	/*
	// switch문
	// 어떤 결과에 따라 그 결과부터 실행되는 명령문
	// 조건에 해당하는 값에 따라 조건의 위치로 이동

	int count = 0;

	switch (count)	// <- 값
	{
		// break
		// 특정한 지점에서 분기를 탈출하는 제어문

	case 0: printf("0 입니다.\n");
		break;
	case 1: printf("1 입니다.\n");
		break;
	case 2: printf("2 입니다.\n");
		break;
	default: printf("ERROR : Out of count!!\n");
		break;
	}
	*/
#pragma endregion

#pragma region IncrementOperator
	/*
	// 피면산자를 하나씩 증가시키거나 감소시킬 경우 사용하는 연산자

	// 전위 증감 연산자
	// 변수의 값을 증감시킨 후에 연산을 수행
	int a = 0;
	int result1 = 0;

	// 증가
	result1 = ++a;
	printf("result1, a = %d, %d\n", result1, a);	// 1, 1
	// 감소
	result1 = --a;
	printf("result1, a = %d, %d\n", result1, a);	// 0, 0

	// 후위 증감 연산자
	// 변수의 값을 연산을 실행한 후에 증감을 수행
	int b = 0;
	int result2 = 0;

	// 증가
	result2 = b++;
	printf("result1, b = %d, %d\n", result2, b);	// 0, 1
	// 감소
	result2 = b--;
	printf("result1, b = %d, %d\n", result2, b);	// 1, 0
	*/
#pragma endregion

}

// 네트워크 photon network, playfab