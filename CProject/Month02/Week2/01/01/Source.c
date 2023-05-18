#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#define SIZER 100

void PrintReverse(char string[])
{
	if (string[0] == '\0')
	{
		return;
	}

	PrintReverse(&string[1]);
	printf("%c", string[0]);
}

int main()
{

#pragma region Dynamic_Allocation

	/*

	// HEAP이라는 메모리 공간을 이용하여
	// 배열의 크기를 컴파일 단계가 아닌
	// 실행 시간에 가변적으로 바꿀 수 있는 배열

	// 스택 배열의 크기는 컴파일 시점에 정해지는데,
	// 메모리 구조상 코드, 데이터 영역은 컴파일 시점에 크기가 정해지지만,
	// 스택, 힙 영역은 런타임 시점에 크기가 정해진다.
	// 따라서 스택 변수로 배열을 생성할 수 없다.

	int size = 10;
	scanf_s("%d", &size);

	int* arrayPtr = (int*)malloc(sizeof(int) * size);
	

	for (int i = 0; i < size; i++)
	{
		arrayPtr[i] = size * i;
	}

	for (int i = 0; i < size; i++)
	{
		printf("arrayPtr[%d] = %d\n", i, arrayPtr[i]);
	}

	free(arrayPtr);
	
	*/

#pragma endregion

#pragma region fflush()

	/*

	char a, b, c;

	printf("문자 입력 : ");
	scanf_s("%c", &a, 1);
	fflush(stdin);

	scanf_s("%c", &b, 1);
	fflush(stdin);

	scanf_s("%c", &c, 1);
	fflush(stdin);

	printf("a변수의 값 : %c\n", a);
	printf("b변수의 값 : %c\n", b);
	printf("c변수의 값 : %c\n", c);
	
	*/

#pragma endregion

#pragma region Reverse_String

	/*

	// 문자열 입력 후 역순으로 저장 및 출력
	char string1[100] = { 0 };
	char string2[100] = { 0 };
	scanf_s("%[^\n]s", string1, 100);
	int size = (int)strlen(string1);

	PrintReverse(string1);
	printf("\n");

	for (int i = 0; i < size; i++)
	{
		string2[i] = string1[size - i - 1];
	}
	printf("%s\n", string2);
	
	*/

#pragma endregion



	return 0;
}
