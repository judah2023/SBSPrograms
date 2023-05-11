#include <stdio.h>
#include <stdlib.h>

void main()
{

#pragma region Pointer Of Const
	/*

	// 포인터 변수를 상수로 선언하여,
	// 포인터 변수를 가리키고 있는 주소에 존재하는 값을
	// 변경 할 수 없도록 하는 상수화

	int data = 100;
	int data1 = 20;

	const int *ptr = &data;

	printf("ptr 변수의 값 : %p\n", ptr);

	// *ptr = 300; (X)
	ptr = &data1;

	printf("ptr 변수의 값 : %p\n", ptr);

	*/
#pragma endregion

#pragma region Const Of Ponter
	/*

	// 상수로 선언한 포인터이므로, 해당 변수의 값을 변경할 수 없지만,
	// 다른 변수의 주소 값을 가리킬 수 있다.
	int value1 = 30;
	int value2 = 60;

	int* const ptr1 = &value1;	// 포인터 변수를 상수화

	printf("value1의 값 : %d\n", value1);

	// ptr1 = &value2;	(X)
	*ptr1 = 99999;	// 역참조 값 변경 가능

	printf("value1의 값 : %d\n", value1);

	// 배열의 이름은 포인터 상수(Const Of Ponter)로 되어있다.

	*/
#pragma endregion

#pragma region sizeof(Type)
	/*

	float health = 66.5f;
	short *pointer = NULL;

	printf("char의 크기 : %llu\n", sizeof(char));
	printf("short의 크기 : %llu\n", sizeof(short));
	printf("int의 크기 : %llu\n", sizeof(int));
	printf("long의 크기 : %llu\n", sizeof(long));
	printf("long long의 크기 : %llu\n\n", sizeof(long long));

	printf("health의 크기 : %llu\n", sizeof(health));
	printf("float의 크기 : %llu\n", sizeof(float));
	printf("double의 크기 : %llu\n", sizeof(double));
	printf("long double의 크기 : %llu\n\n", sizeof(long double));

	printf("Pointer의 크기 : %llu\n", sizeof(pointer));

	*/
#pragma endregion

#pragma region Multiplication Table
	/*

	for (int i = 2; i <= 9; i++)
	{
		printf(" %d단\t\t", i);
	}
	printf("\n\n");

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			printf(" %d X %d = %d\t", j, i, i * j);
		}
		printf("\n\n");
	}

	*/
#pragma endregion

#pragma region OutPut_scanf
	/*

	// 표준 입력 함수로, 여려 종류의 데이터를
	// 다양한 서식에 맞추어 입력해주는 함수

	// scanf <- SDL 검사 해제를 안하고 사용하게 될 경우 ERROR 발생

	// scanf_s("입력할 변수의 서식", &변수)
	int count = 2 << 30;

	printf("Count 변수의 값(변경 전) : %4d\n", count);

	printf("변경할 값을 입력하세요. : ");
	scanf_s("%d", &count);

	printf("Count 변수의 값(변경 후) : %4d\n", count);

	// 표준 입력 함수는 입력을 수행할 때까지
	// 다음 작업으로 넘어갈 수 없습니다.

	*/

	/*

	// 별 찍기
	// 문제) 내가 입력한 값에 따라 별이 찍히도록 구현해주세요.

	int floor = 0;

	printf("몇 층으로 하시겠어요? : ");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("☆");
		}
		printf("\n");
	}

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= floor + i; j++)
		{
			if ((i + j) % 2 == 0 || j < floor - i - 1)
			{
				printf("  ");
			}
			else
			{
				printf("☆");
			}
		}
		printf("\n");
	}

	*/

#pragma endregion

}

// 네트워크 photon network, playfab