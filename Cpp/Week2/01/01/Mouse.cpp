#include "Mouse.h"
#include <iostream>

Mouse::Mouse() : sensity(10)
{
	std::cout << "Mouse ������ ȣ��" << std::endl;
}

void Mouse::OnDrag()
{
	std::cout << "Mouse Drag" << std::endl;
}
