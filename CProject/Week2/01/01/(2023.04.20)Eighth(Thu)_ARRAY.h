#include <stdio.h>
#include <stdlib.h>

void main()
{
#pragma region Array

	/*

	// 같은 자료형의 변수들로 이루어진 유한 집합

	//  0  1  2  3  4
	// [ ][ ][ ][ ][ ]
	int array[5] = { 0 };

	// 배열의 경우 첫 번째 원소는 0부터 시작
	array[0] = 100;
	array[1] = 200;
	array[2] = 300;
	array[3] = 400;
	array[4] = 500;

	printf("Array 출력 중...\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Array[%d] : %d\n", i, array[i]);
	}

	// 배열의 크기는 컴파일이 되는 시점부터 고정돤 메모리 공간을 가지게 된다.
	// (배열 확장이 불가능)
	// array[5] = 600;	(X)

	// [ ][ ][ ][ ][ ]	   [0]	  [1]	  [2]
	float itemList[3] = { 15.5f, 30.25f, 57.15f };

	// 배열의 메모리 공간은 프로그램이 실행되는 동안 변경할 수 없다.
	// float itemList[3] = { 15.5f, 30.25f, 57.15f, 1.0f };	(X)

	printf("ItemList 출력 중...\n\n");
	for (int i = 0; i < 3; i++)
	{
		printf("ItemList[%d] : %f\n", i, itemList[i]);
	}

	// 배열의 크기는 생략할 수 있으며, 초기화 목록에서
	// 설정한 요소에 따라 배열의 크기가 결정된다.
	char string[] = { 'A', 'B', 'C', '\0'};

	// 배열의 이름은 배열의 시작 주소를 가리킨다.
	printf("string배열 의 주소 : 0x%p\n", string);
	for (int i = 0; i < 4; i++)
	{
		printf("string[%d]  의 주소 : 0x%p\n", i, &string[i]);
	}

	// 배열과 포인터의 관계
	int		data = 100;
	int		*ptr = &data;

	printf("ptr	 : %p\n", ptr);
	printf("ptr + 1	 : %p\n", ptr + 1);

	// 16 진수		||	2 진수
	// 1 ~ 9		||
	// 10 : 0x0A	||	0b00001010
	// 11 : 0x0B	||	0b00001011
	// 12 : 0x0C	||	0b00001100
	// 13 : 0x0D	||	0b00001101
	// 14 : 0x0E	||	0b00001110
	// 15 : 0x0F	||	0b00001111
	// 16 : 0x10	||	0b00010000

	*/

#pragma endregion

#pragma region Shift Operator

	/*

// 비트 값을 주어진 숫자만큼 부호 방향으로 이동시키는 연산자

	char value = 10;	// 0000 1010

// >> : 비트값을 주어진 숫자만큼 오른쪽으로 이동

	// 0000 1010
	// 0000 0101 -> 1번 오른쪽 비트 연산을 한 결과
	// 0000 0010 -> 2번 오른쪽 비트 연산을 한 결과
	printf("value 변수를 오른쪽으로 2번 비트 연산한 결과 : %d\n", value >> 2);

// << : 비트값을 주어진 숫자만큼 왼쪽으로 이동

	// 0000 1010
	// 0001 0100 -> 1번 왼쪽 비트 연산을 한 결과
	// 0010 1000 -> 2번 왼쪽 비트 연산을 한 결과
	// 0101 0000 -> 3번 왼쪽 비트 연산을 한 결과
	printf("value 변수를 오른쪽으로 2번 비트 연산한 결과 : %d\n", value << 3);

	// 7 % 5 (모듈러 연산)

	*/

#pragma endregion


}

// 네트워크 photon network, playfab