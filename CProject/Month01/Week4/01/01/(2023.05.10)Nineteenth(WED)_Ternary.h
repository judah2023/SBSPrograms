#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#pragma region Self_Referential_Structure

/*

// �ڱ��ڽ��� ����Ű�� ����ü �����Ͱ�

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

Node CreateNode(int data)
{
	Node newNode;
	newNode.data = data;
	newNode.next = NULL;

	return newNode;
}

void InsertNode(Node* head, Node* newNode, int number)
{
	Node* prevNode = head;

	if (number == 0)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	for (int i = 1; i < number - 1; i++)
	{
		prevNode = prevNode->next;
	}

	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

*/

#pragma endregion

int main()
{
#pragma region Ternary_Operator

	/*

	printf("%d\n\n", 1 < 0 ? 100 : // ->
					 2 < 1 ? 200 : // ->
					 3 < 2 ? 300 : 400);

	int data = 0;

	//		  ����		��	  ����
	data = (10 != 10) ? 100 : 999;
	printf("%d\n", data);

	*/

#pragma endregion

	/*

	char string[15] = { 0 };

	scanf_s("%[^\n]s", string, 15);

	printf("string : %s\n", string);

	*/

	return 0;
}




























/* github - Branch
* A, B, C �����ڰ� �����Ѵٰ� ����
* Main ������Ʈ�� ���ε�
* 3 �� ��� Main���� ���ÿ� �۾��ϸ� �浹 ���ɼ��� ����
* �̷� ��� branch�� ����Ͽ� ������ ����
* ���� �۾��� ������ �ڽ��� �۾����� Main�� ����(merge)
*/

/*
Ŭ������ ����ü(��� ��)�� �޸� ��ġ
�𸮾�� ����Ƽ�� ����
*/