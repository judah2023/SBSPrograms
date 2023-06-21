#include "Vector3.h"
#include <iostream>

Vector3::Vector3() : x(0), y(0), z(0) 
{
	std::cout << "Default Constructor" << std::endl;
}
Vector3::Vector3(int x, int y, int z) : x(x), y(y), z(z) 
{
	std::cout << "3-Parameters Constructor" << std::endl;
}

Vector3::Vector3(const Vector3& rhsVec)
{
	x = rhsVec.x;
	y = rhsVec.y;
	z = rhsVec.z;
	std::cout << "Copy Constructor" << std::endl;
}

Vector3 Vector3::operator+(const Vector3& rhsVec)
{
	return Vector3(
		x + rhsVec.x, 
		y + rhsVec.y, 
		z + rhsVec.z
	);
}

Vector3& Vector3::operator++()
{
	x++;
	y++;
	z++;
	return *this;
}

Vector3& Vector3::operator++(int)
{
	// TODO: insert return statement here
	x += 1;
	y += 1;
	z += 1;
	return *this;
}

void Vector3::Print()
{
	std::cout << "[ x, y, z ] = " << "[ " << x << ", " << y << ", " << z << " ]" << std::endl;
}

