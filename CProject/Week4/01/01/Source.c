#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#pragma region Self_Referential_Structure

/*

// 자기자신을 가리키는 구조체 포인터가 

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

	//		  조건		참	  거짓
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
* A, B, C 개발자가 협업한다고 가정
* Main 프로젝트를 업로드
* 3 명 모두 Main에서 동시에 작업하면 충돌 가능성이 있음
* 이런 경우 branch를 사용하여 업무를 분할
* 각각 작업이 끝나면 자신의 작업물을 Main에 병합(merge)
*/

/*
클래스와 구조체(사용 전)의 메모리 위치
언리얼과 유니티의 차이
*/