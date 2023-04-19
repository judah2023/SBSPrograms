#include <stdio.h>
#include <stdlib.h>

void main()
{
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
	
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("☆");
		}
		printf("\n");
	}

	*/
	// 별 찍기
	// 문제) 내가 입력한 값에 따라 별이 찍히도록 구현해주세요.

	int floor = 0;

	printf("몇 층으로 하시겠어요? : ");
	scanf_s("%d", &floor);

	
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= floor + i; j++)
		{
			if ((i + j) % 2 == 0 || j < floor - i)
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

#pragma endregion


}

// 네트워크 photon network, playfab