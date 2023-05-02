#include <stdio.h>

int main()
{

#pragma region Pointer_Array

	/*

	const char* string[3];

	//	8BYTE	8BYTE	8BYTE
	//	  0		  1		  2
	//	['F']	['S']	['T']
	// 각 배열에는 참조하는 자료의 시작주소를 저장하고 있다.

	string[0] = "First";
	string[1] = "Second";
	string[2] = "Third";

	for (int i = 0; i < 3; i++)
	{
		printf("%p : string[%d] = %s\n", string[i], i, string[i]);
	}

	int a = 10;
	int b = 20;
	int c = 30;

	int* nArrPtr[] = { &a, &b, &c };

	for (int i = 0; i < 3; i++)
	{
		*nArrPtr[i] = (i + 1) << 10;
		printf("%p : string[%d] = %d\n", nArrPtr[i], i, *nArrPtr[i]);
	}

	*/

#pragma endregion

#pragma region Unsigned_Type

	/*

	// 부호가 없는 자료형
	// 부호 비트가 없고, 저장 가능한 양의 정수가 2배로 늘어난다.

	char data = 128;
	unsigned char uData = 255;

	// signed 자료형은 암묵적 형 변환이 진행될 때,
	// 늘어나는 메모리 값은 1(부호비트)로 채워진다.
	printf("data : %d\n", data);
	printf("data : %u\n\n", data);

	// 둘 다 부호가 없느 표현이므로 암묵적 형 변환이 진행될 때,
	// 늘어나는 메모리 값은 0으로 채워진다.
	printf("uData : %d\n", uData);
	printf("uData : %u\n", uData);
	
	*/

#pragma endregion

#pragma region Comon_Divisor

	/*
	
	// 두개의 정수형 변수 선언
	// x, y에 입력한 값을 저장하고
	// 공통된 약수를 구하라.

	int x, y;

	printf("두 정수를 입력해주세요 : ");
	scanf_s("%d %d", &x, &y);

	int a = x, b = y;
	int temp;

	while (b != 0)
	{
		temp = a;
		a = b;
		b = temp % a;
	}

	printf("%d와 %d의 공약수들 : ",x, y);
	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
		{
			printf("%d, ", i);
		}
	}
	printf("%d\n", a);
	
	*/

#pragma endregion

	// 0을 반환할 경우 : 정상적으로 종료됨
	return 0;
}