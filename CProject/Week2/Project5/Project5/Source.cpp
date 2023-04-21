#include <iostream>
#include <format>

using namespace std;

struct Status
{
	int hp;			// 체력
	int power;		// 공격력
	int defence;	// 방어력
	float speed;	// 이동속도

	Status(int hp, int power, int defence, float speed)
	{
		this->hp = hp;
		this->power = power;
		this->speed = speed;
		this->defence = defence;
	}

	Status()
	{
		hp = 0;
		power = 0;
		defence = 0;
		speed = 0.0f;
	}
};

#pragma region 아이템

class Item
{
public:
	enum class TYPE
	{
		Equip,
		Useable,
		Material,
	};


protected:
	string name;
	string context;
	TYPE type;

	Item()
	{
		name = "";
		context = "";
		type = (TYPE)0;
	}
	Item(string name, string context, TYPE type)
	{
		this->name = name;
		this->context = context;
		this->type = type;
	}
public:
	virtual void UseItem()
	{

	}

	string GetName()
	{
		// 외부에서 name에 값을 대입할수는 없지만
		// 해당 함수를 통해 name을 값을 참조할 수는 있다.
		return name;
	}
};
class EquipItem : public Item
{
public:
	enum class KIND
	{
		HeadTree,
		UpperTree,
		BottomTree,
		ShoesTree,
		
	};

	enum class PART
	{
		Head,
		Upper,
		Bottom,
		Shoes,
		Count,
	};


	Status stat;
	KIND kine;
	PART part;

public:
	EquipItem(KIND kind)
	{
		this->kine = kine;
		this->part = (PART)0;

		switch (kind)
		{
		case KIND::HeadTree:
			name = "나무 모자";
			context = "나무로 만들어진 모자다.";
			stat = Status(3, 0, 1, 0);
			part = PART::Head;
			break;
		case KIND::UpperTree:
			name = "나무 갑옷";
			context = "나무로 만들어진 상의 갑옷이다.";
			stat = Status(10, 0, 3, 0);
			part = PART::Upper;
			break;
		case KIND::ShoesTree:
			name = "나무 신발";
			context = "나무로 만들어진 신발이다.";
			stat = Status(2, 0, 2, 1);
			part = PART::Shoes;
		}
	}

	// static 함수는 프로그램 시작시 메모리에 올라간다.
	// 그리고 클래스에 종속된다.
	PART GetPart()
	{

	}
};
class UseableItem : public Item
{
public:
	UseableItem(string name, string context) : Item(name, context, TYPE::Useable) { }
	virtual void UseItem()
	{

	}
};
class MaterialItem : public Item
{
	MaterialItem(string name, string context) : Item(name, context, TYPE::Material) { }
};

#pragma endregion



class Player
{
	#define PARTCOUNT (int)EquipItem::PART::Count
	Status status;
	EquipItem* equipSlots[PARTCOUNT];


public:
	Player(Status& status) : status(status)
	{
		for (int i = 0; i < PARTCOUNT; i++)
		{
			equipSlots[i] = nullptr;
		}
	}

	void Equip(EquipItem& equip)
	{
		int index = (int)equip.GetPart();
		if (equipSlots[index] != nullptr)
			cout << format("{}부위에는 이미 아이템이 있습니다.", (int)equip.GetPart()) << endl;
		else
		{
			cout << format("{}을 장비했습니다.", (int)equip.GetPart()) << endl;
			equipSlots[index] = &equip;
		}
	}
};

// 캐릭터
// - 스테이터스
// - 인벤토리
// - 장비 슬롯

// 아이템
//   = 이름, 설명
// - 장비아이템 (스테이터스)
//   = + 스텟 
// - 소비아이템 (사용 효과)
//   = + 효과
// - 재료아이템
//   = ;;



int main()
{
	// Item클래스는 기반 클래스다. 단 하나 있는 생성자가 protected로 보호 받기 때문에
	// 단일 객체로는 존재할 수가 없다.
	// Item* item = new Item()

	Item* inv[3];
	inv[0] = new EquipItem(EquipItem::KIND::HeadTree);
	inv[1] = new EquipItem(EquipItem::KIND::UpperTree);
	inv[2] = new EquipItem(EquipItem::KIND::ShoesTree);


	for (int i = 0; i < 3; i++)
	{
		cout << inv[i]->GetName() << endl;
	}


	return 0;
}