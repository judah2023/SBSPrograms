#pragma once
class Vector3
{
private:
	int x, y, z;	// 3-Dimensional Coordinate
public:
	Vector3();
	Vector3(int x, int y, int z);
	Vector3(const Vector3& rhsVec);

	Vector3 operator+(const Vector3& rhsVec);
	Vector3& operator++();
	Vector3& operator++(int);

	void Print();
};

