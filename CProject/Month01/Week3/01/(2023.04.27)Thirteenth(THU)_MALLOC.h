#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SoundManager.h"

void main()
{
#pragma region Dynamic_Allocation

	/*

	// 프로그램을 실행 중에 필요한 만큼 메모리를 할당하는 작업
	// 동적할당한 메모리는 반드시 사용자가 해제해야 한다.

	// 해제하지 않는 경우
	// 메모리 누수(Leak)이 발생하여 OS가 강제로 프로그램을 종료시킬 수 있다.

	// 동적 할당은 실행 시간에 가변적으로 메모리의 크기를 변경할 수 있으며,
	// 동적 할당할 때 바이트 단위로 저장한다.
	int *ptr = (int*)malloc(sizeof(int));
	if (ptr == NULL)
	{
		printf("\n\nERROR : Failed to Allocate Memory!!!\n\n");
		return;
	}

	// 메모리 동적 할당할 때 주소를 void 포인터로 반환하기 때문에
	// 자료형을 변환한 다음 할당해야 한다.
	*ptr = 1000;

	printf("동적 할당한 메모리 안의 값 : %d\n", *ptr);

	// 메모리 해제
	free(ptr);

	// 이미 해제된 메모리를 해제하면 Error가 발생한다.
	// free(ptr);

	*/

#pragma endregion

#pragma region ASCII_Code

	/*

	// 영문 알파벳을 사용하는 대표적인 문자 인코딩

	char alphabet = 65;

	printf("ASCII code 정수 값 : %d\n", alphabet);
	printf("ASCII code 문자 값 : %c\n", alphabet);

	// 문제) 알파벳 a ~ z까지 출력해주세요.
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		printf("%c ", ch);
	}

	*/

#pragma endregion

#pragma region Dangling_Pointer

	/*

	// 이미 해제된 메모리 영역을 가리키는 포인터

	int *intPtr = malloc(sizeof(int));

	*intPtr = 300;

	printf("intPtr이 가리키는 값 (해제 전) : %d\n", *intPtr);

	free(intPtr);

	printf("intPtr이 가리키는 값 (해제 후) : %d\n", *intPtr);

	intPtr = NULL;

	*/

#pragma endregion

#pragma region Double_Pointer

	/*

	// 포인터의 주소를 담는 포인터

	int a		= 100;
	int* aPtr	= &a;
	int** dAPtr	= &aPtr;

	printf("  dPtr의 값 : %p\n", dAPtr);
	printf(" *dPtr의 값 : %p\n", *dAPtr);
	printf("**dPtr의 값 : %d\n\n", **dAPtr);

	int b		= 200;
	int* bPtr	= &b;
	int** dBPtr = &bPtr;

	printf("  dPtr의 값 : %p\n", dBPtr);
	printf(" *dPtr의 값 : %p\n", *dBPtr);
	printf("**dPtr의 값 : %d\n\n", **dBPtr);

	int temp = **dBPtr;
	**dBPtr  = **dAPtr;
	**dAPtr  = temp;

	printf("a의 값 : %d\n", **dAPtr);
	printf("b의 값 : %d\n\n", **dBPtr);

	*/


#pragma endregion

}