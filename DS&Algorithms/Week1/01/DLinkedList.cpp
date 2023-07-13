#include "DLinkedList.h"

void DLinkedList::PushFront(int data)
{
	NODE* newNode = MakeNode(data);
	
	newNode->next = head;
	head->prev = newNode;
	
	head = newNode;
	size++;
}

void DLinkedList::PushBack(int data)
{
	NODE* newNode = MakeNode(data);

	newNode->next = tail;
	newNode->prev = tail->prev;
	
	if (head != tail)
		tail->prev->next = newNode;
	else
		head = newNode;

	tail->prev = newNode;
	size++;
}

void DLinkedList::PopFront()
{
	NODE* delNode = head;

	head = head->next;
	head->prev = nullptr;

	DeleteNode(delNode);
	size--;
}

void DLinkedList::PopBack()
{
	NODE* delNode = tail->prev;

	delNode->prev->next = tail;
	tail->prev = delNode->prev;

	DeleteNode(delNode);
	size--;
}

NODE* DLinkedList::Insert(NODE* target, int data)
{
	NODE* newNode = MakeNode(data);

	newNode->next = target;
	newNode->prev = target->prev;

	target->prev->next = newNode;
	target->prev = newNode;

	size++;
	return target;
}

NODE* DLinkedList::Erase(NODE* target)
{
	return nullptr;
}

size_t DLinkedList::Size()
{
	return size;
}

bool DLinkedList::Empty()
{
	return head == tail;
}
