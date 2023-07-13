#include <iostream>
#include <list>
#include "DLinkedList.h"

using namespace std;

int main()
{
	DLinkedList DL;
	DL.PushBack(10);
	DL.PushBack(20);
	DL.PushBack(30);
	DL.PushFront(0);

	DL.PrintList();
	cout << DL.Size() << endl;

	DL.PopBack();

	DL.PrintList();
	cout << DL.Size() << endl;

	DL.PopFront();

	DL.PrintList();
	cout << DL.Size() << endl;

	return 0;
}