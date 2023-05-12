#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma region Rand
	
	/*
	
	// 0 ~ 32767 사이의 난수 값을 생성하는 함수

	// time : 1970년 1월 1일 (UTC)부터 현재까지 흐론 시간(초)을 반환
	
	*/
	
#pragma endregion

#pragma region Up-Down_Game

	/*
	
	srand((unsigned)time(NULL));


	// 1. 컴퓨터가 랜덤한 값 (1 ~ 50)을 뽑는다.
	int key = rand() % 49 + 1;
	int answer = 0;
	// 2. Life는 5개 -> 0개가 되면 게임오버
	int lifeCount = 5;
	int isWin = 0;

	while (lifeCount)
	{
		// 3. 컴퓨터가 랜덤한 값을 맞추기 위해
		//	  임의의 수를 입력
		printf("남은 기회 : %d\n", lifeCount);
		printf("숫자를 입력해수세요 (1 ~ 50) : ");
		scanf_s("%d", &answer);

		if (answer < 1 || answer > 50)
		{
			system("cls");
			continue;
		}

		// 4. 컴퓨터가 입력한 값을 맞추면 승리
		if (answer == key)
		{
			isWin = 1;
			break;
		}
		else
		{
			// 5. 내가 입력한 값보다 큰지 작은지를 출력
			printf("\n*********************\n");
			if (answer > key)
			{
				printf("\n\tDown!!!\n");
			}
			else
			{
				printf("\n\tUp!!!\n");
			}
			printf("\n*********************\n\n");

			// 6. 숫자를 틀릴수록 Life 1 감소
			lifeCount--;
		}
	}

	if (isWin)
	{
		printf("\n\n게임에서 승리했습니다!!!\n\n");
	}
	else
	{
		printf("\n\n게임에서 패배했습니다...\n");
		printf("정답 : %d\n\n", key);
	}

	*/

#pragma endregion

#pragma region Interger_Promotion

	/*

	// char 자료형과 short 자료형이 연산이 이루어질 때,
	// CPU가 처리하기에 가장 적합한 크기의 정수 자료형
	// int로 자동 형 변환하는 과정

	char data1 = 5;
	short data2 = 10;

	printf("sizeof(data1 + data2) : %lluByte\n", sizeof(data1 + data2));
	
	*/

#pragma endregion

	return 0;
}