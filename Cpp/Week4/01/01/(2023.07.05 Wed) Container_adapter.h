#pragma once
#include <iostream>
#include <string>

#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main()
{
#pragma region Standard_STL

	/*

	// C++에서 사용 가능한 컨테이너 클래스와 알고리즘을
	// 일반화 시킨 자료구조를 포함하는 라이브러리

	// 선형 컨테이너
	// 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너
	// std::array, std::vector, std::list, std::deque

	// 연관 컨테이너
	//  키(Key)와 값(Value)처럼 관련있는 데이터를 하나의 쌍으로 저장하는 컨테이너
	// std::stack, std::queue

	// 컨테이너 어댑터
	// 기존 컨테이너의 인터페이스를 제한하여 만든 기능이 제한되거나 변형된 컨테이너
	// std::set, std::map

	*/

#pragma endregion

	// 컨테이너 어댑터 (Container Adapter)
	// 기존 컨테이너의 인터페이스를 제한하여 만든 기능이 제한되거나 변형된 컨테이너

#pragma region std::queue

	/*

	queue<int> stl_queue;
	stl_queue.push(10);
	stl_queue.push(20);
	stl_queue.push(30);
	stl_queue.push(40);
	stl_queue.push(50);


	while (!stl_queue.empty())
	{
		cout << stl_queue.front() << " ";

		// 컨테이너에 데이터가 없을 때 pop()을 할 경우
		// 런타임 에러가 발생
		stl_queue.pop();
	}
	cout << endl;

	*/

#pragma endregion

#pragma region std::stack

	/*

	stack<int> stl_stack;

	stl_stack.push(10);
	stl_stack.push(20);
	stl_stack.push(30);
	stl_stack.push(40);
	stl_stack.push(50);

	while (stl_stack.size())
	{
		cout << stl_stack.top() << " ";
		stl_stack.pop();
	}

	*/

#pragma endregion

#pragma region std::iterator

	/*

	vector<int> vec;
	vec.reserve(8);

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.insert(vec.end(), 35);
	vec.insert(vec.begin() + 2, 25);
	vec.insert(vec.begin() + 1, 15);
	vec.insert(vec.begin(), 5);
	vec.insert(vec.begin(), 0);

	vec.erase(vec.begin());

	for (auto it = vec.begin(); it != vec.cend(); it++)
	{
		cout << "vec[" << it - vec.begin() << "] : " << *it << "\n";
	}

	*/

#pragma endregion

	return 0;
}