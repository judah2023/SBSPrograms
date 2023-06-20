#include <iostream>
#include "Computer.h"

using namespace std;

int value = 50;

int main()
{
#pragma region Multiple_Inheritance

	// 하나의 하위 클래스가 여러 개의 상위 클래스를 상속받는 것
	// C++(O)	C#(X)

	Computer computer;

	// 다중 상속은 여러개의 상위 클래스에 중복되는 속성이
	// 존재할 수 있기 때문에 범위 지정 연산자를 통해서
	// 상위 클래스의 이름을 선언하고 속성을 사용해야 합니다.

	computer.Keyboard::price = 10000;

	computer.OnDrag();
	computer.Input('A');

#pragma endregion

	return 0;
}