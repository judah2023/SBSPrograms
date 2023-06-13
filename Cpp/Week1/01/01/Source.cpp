#include <iostream>

using namespace std;

int data = 56;

#pragma region Namespace

/*

// 속성을 구분할 수 있도록 유효 범위를 설정하는 영역

namespace A
{
	void Damage()
	{
		cout << "A::Damage() 호출" << endl;
	}
}

namespace B
{
	void Damage()
	{
		cout << "B::Damage() 호출" << endl;
	}
}

*/

#pragma endregion

#pragma region Class

/*

*/

// 사용자 정의 데이터 유형
// 속성과 함수가 포함됨
// 클래스를 통해 객체를 생성하여 접근하고 사용 할 수 있는 집합체

struct Monster
{
	// 여러개의 변수를 하나로 묶어 사용자 정의 자료형으로 사용
	// 원칙적으로 함수는 묶을수는 없음
};

class Player
{
	// 속성 -> 변수
	// 기능 -> 함수

public:
	Player() 
		: hp(100), mp(100), level(1), exp(0)
	{ 
		cout << "Player( " << this << " ) 실행" << endl; 
	}

	~Player() { cout << "~Player( " << this << " ) 실행" << endl; }

	void Attack()
	{
		cout << "공격!!!!" << endl;
	}

private:
	int hp;
	int mp;
	uint32_t level;
	uint32_t exp;
};

#pragma endregion

int main()
{
#pragma region Scope_Resolution_Operator

	/*
	
	// 여러 범위에서 사용되는 식별자를 구분하는데 사용하는 연산자

	// :: (범위 연산자)

	int data = 100;

	// 범위 지정 연산자는 전역변수와 같은 이름의 지역 변수가 선언되었을
	// 가장 가까운 범위에 선언된 변수의 이름을 사용하는 범위 규칙이 존재하므로
	// 전역변수가 호출되자 않는다.
	std::cout << "data의 값 : " << data << std::endl;
	std::cout << "::data의 값 : " << ::data << std::endl;

	*/

#pragma endregion

#pragma region auto

	/*
	
	// 선언된 변수의 초기화 식을 사용하여
	// 해당 형식을 추론하도록 컴파일러에게 지시하는 예약어

	// SDK 임포트 설치
	// API 함수()
	// PhotonManager(), PlayFab() 30 ~ 40 개

	auto decimal = 6.25;
	auto value = 100;

	// auto를 사용할 때 값을 넣어주어야 한다.
	// ex) auto b;
	decltype((value)) refValue = value;
	
	int nArr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		nArr[i] = i;
	}
	
	for (const auto &it : nArr)
	{
		cout << it << " ";
	}
	cout << endl;

	*/

#pragma endregion

	Player p1;
	Player* p2 = new Player();

	p2->Attack();

	delete p2;
	return 0;
}