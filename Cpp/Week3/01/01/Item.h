#pragma once
#include <iostream>
#include <memory>

// �� cpp ������ ��ŷ�������� ���� cpp ���ϰ� �������µ�
// ���ø��� �ڷ� Ÿ���� ������ �������� �����ǹǷ�
// �Լ��� ����� ����ο� �ٸ� �Լ��� �Ǿ������.
template<typename T>
inline void Search(T data)
{
	std::cout << data << std::endl;
}

class Item
{
public:
	std::weak_ptr<Item> ptr;

	// ���� �Լ�
	static void Upgrade();

	Item();
	Item(Item const& rhs);
	~Item();
};

static int itemCode(0);