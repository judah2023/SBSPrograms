#include "Sword.h"
#include <iostream>

void Sword::Stat()
{
	attack = 999;
	std::cout << "검 공격력 : " << attack << std::endl;
}

void Sword::Attack()
{
	std::cout << "베기" << std::endl;
}

void LongS::Stat()
{
	attack = 9999;
	std::cout << "롱소드 공격력 : " << attack << std::endl;
}

void LongS::Attack()
{
	std::cout << "휘드르기" << std::endl;
}
