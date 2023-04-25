#include <stdio.h>
#include <stdlib.h>
#include "SoundManager.h"

#pragma region Recursive_Function

/*

	// 어떤 함수에서 자신을 다시 호출하여 작업을 수행하는 함수

	// return : 1. 값을 반환한다.
	//			2. 함수를 반환한다.

void Recursion(int number)
{
	if (number == 0)
	{
		// 재귀함수는 함수를 계속 호출하기 때문에
		// 스택 영역에 메모리가 계속 쌓이게 되므로
		// 스택오버플로우가 발생
		return;
	}

	Recursion(number - 1);
	printf("Recursion() %d번 호출 중...\n", number);
}

*/
#pragma endregion

#pragma region Factorial

/*

unsigned long long Factorial(unsigned long long x)
{
	if (x == 0)
	{
		return 1;
	}

	unsigned long long result = x * Factorial(x - 1);
	return result;
}

unsigned long long FactorialNonResursion(unsigned long long x)
{
	unsigned long long result = 1;

	for (int i = 1; i <= x; i++)
	{
		result *= i;
	}

	return result;
}

*/

#pragma endregion

#pragma region Inline_Function

/*

	// 함수를 호출하는 대신 함수가 호출되는 위치마다
	// 함수의 코드를 복사하여 전달하는 방식의 함수

	// 함수 호출시 발생하는 '오버헤드'를 줄이기 위해 사용
inline void Function()
{
	// inline 함수는 함수를 호출하는 과정이 없으므로
	// 처리속도가 빠르지만, 인라인 함수를 많이 사용하게 되면
	// 함수의 코드가 복사되기 때문에 실행 파일의 크기가 커지게 된다.

	// 인라인 함수는 코드가 적은 간단한 함수로만 쓰는 것이 좋다.
	printf("Function() 함수 호출중...\n");
}

*/

#pragma endregion





void main()
{
#pragma region Iteration_Do~While

	/*

	// 조건과 상관없이 한번의 작업을 수행한 다음
	// 조건에 따라 명령문을 실행하는 반복문
	int count = 3;

	do
	{
		printf("로그인 %d번 시도중...\n", count);
		count--;
	} while (count > 0);

	*/

#pragma endregion

	Sound();
}