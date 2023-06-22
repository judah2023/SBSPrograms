#include "Weapon.h"
#include <iostream>

void Weapon::Stat()
{
	std::cout << "무기 공격력 : " << attack << std::endl;
}

void Weapon::Attack()
{
	std::cout << "공격!" << std::endl;
}
