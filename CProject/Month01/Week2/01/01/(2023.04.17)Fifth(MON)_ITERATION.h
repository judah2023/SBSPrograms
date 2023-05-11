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

#pragma region Increment Operator
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

#pragma region iteration_For
	/*
	// 초기식을 연산하여 조건식의 결과에 따라
	// 특정한 횟수만큼 반복하는 반복문

	// for문의 경우 조건이 끝나는 형태와 반대로 초기식을 연산하게 되면
	// 조건이 일치하지 않아 계속 반복적으로 실행되는 문제 발생

	for (int i = 0; i < 10; i++)
	{
		printf("Case %d : 게임 중...\n", i);
	}

	// 문제
	// 반복문으로 초기값 1 ~ 5의 값을 출력
	for (int i = 0; i < 5; i++)
	{
		printf("%04d\t", i + 1);
	}

	// 문제2
	// 1 ~ 10까지의 합을 구해서 출력
	int nTotal = 0;

	for (int j = 1; j <= 10; j++)
	{
		nTotal += j;
	}
	printf("Solution : %d\n", nTotal);

	// 2중 for문
	// for문 안에 for문이 들어있는 중첩형태
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("안쪽에 있는 for문\n");
		}
		printf("바깥에 있는 for문\n");
	}

	*/

#pragma endregion


}

// 네트워크 photon network, playfab