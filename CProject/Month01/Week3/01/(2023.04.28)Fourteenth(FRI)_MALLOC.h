#pragma once

#include <stdio.h>
#include <stdlib.h>

#pragma region Structure

/*

// 여러 개의 변수를 하나의 집합으로 구조화한 다음
// 하나의 객체를 생성하는 것

struct Player
{
	char	grade;
	int		attack;
	float	health;

	// 구조체를 선언하기 전에 구조체는 메모리 공간이 생성되지 않으므로,
	// 구조체 내부에 있는 데이터를 초기화 할 수 없다.
};

struct Model
{
	short	mesh;
	int		weight;
	double	size;

	// 구조체 크기의 경우 멤버 변수의 순서에 따라
	// 메모리의 크기가 다르게 설정될 수 있으며,
	// 구조체 크기를 결정하는 형태는 기본 자료형으로만 구성된다.
};

*/

#pragma endregion

#pragma region Question

/*

int IsPrime(int x)
{
	if (x % 2 == 0)
	{
		if (x == 2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

*/

#pragma endregion

void main()
{
#pragma region Structure_Init

	/*

	// 구조체 선언
	struct Player player;

	// player.grade = 'A';
	// player.attack = 10;
	// player.health = 91.25f;

	// printf("player.grade의 값 : %c\n", player.grade);
	// printf("player.attack의 값 : %d\n", player.attack);
	// printf("player.health의 값 : %f\n\n", player.health);

	// 구조체 초기화
	// 구조체를 초기화 리스트로 초기화할 때,
	// 구조체에 선언된 변수의 순서로 정의해주어야 한다.
	struct Player newPlayer = { 'B', 15, 66.85f };

	printf("newPlayer.attack의 값 : %d\n", newPlayer.attack);
	printf("newPlayer.grade의 값 : %c\n", newPlayer.grade);
	printf("newPlayer.health의 값 : %f\n\n", newPlayer.health);

	*/

#pragma endregion

#pragma region Byte_Padding

	/*

	// 멤버 변수를 메모리에서 CPU로 읽을 때 한번에 읽을 수 있도록,
	// 컴파일러가 레지스타의 블록에 맞추어 바이트를 패딩 해주는 작업

	struct Player otherPlayer;
	struct Model model;

	// 구조체의 크기는 가장 자료형의 배수가 되도록 설정
	printf("Size Of Player : %llu Byte\n", sizeof(otherPlayer));
	printf("Size Of Model  : %llu Byte\n", sizeof(model));

	*/

#pragma endregion

#pragma region Prime

	/*

	// 자연수를 입력받고
	// 자연수 중 소수만을 출력

	int max = 0;
	int primeCount = 1;
	int lineCount = 0;


	printf("최대 자연수를 입력하세요 : ");
	scanf_s("%d", &max);

	for (int i = 2; i <= max; i += 2)
	{
		primeCount = 1;

		for (int j = 3; j * j <= i; j += 2)
		{
			if (i % j == 0)
			{
				primeCount = 0;
				break;
			}
		}

		if (primeCount == 1)
		{
			printf("%d\t", i);
			lineCount++;
		}


		if (i == 2)
		{
			i--;
		}

		if (lineCount == 10)
		{
			printf("\n");
			lineCount = 0;
		}
	}

	*/

#pragma endregion

}