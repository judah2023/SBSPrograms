#include <iostream>
#include <format>

using namespace std;

struct Status
{
	int hp;			// ü��
	int power;		// ���ݷ�
	int defence;	// ����
	float speed;	// �̵��ӵ�

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

#pragma region ������

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
		// �ܺο��� name�� ���� �����Ҽ��� ������
		// �ش� �Լ��� ���� name�� ���� ������ ���� �ִ�.
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
			name = "���� ����";
			context = "������ ������� ���ڴ�.";
			stat = Status(3, 0, 1, 0);
			part = PART::Head;
			break;
		case KIND::UpperTree:
			name = "���� ����";
			context = "������ ������� ���� �����̴�.";
			stat = Status(10, 0, 3, 0);
			part = PART::Upper;
			break;
		case KIND::ShoesTree:
			name = "���� �Ź�";
			context = "������ ������� �Ź��̴�.";
			stat = Status(2, 0, 2, 1);
			part = PART::Shoes;
		}
	}

	// static �Լ��� ���α׷� ���۽� �޸𸮿� �ö󰣴�.
	// �׸��� Ŭ������ ���ӵȴ�.
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
			cout << format("{}�������� �̹� �������� �ֽ��ϴ�.", (int)equip.GetPart()) << endl;
		else
		{
			cout << format("{}�� ����߽��ϴ�.", (int)equip.GetPart()) << endl;
			equipSlots[index] = &equip;
		}
	}
};

// ĳ����
// - �������ͽ�
// - �κ��丮
// - ��� ����

// ������
//   = �̸�, ����
// - �������� (�������ͽ�)
//   = + ���� 
// - �Һ������ (��� ȿ��)
//   = + ȿ��
// - ��������
//   = ;;



int main()
{
	// ItemŬ������ ��� Ŭ������. �� �ϳ� �ִ� �����ڰ� protected�� ��ȣ �ޱ� ������
	// ���� ��ü�δ� ������ ���� ����.
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