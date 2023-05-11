#include <stdio.h>
#include <stdlib.h>

void main()
{
#pragma region Array

	/*

	// ���� �ڷ����� ������� �̷���� ���� ����

	//  0  1  2  3  4
	// [ ][ ][ ][ ][ ]
	int array[5] = { 0 };

	// �迭�� ��� ù ��° ���Ҵ� 0���� ����
	array[0] = 100;
	array[1] = 200;
	array[2] = 300;
	array[3] = 400;
	array[4] = 500;

	printf("Array ��� ��...\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Array[%d] : %d\n", i, array[i]);
	}

	// �迭�� ũ��� �������� �Ǵ� �������� ������ �޸� ������ ������ �ȴ�.
	// (�迭 Ȯ���� �Ұ���)
	// array[5] = 600;	(X)

	// [ ][ ][ ][ ][ ]	   [0]	  [1]	  [2]
	float itemList[3] = { 15.5f, 30.25f, 57.15f };

	// �迭�� �޸� ������ ���α׷��� ����Ǵ� ���� ������ �� ����.
	// float itemList[3] = { 15.5f, 30.25f, 57.15f, 1.0f };	(X)

	printf("ItemList ��� ��...\n\n");
	for (int i = 0; i < 3; i++)
	{
		printf("ItemList[%d] : %f\n", i, itemList[i]);
	}

	// �迭�� ũ��� ������ �� ������, �ʱ�ȭ ��Ͽ���
	// ������ ��ҿ� ���� �迭�� ũ�Ⱑ �����ȴ�.
	char string[] = { 'A', 'B', 'C', '\0'};

	// �迭�� �̸��� �迭�� ���� �ּҸ� ����Ų��.
	printf("string�迭 �� �ּ� : 0x%p\n", string);
	for (int i = 0; i < 4; i++)
	{
		printf("string[%d]  �� �ּ� : 0x%p\n", i, &string[i]);
	}

	// �迭�� �������� ����
	int		data = 100;
	int		*ptr = &data;

	printf("ptr	 : %p\n", ptr);
	printf("ptr + 1	 : %p\n", ptr + 1);

	// 16 ����		||	2 ����
	// 1 ~ 9		||
	// 10 : 0x0A	||	0b00001010
	// 11 : 0x0B	||	0b00001011
	// 12 : 0x0C	||	0b00001100
	// 13 : 0x0D	||	0b00001101
	// 14 : 0x0E	||	0b00001110
	// 15 : 0x0F	||	0b00001111
	// 16 : 0x10	||	0b00010000

	*/

#pragma endregion

#pragma region Shift Operator

	/*

// ��Ʈ ���� �־��� ���ڸ�ŭ ��ȣ �������� �̵���Ű�� ������

	char value = 10;	// 0000 1010

// >> : ��Ʈ���� �־��� ���ڸ�ŭ ���������� �̵�

	// 0000 1010
	// 0000 0101 -> 1�� ������ ��Ʈ ������ �� ���
	// 0000 0010 -> 2�� ������ ��Ʈ ������ �� ���
	printf("value ������ ���������� 2�� ��Ʈ ������ ��� : %d\n", value >> 2);

// << : ��Ʈ���� �־��� ���ڸ�ŭ �������� �̵�

	// 0000 1010
	// 0001 0100 -> 1�� ���� ��Ʈ ������ �� ���
	// 0010 1000 -> 2�� ���� ��Ʈ ������ �� ���
	// 0101 0000 -> 3�� ���� ��Ʈ ������ �� ���
	printf("value ������ ���������� 2�� ��Ʈ ������ ��� : %d\n", value << 3);

	// 7 % 5 (��ⷯ ����)

	*/

#pragma endregion

#pragma region Odd Or Even
	/*

	// ���� 17 <- �Է�
	// Ȧ�� ���
	int nInput;
	scanf_s("%d", &nInput);
	if (nInput % 2 == 0)
	{
		printf("%d�� ¦���Դϴ�.\n", nInput);
	}
	else
	{
		printf("%d�� Ȧ���Դϴ�.\n", nInput);
	}

	int a, b, tmp;
	printf("���� 2���� �Է����ּ���. : ");
	scanf_s("%d %d", &a, &b);
	while (b != 0)
	{
		tmp = b;
		b	= a % b;
		a	= tmp;
	}

	printf("a, b�� �ִ����� : %d\n", a);

	int nInput;
	scanf_s("%d", &nInput);
	if (nInput & 0x01)
	{
		printf("%d��(��) Ȧ���Դϴ�.\n", nInput);
	}
	else
	{
		printf("%d��(��) ¦���Դϴ�.\n", nInput);
	}

	*/

#pragma endregion

#pragma region Naming Convention

	/*

	// camel case (ī�� ǥ���)
	// ù �ܾ �����ϰ� ù ���ڸ� �빮�ڷ� ǥ��

	// ex) int playerHealth;

	// pascal case (�Ľ�Į ǥ���)
	// �ܾ��� ù ���ڸ� �빮�ڷ� ǥ��

	// ex) void SelectTarget( ) { }

	// snake case (������ũ ǥ���)
	// ���� �ҹ��ڷ� �ۼ��ϰ� �ܾ� ���̿� _�� ǥ��

	// ex) api_url

	*/

#pragma endregion
}

// ��Ʈ��ũ photon network, playfab