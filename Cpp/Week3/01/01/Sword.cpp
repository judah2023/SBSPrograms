#include "Sword.h"
#include <iostream>

Sword::Sword() : Weapon(100, 1'000, 3.75f)
{
	std::cout << "Sword() ����" << std::endl;
}

Sword::~Sword()
{
	std::cout << "~Sword() �Ҹ�" << std::endl;
}

void Sword::Stat()
{
	std::cout << "�� ���ݷ� : " << attack << std::endl;
	std::cout << "�� ���� : " << price << std::endl;
	std::cout << "�� ġ�� Ȯ�� : " << criticalHit << "\%" << std::endl;
}

void Sword::Attack()
{
	std::cout << "����" << std::endl;
}