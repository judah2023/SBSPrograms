#pragma once
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
	virtual void Skill() abstract;

};

// vfptr : ���� �Լ� ������, ���� �Լ� ���̺�(vtable)�� value���� �Լ� �ּҸ� �޴� ������
// vtable�� ������ �� �����ȴ� ( �Լ��� �ڵ� ������ ����� ��, .rdata�� ���� )