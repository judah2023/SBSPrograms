#include "Sword.h"
#include <iostream>

void Sword::Stat()
{
	attack = 999;
	std::cout << "�� ���ݷ� : " << attack << std::endl;
}

void Sword::Attack()
{
	std::cout << "����" << std::endl;
}

void LongS::Stat()
{
	attack = 9999;
	std::cout << "�ռҵ� ���ݷ� : " << attack << std::endl;
}

void LongS::Attack()
{
	std::cout << "�ֵ帣��" << std::endl;
}
