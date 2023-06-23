#include "Sword.h"
#include <iostream>

Sword::Sword()
{
	std::cout << "Sword() 생성" << std::endl;
}

Sword::~Sword()
{
	std::cout << "~Sword() 소멸" << std::endl;
}

void Sword::Stat()
{
	attack = 999;
	std::cout << "검 공격력 : " << attack << std::endl;
}

void Sword::Attack()
{
	std::cout << "베기" << std::endl;
}