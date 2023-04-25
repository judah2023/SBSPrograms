#ifndef WEEK03_H
#define WEEK03_H

#include <stdio.h>
#include <stdlib.h>

#define ADD(x,y)		(x + y)
#define SWAP(T, x, y)	{T temp = x; x = y; y = temp;}

#pragma region Function

/*

// �ϳ��� Ư���� ������ �۾��� �����ϱ� ����
// ���������� �����?�ڵ��� ����

// void : ���� ��ȯ���� �ʴ� �ڷ��� ( 0����Ʈ�� �ؼ��ϴ� �ڷ���)
void Attack()
{
	for (int i = 0; i < 9; i++)
	{
		if (i < 9 && i % 4 == 0)
		{
			printf(" ����");
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

// ��ȯ�� : �Լ��� ����Ǿ���?�� ���� ��ȯ���ִ� ����
int Function()
{
	return 100;
}

// �Լ��� ���?�ڷ����� ��ȯ�ϴ� ���� ���°� ��ġ���� ������
// ���ϴ� ���� ���� �� ����.
int ProcessInt()
{
	return 67.5f;
}

// C����? �Լ� �̸��� �����ϴ�. (�ߺ� ������ �Ұ���)

*/

#pragma endregion

#pragma region Parameter

/*

// �Լ��� ���ǿ��� ���޹��� �μ���
// �Լ� ���η� �����ϱ� ���� ����ϴ�?����

void Calculator(int x)
{
	printf("�Ű������� �� : %d\n", x);
}

int Add(int x, int y)
{
	return x + y;
}

*/

#pragma endregion

// ������ ���� ���� (�Լ�)
void SwapReference(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// ���� ���� ���� (�Լ�)
void Swap(int x, int y)
{
	printf("�ּ� �� : [&x, &y] = [%p, %p]\n", &x, &y);
	printf("���� �� : [x, y] = [%d, %d]\n", x, y);

	int temp;
	temp = x;
	x = y;
	y = temp;

	printf("��� �� : [x, y] = [%d, %d]\n\n", x, y);

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

	// �μ�(Arguement)?
	// �Լ��� ȣ���?�� �Ű������� ������ ���޵Ǵ� ��
	Calculator(100);

	// �μ��� ���ʿ������� �Ű������� ���޵�
	printf("Add() �Լ��� �� : %d\n", Add(10, 20));
	// printf("ADD() �Լ��� �� : %d\n", ADD(10, 20));

	*/

#pragma endregion

#pragma region Call_by_Value_And_Call_by_Reference

	/*

	printf("���� �� : [a, b] = [%d, %d]\n\n", a, b);

	// Call by value
	Swap(a, b);

	printf("��� �� : [a, b] = [%d, %d]\n\n", a, b);

	printf("\n\n\n");

	int a = 100;
	int b = 200;

	printf("���� �� : [a, b] = [%d, %d]\n\n", a, b);

	// Call by Reference
	// �Լ��� ȣ���� �� ������ �ּҸ� �μ��� �����ϰ� �Ǹ�
	// ������ ������ �ּҰ� �����Ǿ� �μ��� ������ ����
	// �Լ� ������ �Ͼ ���꿡 ���� ������ �޴´�.
	SwapReference(&a, &b);

	printf("��� �� : [a, b] = [%d, %d]\n\n", a, b);

	*/

#pragma endregion

}

#endif // !WEEK3_H


