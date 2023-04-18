#include <stdio.h>
#include <stdlib.h>

void main()
{
#pragma region Iteration_while
	/*
	// 특정 조건을 거짓이 될 때까지 계속해서
	// 주어진 명령문을 실행하는 반복문

	int count = 5;

	while (count) // <- 조건
	{
		count--;
		printf("%04d번째 게임 실행...\n", 5 - count);

	}

	*/

#pragma endregion

#pragma region Continue
	/*
	// 해당 조건문만 실행하지 않고,
	// 반복문은 이어서 실행하는 제어문

	for (int i = 1; i <= 5; i++)
	{
		if (i == 3)
		{
			continue;
		}
		printf("%d ", i);
	}

	*/
#pragma endregion

#pragma region Casting
	/*
	// 서로 다른 자료형을 가지고 있는 변수끼리 연산이 이루어질 때
	// 기존에 지정했던 자료형을 다른 자료형으로 변환하는 과정

	// 암묵적 형 변환
	// 서로 다른 자료형으로 연산이 이루어질 때
	// 자료형의 크기가 큰 자료형으로 변환되는 과정
	int nInteger = 10;
	float fDencimal = 2.5f;

	// double > float > int > short > char
	float result = nInteger + fDencimal;
	printf("result의 값 : %f\n", result);

	// 명시적 형 변환
	// 연산이 이루어지기 전에 사용자가 직접 자료형을 변환하는 과정

	// float 메모리 [2.5f] = 5/2	(X)
	// float 메모리 [2.0f] = 5/2	(O)
	// 프로그래밍에서 정수와 정수끼리의 연산은 정수만 나오게 된다
	int a = 5;
	int b = 2;

	float result1 = (float)a / b;
	printf("result1의 값 : %f\n", result1);

	*/

#pragma endregion

#pragma region AddressOperator
	/*
	// 변수의 주소 값을 반환하는 연산자
	// 변수의 주소는 변수의 시작 주소
	int data = 314;

	// %p : 데이터의 주소를 출력하는 서식 지정자
	// x64 : 64 비트 (포인터 : 8 BYTE)
	// x86 : 32 비트 (포인터 : 4 BYTE)

	// 변수의 주소는 프로그램을 실행할때마다 달라진다
	printf("data 변수의 주소 : %p\n", &data);

	*/
#pragma endregion

#pragma region Pointer
	/*
	// 메모리의 주소 값을 저장할 수 있는 변수
	int box = 100;
	int box1 = 999;

	// ptr [box의 주소] <- box의 주소
	int *ptr = &box;

	// 포인터 변수도 자신의 메모리 공간을 가지고 있으며.
	// 포인터 변수에 변수의 주소를 저장하게 되면
	// 해당 변수의 시작 주소를 가리키게 된다.
	printf("ptr 변수의 값		: %p\n", ptr);
	printf("ptr 변수의 주소 값	: %p\n", &ptr);
	printf("box 변수의 주소 값	: %p\n\n", &box);

	printf("box 변수의 값(변경 전)	: %d\n", box);

	*ptr = 600;

	printf("box 변수의 값(변경 후)	: %d\n\n", box);

	// ptr [box1의 주소] <- box1의 주소
	ptr = &box1;
	*ptr = -999;

	printf("box 변수의 값		: %d\n", box);
	printf("box1 변수의 값		: %d\n\n", box1);

	double health = 10.5;

	int* ptr1 = &health;
	printf("ptr1 변수의 값		: %p\n", ptr1);

	// 포인터 변수를 저장하기 위해 주소 값을 저장할
	// 변수의 자료형과 포인터 변수의 자료형이 일치해야 한다.
	*ptr1 = 66.75;
	printf("ptr1 변수가 가리키는 값	: %d\n", *ptr1);
	printf("ptr1 변수가 가리키는 값	: %lf\n", health);

	*/

#pragma endregion


}

// 네트워크 photon network, playfab