#include "Sword.h"

using namespace std;

int main()
{

#pragma region Funcion_Override

	/*

	// 상위 클래스에 있는 함수를
	// 하위 클래스에 재정의 하여 사용하는 기능

	// 함수의 오버라이드는 상속 관계에서만 이루어지며,
	// 하위 클래스에서 함수를 재정의 할 때 상위 클래스의
	// 함수 형태와 일치해야 한다.
	Weapon weapon;
	weapon.Attack();

	Sword sword;
	sword.Attack();

	// 바인딩	( 정적 바인딩, 동적 바인딩 )
	// 프로그램의 어떤 기본 단위가 가질 수 있는 구성 요소의
	// 구체적인 값을 결정하는 것

	// 정적 바인딩 : 컴파일 시점에 결정되는 것
	// 동적 바인딩 : 런타임 시점에 결정되는 것
	weapon = sword;
	weapon.Attack();

	*/

#pragma endregion

#pragma region Vitual_Function

	/*
	
	*/

	// 상속하는 클래스 내에서 같은 형태의 함수로
	// 재정의 될 수 있는 함수

	Weapon *ptr = new Sword;

	// 가상 함수의 경우 가상 함수 테이블을 사용하여 호출되는 함수를 실행 시간에 결정하며,
	// 정적으로 선언된 함수는 가상 함수로 선언 할 수 있다.

	ptr->Stat();
	ptr->Attack();

	delete ptr;

	// 가상 함수 실행 시간에 상위 클래스에 대한 참조로
	// 하위 클래스에 재정의된 함수를 호출할 수 있으며,
	// 접근 지정자는 공개로 설정해야 한다.

#pragma endregion


	return 0;
}