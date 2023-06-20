#include "Computer.h"
#include <iostream>

Computer::Computer() : Mouse(), Keyboard()
{
	std::cout << "Computer 생성자 호출" << std::endl;
}
