#pragma once
#include <iostream>
#include <memory>

// 각 cpp 파일은 링킹과정에서 메인 cpp 파일과 합쳐지는데
// 템플릿의 자료 타입은 컴파일 과정에서 결정되므로
// 함수는 헤더의 선언부와 다른 함수가 되어버린다.
template<typename T>
inline void Search(T data)
{
	std::cout << data << std::endl;
}

class Item
{
public:
	std::weak_ptr<Item> ptr;

	// 정적 함수
	static void Upgrade();

	Item();
	Item(Item const& rhs);
	~Item();
};

static int itemCode(0);