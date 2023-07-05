#pragma once
#include <iostream>

#include <string>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main()
{
#pragma region std::string

	/*

	string str(10, 'a');

	cout << "str : " << str << endl;

	str = "I can";

	cout << "str : " << str << endl;

	string str1(10, 'a');
	string name;

	cout << "before str1 : " << str1 << endl;
	getline(cin, str1);
	cout << "after str1 : " << str1 << endl;
	cout << endl;

	cout << "before name : " << name << endl;
	cin >> name;
	cout << "after name : " << name << endl;
	cout << endl;

	cout << "str1 : " << str1 << " \t name : " << name << endl;

	// 1. 띄워쓰기를 했을 대 출력이 이상하게 되는 부분 (이해하기)
	// 2. 이 문제점 해결하기

	*/

#pragma endregion

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