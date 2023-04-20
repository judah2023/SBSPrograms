#include <stdio.h>
#include <stdlib.h>

void main()
{

#pragma region Pointer Of Const
	/*

	// ������ ������ ����� �����Ͽ�,
	// ������ ������ ����Ű�� �ִ� �ּҿ� �����ϴ� ����
	// ���� �� �� ������ �ϴ� ���ȭ

	int data = 100;
	int data1 = 20;

	const int *ptr = &data;

	printf("ptr ������ �� : %p\n", ptr);

	// *ptr = 300; (X)
	ptr = &data1;

	printf("ptr ������ �� : %p\n", ptr);

	*/
#pragma endregion

#pragma region Const Of Ponter
	/*

	// ����� ������ �������̹Ƿ�, �ش� ������ ���� ������ �� ������,
	// �ٸ� ������ �ּ� ���� ����ų �� �ִ�.
	int value1 = 30;
	int value2 = 60;

	int* const ptr1 = &value1;	// ������ ������ ���ȭ

	printf("value1�� �� : %d\n", value1);

	// ptr1 = &value2;	(X)
	*ptr1 = 99999;	// ������ �� ���� ����

	printf("value1�� �� : %d\n", value1);

	// �迭�� �̸��� ������ ���(Const Of Ponter)�� �Ǿ��ִ�.

	*/
#pragma endregion

#pragma region sizeof(Type)
	/*

	float health = 66.5f;
	short *pointer = NULL;

	printf("char�� ũ�� : %llu\n", sizeof(char));
	printf("short�� ũ�� : %llu\n", sizeof(short));
	printf("int�� ũ�� : %llu\n", sizeof(int));
	printf("long�� ũ�� : %llu\n", sizeof(long));
	printf("long long�� ũ�� : %llu\n\n", sizeof(long long));

	printf("health�� ũ�� : %llu\n", sizeof(health));
	printf("float�� ũ�� : %llu\n", sizeof(float));
	printf("double�� ũ�� : %llu\n", sizeof(double));
	printf("long double�� ũ�� : %llu\n\n", sizeof(long double));

	printf("Pointer�� ũ�� : %llu\n", sizeof(pointer));

	*/
#pragma endregion

#pragma region Multiplication Table
	/*

	for (int i = 2; i <= 9; i++)
	{
		printf(" %d��\t\t", i);
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

	// ǥ�� �Է� �Լ���, ���� ������ �����͸�
	// �پ��� ���Ŀ� ���߾� �Է����ִ� �Լ�

	// scanf <- SDL �˻� ������ ���ϰ� ����ϰ� �� ��� ERROR �߻�

	// scanf_s("�Է��� ������ ����", &����)
	int count = 2 << 30;

	printf("Count ������ ��(���� ��) : %4d\n", count);

	printf("������ ���� �Է��ϼ���. : ");
	scanf_s("%d", &count);

	printf("Count ������ ��(���� ��) : %4d\n", count);

	// ǥ�� �Է� �Լ��� �Է��� ������ ������
	// ���� �۾����� �Ѿ �� �����ϴ�.

	*/

	/*

	// �� ���
	// ����) ���� �Է��� ���� ���� ���� �������� �������ּ���.

	int floor = 0;

	printf("�� ������ �Ͻðھ��? : ");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("��");
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
				printf("��");
			}
		}
		printf("\n");
	}

	*/

#pragma endregion

}

// ��Ʈ��ũ photon network, playfab