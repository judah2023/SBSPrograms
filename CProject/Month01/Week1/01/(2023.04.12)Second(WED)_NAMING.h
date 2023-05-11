#pragma once

#include <stdio.h>	// 기본 입출력 헤더 파일

void main_230412()			// 프로그램의 시작점, 프로그렘에 하나만 존재해야 한다.
{
#pragma region VariableRule
	// 1. 예약어를 사용할 수 없다.
	// int int = 100;			(X)
	//
	// 2. 숫자로 시작할 수 없다.
	// int hp1 = 100;			(O)
	// int 1hp = 100;			(X)
	//
	// 3. 대소문자를 구분한다.
	// int attack = 26;
	// int Attack = 27;
	// printf("%d %d", attack, Attack);		// OUTPUT : 26 27
	//
	// 4. 공백이 포함될 수 없다.
	// int count Down = 200;	(X)
	// int countDown = 200;	(O)
	// int count_down = 200;	(O)
	//
	// 5. 특수기호는 $, _ 만 사용가능하다.
	//int $any = 100;			(O)
	//int _any = 200;			(O)
#pragma endregion

#pragma region InitVariable
	// 최초로 변수에 값을 저장해주는 과정입니다.
	// unsigned int exp = 100;	// 변수의 선언

#pragma endregion

#pragma region Literal
	// 프로그램이 실행되는 동안 
	// 더 이상 값을 변경할 수 없는 메모리 공간
	// const int literalInt = 0;
	// const float pi = 3.141592f;
	// pi = 6.29184; 상수로 선언되었기 때문에 변경할 수 없습니다.

	// 심볼릭 상수 : 메모리 공간을 가지고 있는 상수
	// 리터럴 상수 : 메모리 공간을 가지고 있지 않은 상수
#pragma endregion
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