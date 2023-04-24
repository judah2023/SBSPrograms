#include <stdio.h>
#include <stdlib.h>

#define ADD(x,y)		(x + y)
#define SWAP(T, x, y)	{T temp = x; x = y; y = temp;}

#pragma region Function

/*

// 占싹놂옙占쏙옙 특占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 占쌜억옙占쏙옙 占쏙옙占쏙옙占싹깍옙 占쏙옙占쏙옙
// 占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占?占쌘듸옙占쏙옙 占쏙옙占쏙옙

// void : 占쏙옙占쏙옙 占쏙옙환占쏙옙占쏙옙 占십댐옙 占쌘뤄옙占쏙옙 ( 0占쏙옙占쏙옙트占쏙옙 占쌔쇽옙占싹댐옙 占쌘뤄옙占쏙옙)
void Attack()
{
	for (int i = 0; i < 9; i++)
	{
		if (i < 9 && i % 4 == 0)
		{
			printf(" 占쏙옙占쏙옙");
		}
		else
		{
			printf(" !!!!");
		}

		if (i % 3 == 2)
		{
			printf("\n");
		}
	}
	printf("\n");
}

// 占쏙옙환占쏙옙 : 占쌉쇽옙占쏙옙 占쏙옙占쏙옙퓸占쏙옙占?占쏙옙 占쏙옙占쏙옙 占쏙옙환占쏙옙占쌍댐옙 占쏙옙占쏙옙
int Function()
{
	return 100;
}

// 占쌉쇽옙占쏙옙 占쏙옙占?占쌘뤄옙占쏙옙占쏙옙 占쏙옙환占싹댐옙 占쏙옙占쏙옙 占쏙옙占승곤옙 占쏙옙치占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙
// 占쏙옙占싹댐옙 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙 占쏙옙占쏙옙.
int ProcessInt()
{
	return 67.5f;
}

// C占쏙옙楮∽옙占? 占쌉쇽옙 占싱몌옙占쏙옙 占쏙옙占쏙옙占싹댐옙. (占쌩븝옙 占쏙옙占쏙옙占쏙옙 占쌀곤옙占쏙옙)

*/

#pragma endregion

#pragma region Parameter

/*

// 占쌉쇽옙占쏙옙 占쏙옙占실울옙占쏙옙 占쏙옙占쌨뱄옙占쏙옙 占싸쇽옙占쏙옙 
// 占쌉쇽옙 占쏙옙占싸뤄옙 占쏙옙占쏙옙占싹깍옙 占쏙옙占쏙옙 占쏙옙占쏙옙求占?占쏙옙占쏙옙

void Calculator(int x)
{
	printf("占신곤옙占쏙옙占쏙옙占쏙옙 占쏙옙 : %d\n", x);
}

int Add(int x, int y)
{
	return x + y;
}

*/

#pragma endregion

// 참조에 의한 전달 (함수)
void SwapReference (int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// 값에 의한 전달 (함수)
void Swap(int x, int y)
{
	printf("주소 값 : [&x, &y] = [%p, %p]\n", &x, &y);
	printf("원래 값 : [x, y] = [%d, %d]\n", x, y);

	int temp;
	temp = x;
	x = y;
	y = temp;

	printf("결과 값 : [x, y] = [%d, %d]\n\n", x, y);

}

void main()
{
#pragma region Call_Function(None Parameter)

	/*
	//Attack();
	//Attack();

	printf("Function() : %d\n\n", Function());
	printf("ProcessFloat() : %d\n\n", ProcessInt());
	*/

#pragma endregion

#pragma region Call_Function(Using Parameter)

	/*
	
	// 占싸쇽옙(Arguement)?
	// 占쌉쇽옙占쏙옙 호占쏙옙占?占쏙옙 占신곤옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 占쏙옙占쌨되댐옙 占쏙옙
	Calculator(100);

	// 占싸쇽옙占쏙옙 占쏙옙占십울옙占쏙옙占쏙옙占쏙옙 占신곤옙占쏙옙占쏙옙占쏙옙 占쏙옙占쌨듸옙
	printf("Add() 占쌉쇽옙占쏙옙 占쏙옙 : %d\n", Add(10, 20));
	// printf("ADD() 占쌉쇽옙占쏙옙 占쏙옙 : %d\n", ADD(10, 20));

	*/

#pragma endregion

#pragma region Call_by_Value_And_Call_by_Reference

	/*
	
	printf("원래 값 : [a, b] = [%d, %d]\n\n", a, b);

	// Call by value
	Swap(a, b);

	printf("결과 값 : [a, b] = [%d, %d]\n\n", a, b);

	printf("\n\n\n");

	*/

	int a = 100;
	int b = 200;

	printf("원래 값 : [a, b] = [%d, %d]\n\n", a, b);

	// Call by Reference
	// 함수를 호출할 때 변수의 주소를 인수로 전달하게 되면
	// 전달한 변수의 주소가 참조되어 인수로 전달한 값이
	// 함수 내에서 일어난 연산에 대해 영향을 받는다.
	SwapReference(&a, &b);

	printf("결과 값 : [a, b] = [%d, %d]\n\n", a, b);


#pragma endregion

}