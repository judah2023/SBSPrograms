#include "Sword.h"
#include <iostream>

Sword::Sword() : Weapon(100, 1'000, 3.75f)
{
	std::cout << "Sword() 생성" << std::endl;
}

Sword::~Sword()
{
	std::cout << "~Sword() 소멸" << std::endl;
}

void Sword::Stat()
{
	std::cout << "검 공격력 : " << attack << std::endl;
	std::cout << "검 가격 : " << price << std::endl;
	std::cout << "검 치명 확률 : " << criticalHit << "\%" << std::endl;
}

void Sword::Attack()
{
	std::cout << "베기" << std::endl;
}