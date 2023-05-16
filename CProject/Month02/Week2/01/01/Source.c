#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

enum ARROW_KEYS
{
	UP		= 72,
	LEFT	= 75,
	RIGHT	= 77,
	DOWN	= 80
};

// 좌표이동 함수
void GotoXY(int x, int y)
{
	COORD position = { x + x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{

#pragma region strlen()

	/*

	// 문자열의 크기를 반환하는 함수
	// 문자열의 끝인 NULL 문자를 포함하지 않는 크기가 나온다
	char* string = "Count";

	size_t strSize = strlen(string);

	printf("strSize : %llu\n", strSize);

	*/

#pragma endregion

#pragma region Palindrome

	/*

	char data[101] = { 0 };
	scanf_s("%s", data, 101);
	size_t size = strlen(data);

	char* newData = (char*)malloc(sizeof(char) * (size + 1));
	if (newData == NULL)
	{
		printf("ERROR : Failed to Create string!!!\n");
		return -1;
	}
	strcpy_s(newData, size + 1, data);

	for (int i = 0; i < size; i++)
	{
		if (newData[i] >= 'a' && newData[i] <= 'z')
		{
			newData[i] -= 'a' - 'A';
		}
	}

	int flag = 1;
	for (int i = 0; i < size / 2; i++)
	{
		if (newData[size - i -1] != newData[i])
		{
			flag = 0;
			break;
		}
	}

	if (flag == 1)
	{
		printf("회문\n");
	}
	else
	{
		printf("회문 아님\n");
	}

	free(newData);
	
	*/

#pragma endregion

	return 0;
}