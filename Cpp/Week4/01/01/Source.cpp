#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

#pragma region std::string

	/*
	
	string str(10, 'a');

	cout << "str : " << str << endl;

	str = "I can";

	cout << "str : " << str << endl;

	*/

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

#pragma endregion

	return 0;
}