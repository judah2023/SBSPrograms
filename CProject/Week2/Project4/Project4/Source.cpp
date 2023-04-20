#include <iostream>
#include <format>

using namespace std;


// 상속 : 상속 클래스가 기반 클래스의 모든 내용을 물려받는 것.
// 기반 클래스(부모 클래스)
class Parent
{
public:
	int number;

	// 가상함수
	// => 상속 클래스에서 해당 함수의 내용을 재정의할 수 있다.
	virtual void Say()
	{
		cout << format("number : {}", number) << endl;
	}
};

// 상속 클래스(자식 클래스)
class Child : public Parent
{
public:
	int score;


	// 부모와  같은 형식의 변수, 상수를 선어하면
	// 부모의 변수, 상수가 가려진다.
	virtual void Say()
	{
		cout << format("number : {}, score : {}", number, score) << endl;
	}
};

class Animal
{
	// private : 외부에 공개하지 않겠다.
	// protected : 외부에는 공개하지 않는데 상속 관계에서는 공개하겠다.
protected:
	string name;

public:
	enum class FEED
	{
		Meat, // 고기
		Leap, // 풀
	};

	void Feeding(FEED feed)
	{
		// static 지역 변수
		// -> 해당 함수 내에서만 존재하는 변수. 프로그램 시작 시 최초 1회만 선언된다.
		static const string feedStr[] = { "고기", "풀" };
		cout << name << "가 " << feedStr[(int)feed] << "를 먹습니다." << endl;
	}
	
	// 순수 가상 함수
	// -> 상속받는 클래스구현해야하는 가상 함수.

	void Feeding2(FEED feed)
	{
		static const string feedStr[] = { "고기", "풀" };
		if (IsEat(feed))
			cout << format("{}가 {}dmf 먹습니다.", name, feedStr[(int)feed]) << endl;
		else
			cout << format("{}가 {}dmf 먹지 않습니다.", name, feedStr[(int)feed]) << endl;
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
			cout << name << "은 풀을 먹지 않습니다." << endl;
		else
			Animal::Feeding(feed);  // 부모 클래스의 Feeding을 호출하라.
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
			cout << name << "은 고기를 먹지 않습니다." << endl;
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


	Parent* p = new Child();	 // 기반 클래스는 상속 클래스 변수에 대입이 가능하다.
	// Child c = Parent();		 //반대로 상속 클래스는 기반 클래스 변수에 대입이 불가능하다.

	// p의 자료형은 Parent이기 때문에 Parent의 Say가 호출되는 것이다.
	// 하지만 오버라이딩을 이용하면 p가 가리키는 Child객체의 Say가 호출된다.
	p->Say();
	}

	// 동물을 관리하는 프로그램이라고 생각해보자.
	/*
	Lion* lions[10];
	Bird* birds[10];

	lions[0] = new Lion();
	lions[1] = new Lion();
	*/

	Animal* animals[10];
	for (int i = 0; i < 10; i++)
		animals[i] = nullptr;
	animals[0] = new Lion("사자");
	animals[1] = new Bird("새");


	for (int i = 0; i < 10; i++)
	{
		if (animals[i] != nullptr)
			animals[i]->Feeding(Animal::FEED::Leap);
	}

	// 순수 가상 함수를 포함하면 해당 클래스는 abstract 클래스가 된다.
	// 이 클래스는 단독으로 존재할 수 없다.
	// 왜냐하면 a를 통해 해당 함수를 호출하면 어떻게 실행이 될 것인가?
	// Animal a;

	return 0;
}