#pragma once
#include <iostream>

class Unit
{
private:
	int hp;
	// int attack;

public:
	// Unit();

	// ���� ���� �Լ�
	// ���� Ŭ�������� ������ �� ������ ����ϴ� ��� �Լ�
	// ( ���� Ŭ�������� ������ �� å���� ���� )
	virtual void SetHP(int const& hp);
	virtual int GetHP() const;
	virtual void Skill() abstract;

};

// vfptr : ���� �Լ� ������, ���� �Լ� ���̺�(vtable)�� value���� �Լ� �ּҸ� �޴� ������
// vtable�� ������ �� �����ȴ� ( �Լ��� �ڵ� ������ ����� ��, .rdata�� ���� )