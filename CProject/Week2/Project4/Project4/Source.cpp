#include <iostream>
#include <format>

using namespace std;


// ��� : ��� Ŭ������ ��� Ŭ������ ��� ������ �����޴� ��.
// ��� Ŭ����(�θ� Ŭ����)
class Parent
{
public:
	int number;

	// �����Լ�
	// => ��� Ŭ�������� �ش� �Լ��� ������ �������� �� �ִ�.
	virtual void Say()
	{
		cout << format("number : {}", number) << endl;
	}
};

// ��� Ŭ����(�ڽ� Ŭ����)
class Child : public Parent
{
public:
	int score;


	// �θ��  ���� ������ ����, ����� �����ϸ�
	// �θ��� ����, ����� ��������.
	virtual void Say()
	{
		cout << format("number : {}, score : {}", number, score) << endl;
	}
};

class Animal
{
	// private : �ܺο� �������� �ʰڴ�.
	// protected : �ܺο��� �������� �ʴµ� ��� ���迡���� �����ϰڴ�.
protected:
	string name;

public:
	enum class FEED
	{
		Meat, // ���
		Leap, // Ǯ
	};

	void Feeding(FEED feed)
	{
		// static ���� ����
		// -> �ش� �Լ� �������� �����ϴ� ����. ���α׷� ���� �� ���� 1ȸ�� ����ȴ�.
		static const string feedStr[] = { "���", "Ǯ" };
		cout << name << "�� " << feedStr[(int)feed] << "�� �Խ��ϴ�." << endl;
	}
	
	// ���� ���� �Լ�
	// -> ��ӹ޴� Ŭ���������ؾ��ϴ� ���� �Լ�.

	void Feeding2(FEED feed)
	{
		static const string feedStr[] = { "���", "Ǯ" };
		if (IsEat(feed))
			cout << format("{}�� {}dmf �Խ��ϴ�.", name, feedStr[(int)feed]) << endl;
		else
			cout << format("{}�� {}dmf ���� �ʽ��ϴ�.", name, feedStr[(int)feed]) << endl;
	}

	virtual bool IsEat(FEED feed) = 0;
};

class Lion : public Animal
{
public:
	Lion(string name)
	{
		Animal::name = name;
	}
	virtual void Feeding(FEED feed)
	{
		if (feed == FEED::Leap)
			cout << name << "�� Ǯ�� ���� �ʽ��ϴ�." << endl;
		else
			Animal::Feeding(feed);  // �θ� Ŭ������ Feeding�� ȣ���϶�.
	}

	virtual bool IsEat(FEED feed)
	{
		return feed == FEED::Meat;
	}
};

class Bird : public Animal
{
public:
	Bird(string name) 
	{
		Animal::name = name;
	}
	virtual void Feeding(FEED feed)
	{
		if (feed == FEED::Meat)
			cout << name << "�� ��⸦ ���� �ʽ��ϴ�." << endl;
		else
			Animal::Feeding(feed);
	}
	virtual bool IsEat(FEED feed)
	{
		return feed == FEED::Leap;
	}
};


int main()
{
	if (false)
	{

	
	Parent parent;
	Child child;


	Parent* p = new Child();	 // ��� Ŭ������ ��� Ŭ���� ������ ������ �����ϴ�.
	// Child c = Parent();		 //�ݴ�� ��� Ŭ������ ��� Ŭ���� ������ ������ �Ұ����ϴ�.

	// p�� �ڷ����� Parent�̱� ������ Parent�� Say�� ȣ��Ǵ� ���̴�.
	// ������ �������̵��� �̿��ϸ� p�� ����Ű�� Child��ü�� Say�� ȣ��ȴ�.
	p->Say();
	}

	// ������ �����ϴ� ���α׷��̶�� �����غ���.
	/*
	Lion* lions[10];
	Bird* birds[10];

	lions[0] = new Lion();
	lions[1] = new Lion();
	*/

	Animal* animals[10];
	for (int i = 0; i < 10; i++)
		animals[i] = nullptr;
	animals[0] = new Lion("����");
	animals[1] = new Bird("��");


	for (int i = 0; i < 10; i++)
	{
		if (animals[i] != nullptr)
			animals[i]->Feeding(Animal::FEED::Leap);
	}

	// ���� ���� �Լ��� �����ϸ� �ش� Ŭ������ abstract Ŭ������ �ȴ�.
	// �� Ŭ������ �ܵ����� ������ �� ����.
	// �ֳ��ϸ� a�� ���� �ش� �Լ��� ȣ���ϸ� ��� ������ �� ���ΰ�?
	// Animal a;

	return 0;
}