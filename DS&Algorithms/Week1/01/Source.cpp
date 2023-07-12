#include <iostream>

using namespace std;

// 1. 노드 만들기
struct NODE
{
	int data;
	NODE* nextNode;
};

void AddNode(NODE** tail, int data)
{
	NODE* newNode = new NODE{ data, nullptr };

	newNode->nextNode = (*tail)->nextNode;
	(*tail)->nextNode = newNode;
	*tail = newNode;
}

void PrintAll(NODE* head)
{
	while (head->nextNode != nullptr)
	{
		head = head->nextNode;
		
		cout << head->data;
		if (head->nextNode != nullptr)
			cout << " -> ";
	}
	cout << endl;
}

class LinkedList
{
private:
	NODE* head;
	NODE* tail;

	NODE* MakeNode(int data) 
	{
		NODE* newNode = new NODE{ data, nullptr };
		return newNode;
	}

	void DeleteNode(NODE* node)
	{
		delete node;
	}

public:
	LinkedList() : head(nullptr), tail(nullptr) { cout << "LinkedList is Started!\n"; }
	~LinkedList() 
	{
		while (head != nullptr)
			Pop_back();
		cout << "LinkedList is Ended!\n";
	}

	void Push_back(int data);
	void Pop_back();
	void PrintList();
};

int main()
{
	// 단일 연결 리스트

	/*NODE* node1 = new NODE{ 10, nullptr };
	NODE* node2 = new NODE{ 20, nullptr };
	NODE* node3 = new NODE{ 30, nullptr };

	node1->nextNode = node2;
	node2->nextNode = node3;

	NODE* curr = node1;
	while (curr != nullptr)
	{
		cout << curr->data;
		if (curr->nextNode != nullptr)
			cout << " -> ";

		curr = curr->nextNode;
	}

	delete node1;
	delete node2;
	delete node3;
	*/

	/*LinkedList LList;

	LList.Push_back(10);
	LList.Push_back(20);
	LList.Push_back(30);
	LList.Push_back(40);
	LList.Push_back(50);

	LList.PrintList();

	LList.Pop_back();
	LList.Pop_back();

	LList.PrintList();
	*/

	NODE* head = new NODE{ 0, nullptr };
	NODE* tail = head;

	AddNode(&tail, 10);
	AddNode(&tail, 20);
	AddNode(&tail, 30);
	AddNode(&tail, 40);
	AddNode(&tail, 50);

	PrintAll(head);

	delete head;
	return 0;
}

void LinkedList::Push_back(int data)
{
	NODE* newNode = MakeNode(data);

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nextNode = newNode;
		tail = newNode;
	}
}

void LinkedList::Pop_back()
{
	if (head == nullptr)
		return;

	if (head == tail)
	{
		DeleteNode(tail);
		head = tail = nullptr;
		return;
	}

	NODE* curr = head;
	while (curr->nextNode != tail)
		curr = curr->nextNode;

	DeleteNode(tail);
	tail = curr;
}

void LinkedList::PrintList()
{
	NODE* currNode = head;
	while (currNode != tail->nextNode)
	{
		cout << currNode->data;
		if (currNode != tail)
			cout << " -> ";
		currNode = currNode->nextNode;
	}
	cout << endl;
}
