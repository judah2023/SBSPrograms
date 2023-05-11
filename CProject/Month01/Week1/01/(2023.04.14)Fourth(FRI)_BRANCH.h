#include <stdio.h>

void main_230414()
{
#pragma region Overflow
	/*
	// 특정한 자료형이 표현할 수 있는
	// 최대값의 범위를 넘어서 수행하는 과정

	// char (1 BYTE, -128 ~ 127)
	char cOverflowData = 128;
	printf("data의 값 : %d\n", cOverflowData);
	*/
#pragma endregion

#pragma region Underflow
	/*
	// 특정한 자료형이 표현할 수 있는
	// 최소값의 범위를 넘어서 수행하는 과정

	unsigned char cUnderflowData = -129;
	printf("data의 값 : %d\n", cUnderflowData);
	*/
#pragma endregion

#pragma region RelationalOperator
	/*
	// 두 개의 피연산자의 값을 비교하여
	// 그 결과를 0 또는 1이라는 값으로 나타내는 연산자입니다.
	int A = 10, B = 5;
	char c;

	c = A < B;		// B가 A보다 클 때
	c = A > B;		// B가 A보다 작을 때
	c = A <= B;		// B가 A보다 크거나 같을 때
	c = A >= B;		// B가 A보다 작거나 같을 때
	c = A == B;		// B가 A보다 같을 때
	c = A != B;		// B가 A보다 다를 때

	printf("A < B	= %d\n", A < B);
	printf("A > B	= %d\n", A > B);
	printf("A <= B	= %d\n", A <= B);
	printf("A >= B	= %d\n", A >= B);
	printf("A == B	= %d\n", A == B);
	printf("A != B	= %d\n", A != B);
	*/
#pragma endregion

#pragma region Branch(if ~ else if ~ else)
	/*
	// 어떤 특정한 조건을 비교하여
	// 조건에 따라 분개되는 명령문

	if (5 == 1)
	{
		printf("5는 1과 같다.\n");
	}
	else if (5 < 1)
	{
		printf("5는 1과 작다.\n");
	}
	else
	{
		printf("5는 1보다 크다.\n");
	}

	if ('a' == 'b')
	{
		printf("if\n");
	}
	else if ('c' == 'd')
	{
		printf("else if\n");
	}
	else
	{
		printf("else\n");
	}
	*/

#pragma endregion

#pragma region LogicalOperator
	/*
	// &&	(AND)
	if ('a' == 'a' && 'a' == 'a')
	{
		printf("AND의 조건이 성립합니다.\n");
	}
	// ||	(OR)
	if ('a' == 'a' || 'a' == 'b')
	{
		printf("OR의 조건이 성립합니다.\n");
	}
	// !	(NOT)
	if (!'a')
	{
		printf("NOT의 조건이 성립합니다.\n");
	}
	*/
#pragma endregion

#pragma region Quadrant
	int x = 5, y = 5;

	if (y != 0 && x > 0)
	{
		if (y > 0)
		{
			printf("1사분면\n");
		}
		else
		{
			printf("4사분면\n");
		}
	}
	else if (y != 0 && x < 0)
	{

		if (y > 0)
		{
			printf("2사분면\n");
		}
		else
		{
			printf("3사분면\n");
		}
	}
	else
	{
		if (x != 0)
		{
			printf("x축\n");
		}
		else if (y != 0)
		{
			printf("y축\n");
		}
		else
		{
			printf("원점\n");
		}
	}
#pragma endregion
}
