#include "Weapon.h"
#include <iostream>

Weapon::Weapon() : attack(0)
{
	std::cout << "Weapon() 생성" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "~Weapon() 소멸" << std::endl;
}

void Weapon::Stat()
{
	std::cout << "무기 공격력 : " << attack << std::endl;
}

void Weapon::Attack()
{
	std::cout << "공격!" << std::endl;
}
