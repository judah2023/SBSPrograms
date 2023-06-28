#pragma once
#include <iostream>
#include <memory>

#include "Item.h"

using namespace std;

int main()
{
#pragma region Smart_Pointer

	/*

	// 포인터처럼 동작하는 클래스 탬플릿으로
	// 사용이 끝난 메모리를 자동으로 해제시켜준다
	cout << "0" << endl;

	// unique_ptr
	// 메모리 공간을 하나의 포인터만 가리킬 수 있는 포인터
	{
		unique_ptr<int> uSPtr1(new int(5));
		cout << *uSPtr1 << endl;
		*uSPtr1 = 300;
		cout << *uSPtr1 << endl;

		// unique_ptr이 가지고 있던 메모리 소유권을 넘겨주는 과정
		// 단, std::move 함수는 어디까지나 인자를 r-value 참조 타임으로 만들어 반환하는 함수이다.
		unique_ptr<int> uSPtr2(std::move(uSPtr1));

		// std::move() 함수로 객체에 대한 소유권을 이전 할 수 있지만,
		// 객체를 이전한 유니크 포인터는 아무것도 가리킬 수 없으며, 소멸한 포인터로 처리된다.
		cout << *uSPtr2 << endl;
		*uSPtr2 = 10;
		cout << *uSPtr2 << endl;
	}
	cout << "scope1" << endl;

	// shared_ptr
	// 어떤 하나의 객체를 참조하는 스마트 포인터의 개수를 참조하는 포인터

	// 참조하고 있는 스마트 포인터의 수를 참조 카운트라고 한다.

	// 참조 카운트(Reference Counting)
	// 해당 메모리를 참조하는 포인터가 몇 개가 있는지 나타내는 값
	// 참조 카운트가 0이 되면 해당 메모리 공간이 해제된다.
	{
		shared_ptr<int> shSPtr0(new int(999));
		shared_ptr<Item> shSPtr1 = make_shared<Item>();

		cout << "shSPtr1.use_count() ; " << shSPtr1.use_count() << endl;
		{
			shared_ptr<Item> shSPtr2 = shSPtr1;
			cout << "shSPtr1.use_count() ; " << shSPtr1.use_count() << endl;
		}
		cout << "shSPtr1.use_count() ; " << shSPtr1.use_count() << endl;
		cout << "sizeof(shSPtr1) ; " << sizeof(shSPtr1) << endl;
	}
	cout << "scope2" << endl;

	// weak_ptr
	// 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공하지만,
	// 참조 카운트에 포함되지 않는 스마트 포인터
	{
		shared_ptr<Item> ptr1(new Item);
		cout << "ptr1.use_count() : " << ptr1.use_count() << endl;
		cout << "ptr1->ptr.use_count() : " << ptr1->ptr.use_count() << endl;
		cout << endl;

		{
			shared_ptr<Item> ptr2(new Item);

			ptr1->ptr = ptr2;
			ptr2->ptr = ptr1;

			cout << "ptr1.use_count() : " << ptr1.use_count() << endl;
			cout << "ptr2.use_count() : " << ptr2.use_count() << endl;
			cout << "ptr1->ptr.use_count() : " << ptr1->ptr.use_count() << endl;
			cout << "ptr2->ptr.use_count() : " << ptr2->ptr.use_count() << endl;
			cout << endl;
		}

		cout << "ptr1.use_count() : " << ptr1.use_count() << endl;
		cout << "ptr1->ptr.use_count() : " << ptr1->ptr.use_count() << endl;
	}
	cout << "scope3" << endl;


	*/

#pragma endregion

	return 0;
}s