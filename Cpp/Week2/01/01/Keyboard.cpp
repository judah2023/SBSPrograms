#include "Keyboard.h"
#include <iostream>

Keyboard::Keyboard() : character('\0')
{
	std::cout << "Keyboard ������ ȣ��" << std::endl;
}

void Keyboard::Input(char character)
{
	this->character = character;
	std::cout << "Keyboard Input : " << character << std::endl;
}
