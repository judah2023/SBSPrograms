#include "Weapon.h"
#include <iostream>

void Weapon::Stat()
{
	std::cout << "���� ���ݷ� : " << attack << std::endl;
}

void Weapon::Attack()
{
	std::cout << "����!" << std::endl;
}
