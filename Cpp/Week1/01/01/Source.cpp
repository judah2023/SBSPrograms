#include "Weapon.h"

using namespace std;

#pragma region Constructor

class Animal
{
	int age;

public:
	// 생성자
	// 클래스의 인스턴스가 생성되는 시점에서
	// 자동으로 호출되는 특수한 멤버 함수
	// 생성자는 함수 오버로딩이 가능

	// 생성자의 경우 객체가 생성될 때 단 한 번만 호출되며,
	// 생성자는 반환형이 존재하지 않는다.

	// 따라서, 생성자 호출 전에는
	// 객체에 대한 메모리는 할당되지 않는다.

	Animal() = default;

	Animal(int x) : age(x)
	{
		cout << "생성자 Animal(int) 호출" << endl;
	}

	// 복사 생성자
	// 같은 객체를 복사하여 생성시킬 대 호출되는 생성자
	Animal(const Animal& clone)
	{
		age = clone.age;
		cout << "복사 생성자 Animal(const Animal&) 호출" << endl;
	}

	// 소멸자
	// 객체가 소멸될 때 자동으로 실행되는 클래스의 멤버 함수
	// 소멸자는 함수 오버로딩이 불가능

	~Animal()
	{
		// 소멸자는 객체가 메모리에서 해제 될 때
		// 단 한번만 호출되며, 소멸자에는 매개변수를 생성하여 사용 할 수 없다.
		cout << "Animal() 소멸" << endl;
	}
};

#pragma endregion

#pragma region Default_Parameter

// 매개변수에 기본 값을 선언하여 함수가 호출될 때
// 인수 없이 호출될 수 있도록 설정하는 매개변수

void Damage(int x = 100)
{
	cout << "x의 값 : " << x << endl;
}

// 컴파일러는 매개 변수 위치를 유추하지 못하므로
// 기본 매개 변수를 선언 할 때 오른쪽에서 부터 정의한다.
void Calculator(int x, int y, int z = 300)
{
	cout << "x의 값 : " << x << endl;
	cout << "y의 값 : " << y << endl;
	cout << "z의 값 : " << z << endl;
}

#pragma endregion

int main()
{
#pragma region Constructor_main()

	Animal animal1;

	Animal animal2 = animal1;

	Weapon weapon;

	weapon.Stat();

	// 동적할당의 경우,
	// 프로그램이 종료되어도 메모리 할당이 해제되지 않으므로
	// 소멸자가 호출되지 않는다.
	Animal* aPtr = new Animal(15);

	// 따라서, 사용자는 동적할당한 객체를 해제할 책임이 생긴다.
	delete aPtr;

#pragma endregion

#pragma region Default_Parameter_main()
	
	/*
	
	Damage(999);
	Calculator(1, 2);

	*/

#pragma endregion

	return 0;
}