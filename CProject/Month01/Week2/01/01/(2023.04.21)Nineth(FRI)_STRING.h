// 전처리기란?
// 프로그램이 컴파일되기 전에 사전 처리되는 과정

// #include 파일 처리 전처리 문
// 시스템 파일이나 사용자 정의 파일을 프로그램 소스에 삽입하기 위한 선언문
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGNUMBER	1000

#pragma region Macro
	// 프로그램 내에서 특정한 데이터가 정의되고 처리되는 과정

	// 전처리기에서 처리되므로 명령문 끝인
	// ";"를 사용하지 않는다
#define SIZE		5

	// 매크로는 변수 메모리 공간을 가지고 있지 않다.

#pragma endregion

void main()
{
#pragma region String

	/*

	// 연속적인 메모리 공간에 저장된
	// 문자 변수의 집합입니다.

	// 문자열의 경우 포인터를 이용하여
	// 문자열 상수를 가리킬수 있다.
	const char* name = "James";

	// %s : 문자열을 출력하는 서식
	printf("*name 변수의 값 : %s\n", name);
	printf("*name 의 주소 : %p\n\n", name);

	// 문자열 상수는 읽기 전용 데이터 공간에 저장되므로
	// 문자열을 값을 변경할 수 없다.
	// *name = 'G';		(X)
	// name[0] = 'G'	(X)

	name = "Tom";


	// 문자열은 맨 마지막에 널 문자가 자동으로 들어간다
	printf("*name 변수의 값 : %s\n", name);
	printf("*name 의 주소 : %p\n\n", name);

	// 배열을 이용한 문자열
	char string[] = "Game";

	// 문자열은 공백도 메모리 공간에 포함
	char string1[] = "App le";

	printf("string의 값 : %s\n", string);

	string[0] = 'B';
	string[3] = 'o';

	printf("string의 값 : %s\n", string);

	// char 배열은 포인터 상수
	// string = string1;
	// string = "Com";

	// 문자 배열 사이에 무효의 문자를 넣게 되면
	// 널문자까지만 문자열을 출력

	*/

#pragma endregion

#pragma region Max and Min
	/*

	// int 배열에서 최대값과 최소값을 각각 출력

	int arr[] = { 1,2,3,4,5 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	int nMax = arr[0];
	int nMin = arr[0];

	for (int i = 1; i < arrSize; i++)
	{
		if (nMax < arr[i])
		{
			nMax = arr[i];
		}

		if (nMin > arr[i])
		{
			nMin = arr[i];
		}
	}

	printf("배열 Arr의 최대값, 최소값 : %d, %d\n", nMax, nMin);

	int a0 = 1;
	int a1 = 1;

	int num;
	int tmp;

	printf("n ? : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		printf("%2d번째 피보나치 수 : %10d\n", i, a0);
		tmp = a1;
		a1 += a0;
		a0 = tmp;
	}

	int sifter[BIGNUMBER] = { 0 };

	int prime;

	sifter[0] = 1;

	for (int i = 3; i < BIGNUMBER; i += 2)
	{
		sifter[i] = 1;
	}

	for (int i = 2; i * i < BIGNUMBER; i += 2)
	{
		prime = i + 1;
		if (sifter[prime - 1] == 0)
		{
			for (int j = prime * 2; j <= BIGNUMBER; j += prime)
			{
				sifter[j - 1] = 1;
			}
		}

	}

	for (int i = 0; i < BIGNUMBER; i++)
	{
		if (sifter[i] == 0)
		{
			printf("Prime : %d\n", i + 1);
		}
	}

	*/

#pragma endregion


}
// 네트워크 ph2ton network, playfab