#include "Weapon.h"
#include <iostream>

Weapon::Weapon() 
	: attack(0), criticalHit(100.f), price(999), b(attack)
{
	std::cout << "Weapon() 생성" << std::endl;
}

Weapon::Weapon(int attack, int price, float criticalHit)
	: attack(attack), criticalHit(criticalHit), price(price), b(attack)
{
	std::cout << "Weapon(int, int, float) 생성" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "~Weapon() 소멸" << std::endl;
}

void Weapon::Stat()
{
	std::cout << "무기 공격력 : " << attack << std::endl;
	std::cout << "무기 가격 : " << price << std::endl;
	std::cout << "무기 치명 확률 : " << criticalHit << std::endl;
}

void Weapon::Attack()
{
	std::cout << "공격!" << std::endl;
}
