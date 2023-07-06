#pragma once
#include <iostream>
#include <string>

#include <map>
#include <set>

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

	// 연관 컨테이너 (Associate Container)
	// 키(Key)와 값(Value)처럼 관련있는 데이터를 하나의 쌍으로 저장하는 컨테이너

#pragma region std::map

	/*

	map<string, int> stl_map;
	stl_map.insert(pair<string, int>("Sword", 1000));
	stl_map["Shoes"] = 500;
	stl_map["Armor"] = 1500;
	stl_map["Zero"] = 0;

	for (auto it = stl_map.begin(); it != stl_map.end(); it++)
		cout << "[ Key : Value ] = [ " << it->first << " : " << it->second << " ]\n";
	cout << endl;

	string word("Shoes");
	cout << "Q : Is Exsisting Key?\n";
	cout << "A : " << (stl_map.find(word) != stl_map.end() ? "Yes" : "No") << endl;

	*/

#pragma endregion

#pragma region std::set

	/*

	set<int> stl_set;

	stl_set.insert(1);
	stl_set.insert(2);
	stl_set.insert(4);
	stl_set.insert(3);
	stl_set.insert(5);

	cout << "1." << endl;
	for (auto it = stl_set.begin(); it != stl_set.end(); it++)
		cout << *it << " ";
	cout << endl;

	stl_set.clear();

	cout << "2." << endl;
	for (auto& it : stl_set)
		cout << it << " ";
	cout << endl;

	*/

#pragma endregion

	return 0;
}