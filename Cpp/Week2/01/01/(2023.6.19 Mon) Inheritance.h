#pragma once
#include <iostream>
#include "IPhone.h"

using namespace std;

#pragma region Inheritance

//

class Parent
{
public:
	Parent() : a(0), b(0), c(0)
	{
		cout << "Parent() 클래스 생성자" << endl;
	}

	~Parent()
	{
		cout << "~Parent() 클래스 소멸자" << endl;

	}

	void Speak(int a)	// 컴파일러가 자동으로 자기 자신의 주소(this)를 인자로 넣는다.
	{
		// this 포인터
		// 자기 자신을 가리키는 포인터
		this->a = a;

		// this 포인터는 호출된 객체를 가리키는 상수 포인터이다.

		// 상수 포인터 자료형이므로 포인터 자체가
		// 다른 것을 가리키도록 할 수 없다.

		cout << this << endl;
		cout << "Speak()" << endl;
	}

	int a;
protected:
	int b;
private:
	int c;
};

class Child : public Parent
{
public:
	Child() : d(0)
	{
		// pubilc 상속 시
		/*
		a = 1;	// (O)
		b = 2;	// (O)
		c = 3;	// (X)
		*/

		// protected 상속 시
		/*
		a = 1;	// (O)
		b = 2;	// (O)
		c = 3;	// (X)
		*/

		// private 상속 시
		/*
		a = 1;	// (O)
		b = 2;	// (O)
		c = 3;	// (X)
		*/

		cout << "Child() 클래스 생성자" << endl;
	}

	~Child()
	{
		cout << "~Child() 클래스 소멸자" << endl;
	}

	int d;
};

class GrandChild : private Child
{
public:
	GrandChild()
	{
		a = 1;
		b = 2;
		// c = 3;
	}
};

#pragma endregion

int main()
{
	// 상속
	/*

	Child child;

	// pubilc 상속 시
	// child.a = 999;	// (O)

	// protected 상속 시
	// 접근 할 수 있는 멤버 변수가 존재하지 않는다.
	// child.a = 999;	// (X)

	// private 상속 시
	// 접근 할 수 있는 멤버 변수가 존재하지 않는다.
	// child.a = 999;	// (X)

	*/

	// this 포인터
	/*
	Parent parent1;
	parent1.Speak(1);
	Parent parent2;
	parent2.Speak(2);
	Parent parent3;
	parent3.Speak(3);
	*/

	// super, child 클래스의 크기
	/*
	Parent p1;
	Child c1;

	cout << "Parent 사이즈의 크기 : " << sizeof(p1) << endl;
	cout << "Child 사이즈의 크기 : " << sizeof(c1) << endl;
	*/

	// 캡슐화(기본)
	/*
	IPhone iPhone14;

	iPhone14.SetVolume(104);
	cout << iPhone14.GetVolume() << endl;
	*/

	return 0;
}