#include <iostream>
#include <format>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define MAX_ITEM_LIFE 100
#define ARROW_UP 72
#define ARROW_DOWN 80
#define clear() system("cls")

// ������
class Item
{
	string name;	// �̸�
	int price;		// ����
	int life;		// ������

public:
	// �����ڴ� ���� public�̴�. ������ pivate�� �ִ�.
	Item(string name, int price)
	{
		this->name = name;
		this->price = price;
		life = MAX_ITEM_LIFE;
	}

	string ToString()
	{
		return format("�̸� : {}, ���� : {}	, ������ : {}", name, price, life);
		
	}
};

class Inventory
{
	enum {
		MAX_SLOT = 5,
	};
	Item* slots[MAX_SLOT];
	int currentIndex;

public:
	Inventory()
	{
		// Item������ �迭�̱� ������
		// Item�迭���� �ٸ��� ��ü�� ���ܳ��� �ʴ´�.
		// ���� ������ �迭�� ������������ �������� ���ٸ� ǥ���ϱ� ��ƴ�.
		for (int i = 0; i < MAX_SLOT; i++)
			slots[i] = nullptr;
		currentIndex = 0;
	}

	void AddItem(Item& item)
	{
		// slots�迭�� ��ȸ�ϸ鼭 ����ִ� ������ �߰��ϸ� �������� �����Ѵ�.Item item("������", 2000);
		for (int i = 0; i < MAX_SLOT; i++)
		{
			if (slots[i] == nullptr)
			{
				slots[i] = &item;
				break;
			}
		}
	}
	void ShowInventory()
	{
		clear();
		cout << "�κ��丮" << endl;
		for (int i = 0; i < MAX_SLOT; i++)
		{
			// slots[i]�� nullptr�� ��� ���ο� ������ �� ����.
			string cursor = (i == currentIndex) ? "��" : "��";
			string content = (slots[i] == nullptr) ? "" : slots[i]->ToString();
			cout << format("{}{}.{}", cursor, i + 1, content) << endl;
		}
	}
	Item* RemoveItem(int index)
	{
		if (slots[index] == nullptr)
		{
			return nullptr;
		}
		else
		{
			Item& item = *slots[index]; // ���Կ��� �����ϱ� ���� �̸� �ű��.
			slots[index] = nullptr;    // index��° ������ ����.
			return &item;				// �������� ��ȯ�Ѵ�.
		}
	}

	void OpenInventory()
	{
		// ��, �Ʒ� ����Ű�� ������ ������ �� �ִ�.
		// QŰ�� ������ �������� �����Ѵ�.
		currentIndex = 0;
		while (true)
		{
			ShowInventory();
			Input();
		}
	}
	void Input()
	{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				switch (c)
				{
				case ARROW_UP:
					if(currentIndex > 0)
						currentIndex -= 1;
					break;
				case ARROW_DOWN:
					if(currentIndex < MAX_SLOT -1)
						currentIndex += 1;
					break;
				}
			}
			else
			{
				switch (c)
				{
				case 'q':
				case 'Q':
					RemoveItem(currentIndex);
					break;
				}
			}


	}
};

int main()
{

	Item item("������", 2000);
	Inventory inven;
	inven.AddItem(item);
	inven.OpenInventory();
	return 0;
}