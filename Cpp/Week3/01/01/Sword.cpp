#include "Sword.h"
#include <iostream>

Sword::Sword()
{
	std::cout << "Sword() ����" << std::endl;
}

Sword::~Sword()
{
	std::cout << "~Sword() �Ҹ�" << std::endl;
}

void Sword::Stat()
{
	attack = 999;
	std::cout << "�� ���ݷ� : " << attack << std::endl;
}

void Sword::Attack()
{
	std::cout << "����" << std::endl;
}