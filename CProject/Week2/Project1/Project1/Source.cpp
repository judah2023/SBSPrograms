#include <iostream>
#include <format>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define MAX_ITEM_LIFE 100
#define ARROW_UP 72
#define ARROW_DOWN 80
#define clear() system("cls")

// 아이템
class Item
{
	string name;	// 이름
	int price;		// 가격
	int life;		// 내구도

public:
	// 생성자는 보통 public이다. 하지만 pivate도 있다.
	Item(string name, int price)
	{
		this->name = name;
		this->price = price;
		life = MAX_ITEM_LIFE;
	}

	string ToString()
	{
		return format("이름 : {}, 가격 : {}	, 내구도 : {}", name, price, life);
		
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
		// Item포인터 배열이기 때문에
		// Item배열과는 다르게 객체가 생겨나지 않는다.
		// 또한 아이템 배열로 가지고있으면 아이템이 없다를 표현하기 어렵다.
		for (int i = 0; i < MAX_SLOT; i++)
			slots[i] = nullptr;
		currentIndex = 0;
	}

	void AddItem(Item& item)
	{
		// slots배열을 순회하면서 비어있는 슬롯을 발견하면 아이템을 대입한다.Item item("나무검", 2000);
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
		cout << "인벤토리" << endl;
		for (int i = 0; i < MAX_SLOT; i++)
		{
			// slots[i]가 nullptr일 경우 내부에 접근할 수 없다.
			string cursor = (i == currentIndex) ? "▶" : "　";
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
			Item& item = *slots[index]; // 슬롯에서 삭제하기 전에 미리 옮긴다.
			slots[index] = nullptr;    // index번째 슬롯을 비운다.
			return &item;				// 아이템을 반환한다.
		}
	}

	void OpenInventory()
	{
		// 위, 아래 방향키로 슬롯을 선택할 수 있다.
		// Q키를 누르면 아이템을 제거한다.
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

	Item item("나무검", 2000);
	Inventory inven;
	inven.AddItem(item);
	inven.OpenInventory();
	return 0;
}