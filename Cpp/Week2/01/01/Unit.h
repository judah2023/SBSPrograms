#pragma once
class Unit
{
private:
	int hp;
	// int attack;

public:
	// Unit();

	// 순수 가상 함수
	// 하위 클래스에서 재정의 할 것으로 기대하는 멤버 함수
	// ( 하위 클래스에서 구현을 할 책임이 생김 )
	virtual void Skill() abstract;

};

// vfptr : 가상 함수 포인터, 가상 함수 테이블(vtable)의 value값인 함수 주소를 받는 포인터
// vtable은 컴파일 시 생성된다 ( 함수가 코드 영역에 적재될 때, .rdata에 생성 )