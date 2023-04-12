#include <stdio.h>	// 기본 입출력 헤더 파일

void main()			// 프로그램의 시작점, 프로그렘에 하나만 존재해야 한다.
{
#pragma region Operator
	int result = (1 == 2) ? 10 - 25 : 10 + 25;

	// 1. num1 변수 = B 변수 + C 변수
	// 2. num2 변수 = E 변수 - F 상수
	// 3. num3 변수 = 리터럴 * B 변수
	// 4. num4 변수 = 리터럴 / F 상수
	// 5. num5 변수 = 리터럴 + 리터럴

	int num1, num2, num3, num4, num5;
	int B = 10, C = 20, E = 30;
	const int F = 40;
	
	num1 = B + C;
	num2 = E - F;
	num3 = 50 * B;
	num4 = 60 / F;
	num5 = 70 + 80;
#pragma endregion
	printf("%d\n", result);
}