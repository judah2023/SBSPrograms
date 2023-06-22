#pragma once
#include <iostream>
#include "Vector3.h"

using namespace std;
#pragma region Polymorphism

/*

*/

// 여러 개의 서로 다른 객체가 동일한 기능을
// 서로 다른 방법으로 처리할 수 있는 기능

#pragma endregion

#pragma region Funcion_Overloading

/*

// 같은 이름의 함수를 매개변수의 자료형과 매개변수의 수로 구분하여
// 여러 개를 선언 할 수 있는 기능

template<typename T>
void Add(T x, T y)
{
	cout << x + y << endl;
}

void Add(int x, int y)
{
	cout << x + y << endl;
}

// 함수의 오버로딩의 경우
// 함수의 매개변수에 전달하는 인수의 형태를 보고 호출하므로
// 반환형으로 함수의 오버로딩을 생성할 수 없다.
// int Add(int x, int x) { return x + y; }	// (X)

void Add(double x, double y)
{
	cout << x + y << endl;
}

*/

#pragma endregion

int main()
{
	// 함수의 오버로딩
	/*
	Add(1, 2);
	Add(1.111, 2.2124);
	*/

	// 연산자 오버로딩
	/*
	Vector3 v1(2, 2, 2);
	Vector3 v2(1, 2, 3);
	v1.Print();
	v2.Print();
	cout << endl;

	Vector3 v3(v1 + v2);
	v1.Print();
	v2.Print();
	v3.Print();
	cout << endl;

	v1 = v2 + v3;
	v1.Print();
	v2.Print();
	v3.Print();
	cout << endl;


	Vector3 v4(1, 1, 1);
	((v4++)++).Print();
	v4.Print();
	*/

	return 0;
}

// 단항 연산자
// ++ --
// v4 = {1,1,1}
// ++(++v4) = 3,3,3