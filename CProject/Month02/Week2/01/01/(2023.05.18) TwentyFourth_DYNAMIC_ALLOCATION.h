#pragma once

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

	// HEAP�̶�� �޸� ������ �̿��Ͽ�
	// �迭�� ũ�⸦ ������ �ܰ谡 �ƴ�
	// ���� �ð��� ���������� �ٲ� �� �ִ� �迭

	// ���� �迭�� ũ��� ������ ������ �������µ�,
	// �޸� ������ �ڵ�, ������ ������ ������ ������ ũ�Ⱑ ����������,
	// ����, �� ������ ��Ÿ�� ������ ũ�Ⱑ ��������.
	// ���� ���� ������ �迭�� ������ �� ����.

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

	printf("���� �Է� : ");
	scanf_s("%c", &a, 1);
	fflush(stdin);

	scanf_s("%c", &b, 1);
	fflush(stdin);

	scanf_s("%c", &c, 1);
	fflush(stdin);

	printf("a������ �� : %c\n", a);
	printf("b������ �� : %c\n", b);
	printf("c������ �� : %c\n", c);

	*/

#pragma endregion

#pragma region Reverse_String

	/*

	// ���ڿ� �Է� �� �������� ���� �� ���
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
