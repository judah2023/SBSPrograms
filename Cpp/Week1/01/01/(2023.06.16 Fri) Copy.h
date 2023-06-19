#pragma once
#include <iostream>

using namespace std;

#pragma region Copy

// 객체를 복사할 때, 참조 값이 아닌 인스턴스의 값을 복사하여
// 서로 다른 메모리를 생성하는 복사.

class GameObject
{
private:
	int size;
	int* data;
	static int deathCount;

public:
	GameObject()
	{
		size = 1;
		data = new int[size] {0};
	}

	GameObject(const int m_size)
	{
		size = m_size;
		data = new int[size] {0};
	}

	GameObject(const int m_size, const int* dataArr)
	{
		size = m_size;
		data = new int[size] {0};
		for (int i = 0; i < size; i++)
		{
			data[i] = dataArr[i];
		}
	}

	GameObject(const GameObject& rhs)
	{
		size = rhs.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rhs.data[i];
		}
		cout << "Deep Copy Completed!" << endl;
	}

	~GameObject()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
		deathCount++;
		cout << "\n오브젝트 소멸" << endl;
		cout << "deathCount : " << deathCount << endl;
	}

	void SetData(const int m_size, const int* dataArr)
	{
		if (m_size > size)
		{
			delete[] data;
			size = m_size;
			data = new int[size] {0};
		}

		for (int i = 0; i < m_size; i++)
		{
			data[i] = dataArr[i];
		}
	}

	void PrintObject()
	{
		cout << "\nsize : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "data[" << i << "] : " << data[i] << endl;
		}
	}
};

int GameObject::deathCount = 0;

#pragma endregion

int main()
{
#pragma region Shallow_Copy

	/*

	// 객체를 복사할 때 주솟값을 복사하여
	// 같은 메모리를 가리키는 복사

	int* ptr1 = new int;
	int* ptr2 = ptr1;

	// 얕은 복사는 같은 객체가 서로 같은 메모리 공간을 참조하고 있기 때문에
	// 하나의 객체로 값을 변경하게 되면 메모리 공간을 참조하는 객체도 함께 영향을 받는다.

	*ptr1 = 100;
	*ptr2 = 999;

	cout << "ptr1 = " << *ptr1 << endl;
	cout << "ptr2 = " << *ptr2 << endl;

	delete ptr1;
	// delete ptr2; // ERROR : 이미 해제된 메모리를 해제하려 함

	*/

#pragma endregion

#pragma region Deep_Copy

	/*

	int size = 3;
	int data[3] = { 1,2,3 };

	GameObject obj1;
	GameObject obj2 = obj1;

	obj2.SetData(3, data);
	obj2.PrintObject();

	*/

#pragma endregion

	GameObject obj1(3);
	GameObject obj2(3);
	GameObject obj3(3);
	GameObject obj4(3);

	return 0;
}