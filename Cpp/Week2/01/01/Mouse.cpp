#include "Mouse.h"
#include <iostream>

Mouse::Mouse() : sensity(10)
{
	std::cout << "Mouse 생성자 호출" << std::endl;
}

void Mouse::OnDrag()
{
	std::cout << "Mouse Drag" << std::endl;
}
