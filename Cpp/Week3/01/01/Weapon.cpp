#include "Weapon.h"
#include <iostream>

Weapon::Weapon() 
	: attack(0), criticalHit(100.f), price(999), b(attack)
{
	std::cout << "Weapon() ����" << std::endl;
}

Weapon::Weapon(int attack, int price, float criticalHit)
	: attack(attack), criticalHit(criticalHit), price(price), b(attack)
{
	std::cout << "Weapon(int, int, float) ����" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "~Weapon() �Ҹ�" << std::endl;
}

void Weapon::Stat()
{
	std::cout << "���� ���ݷ� : " << attack << std::endl;
	std::cout << "���� ���� : " << price << std::endl;
	std::cout << "���� ġ�� Ȯ�� : " << criticalHit << std::endl;
}

void Weapon::Attack()
{
	std::cout << "����!" << std::endl;
}
