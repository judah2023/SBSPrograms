#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

void Array(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = 100 * i;
	}
}

void ChangeString(char str[], int size)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
}

void Information(int size, ...)
{
	// va_list
	// 각 가변 인자의 시작주소를 가리키는 포인터
	va_list argPtr;

	// va_start
	// va_list로 만들어진 포인터에게 가변인자 중
	// 첫 번째 인자의 주소를 가르쳐주는 매크로입니다.
	va_start(argPtr, size);

	int result = 0;


	for (int i = 0; i < size; i++)
	{
		// va_arg
		// 특정 가변인자를 가리키고 있는 va_list의 포인터를
		// 다음 가변인자로 이동시켸 주는 매크로입니다.
		result += va_arg(argPtr, int);
	}

	printf("result : %d\n", result);
	
	// va_end
	// 사용한 가변인자 변수를 끝낼 때 NULL로 돌려주는 매크로
	va_end(argPtr);
}

int main()
{
#pragma region Array_Parameter

	/*
	
	int dataList[5] = { 1, 2, 3, 4, 5 };

	Array(dataList, 5);

	printf("List : ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", dataList[i]);
	}
	printf("\n");

	*/

#pragma endregion

	/*
	
	char ptr[27] = { 0 };
	
	scanf("%[^\n]s", ptr);

	// 소문자 입력
	// 대문자로 변경
	ChangeString(ptr, 27);

	printf("%s\n", ptr);

	*/

#pragma region Dynamic_argument

	/*
	
	*/

	// 매개변수로 들어오는 값의 갯수와 상관없이
	// 동적으로 인수를 받을 수 있는 인수입니다.
	Information(5, 1, 2, 3, 4, 5);

#pragma endregion

	
	return 0;
}