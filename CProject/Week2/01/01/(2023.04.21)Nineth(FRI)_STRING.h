// ��ó�����?
// ���α׷��� �����ϵǱ� ���� ���� ó���Ǵ� ����

// #include ���� ó�� ��ó�� ��
// �ý��� �����̳� ����� ���� ������ ���α׷� �ҽ��� �����ϱ� ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGNUMBER	1000

#pragma region Macro
	// ���α׷� ������ Ư���� �����Ͱ� ���ǵǰ� ó���Ǵ� ����

	// ��ó���⿡�� ó���ǹǷ� ��ɹ� ����
	// ";"�� ������� �ʴ´�
#define SIZE		5

	// ��ũ�δ� ���� �޸� ������ ������ ���� �ʴ�.

#pragma endregion

void main()
{
#pragma region String

	/*

	// �������� �޸� ������ �����
	// ���� ������ �����Դϴ�.

	// ���ڿ��� ��� �����͸� �̿��Ͽ�
	// ���ڿ� ����� ����ų�� �ִ�.
	const char* name = "James";

	// %s : ���ڿ��� ����ϴ� ����
	printf("*name ������ �� : %s\n", name);
	printf("*name �� �ּ� : %p\n\n", name);

	// ���ڿ� ����� �б� ���� ������ ������ ����ǹǷ�
	// ���ڿ��� ���� ������ �� ����.
	// *name = 'G';		(X)
	// name[0] = 'G'	(X)

	name = "Tom";


	// ���ڿ��� �� �������� �� ���ڰ� �ڵ����� ����
	printf("*name ������ �� : %s\n", name);
	printf("*name �� �ּ� : %p\n\n", name);

	// �迭�� �̿��� ���ڿ�
	char string[] = "Game";

	// ���ڿ��� ���鵵 �޸� ������ ����
	char string1[] = "App le";

	printf("string�� �� : %s\n", string);

	string[0] = 'B';
	string[3] = 'o';

	printf("string�� �� : %s\n", string);

	// char �迭�� ������ ���
	// string = string1;
	// string = "Com";

	// ���� �迭 ���̿� ��ȿ�� ���ڸ� �ְ� �Ǹ�
	// �ι��ڱ����� ���ڿ��� ���

	*/

#pragma endregion

#pragma region Max and Min
	/*

	// int �迭���� �ִ밪�� �ּҰ��� ���� ���

	int arr[] = { 1,2,3,4,5 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	int nMax = arr[0];
	int nMin = arr[0];

	for (int i = 1; i < arrSize; i++)
	{
		if (nMax < arr[i])
		{
			nMax = arr[i];
		}

		if (nMin > arr[i])
		{
			nMin = arr[i];
		}
	}

	printf("�迭 Arr�� �ִ밪, �ּҰ� : %d, %d\n", nMax, nMin);

	int a0 = 1;
	int a1 = 1;

	int num;
	int tmp;

	printf("n ? : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		printf("%2d��° �Ǻ���ġ �� : %10d\n", i, a0);
		tmp = a1;
		a1 += a0;
		a0 = tmp;
	}

	int sifter[BIGNUMBER] = { 0 };

	int prime;

	sifter[0] = 1;

	for (int i = 3; i < BIGNUMBER; i += 2)
	{
		sifter[i] = 1;
	}

	for (int i = 2; i * i < BIGNUMBER; i += 2)
	{
		prime = i + 1;
		if (sifter[prime - 1] == 0)
		{
			for (int j = prime * 2; j <= BIGNUMBER; j += prime)
			{
				sifter[j - 1] = 1;
			}
		}

	}

	for (int i = 0; i < BIGNUMBER; i++)
	{
		if (sifter[i] == 0)
		{
			printf("Prime : %d\n", i + 1);
		}
	}

	*/

#pragma endregion


}
// ��Ʈ��ũ ph2ton network, playfab