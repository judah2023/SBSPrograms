#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
#pragma region Standard_STL

	/*
	
	// C++에서 사용 가능한 컨테이너 클래스와 알고리즘을
	// 일반화 시킨 자료구조를 포함하는 라이브러리

	// 선형 컨테이너
	// std::array, std::vector, std::deque

	// 연관 컨테이너
	// std::stack, std::queue

	// 컨테이너 어댑터
	// std::set, std::map, std::list

	*/

#pragma endregion

#pragma region std::array

	/*
	
	array<int, 10> stl_array {1, 2, 3, 4, 5, 6};

	stl_array[0] = 10;
	cout << "STLArray's size : " << stl_array.size() << endl;

	*/

#pragma endregion

#pragma region std::vector

	/*
	
	vector<int> stl_vector;

	stl_vector.push_back(10);
	stl_vector.push_back(20);
	stl_vector.push_back(30);
	stl_vector.push_back(40);
	stl_vector.push_back(50);
	stl_vector.push_back(60);
	stl_vector.push_back(70);

	stl_vector.pop_back();
	stl_vector.pop_back();
	stl_vector.pop_back();
	stl_vector.pop_back();
	stl_vector.pop_back();

	cout << "stl_vector's capacity : " << stl_vector.capacity() << endl;
	cout << "stl_vector's size : " << stl_vector.size() << endl;

	for (auto const& it : stl_vector)
		cout << it << " ";
	cout << endl;

	*/
	
#pragma endregion

#pragma region Ex)Simple_Rythm_Game

	/*
	
	*/

	// 1. 랜덤으로 화살표가 주어진다. (5개 > 7개 > 9개)
	// 2. Life : 3개 정도
	// 3. 키 입력을 하면 화면에 표시
	// 4. 키가 맞으면 성공 (라이프 유지, 점수 상승)
	// 5. 틀리면 실패 (라이프 감소)
	size_t size[3] = { 5,7,9 };
	vector<int> arrowList;
	int life = 3, level = 1, score = 0;
	int gameState, myArrow = 5;

	while (life)
	{
		for (int i = 0; i < size[level - 1]; i++)
			arrowList.push_back(rand() % 4);

		gameState = 1;
		while (gameState > 0)
		{
			myArrow = 5;

			cout << "Level : " << level << "\t Score : " << score << endl;
			for (auto const& it : arrowList)
			{
				switch (it)
				{
				case 0:
					cout << "↑ ";
					break;
				case 1:
					cout << "↓ ";
					break;
				case 2:
					cout << "← ";
					break;
				case 3:
					cout << "→ ";
					break;
				}
			}

			if (GetAsyncKeyState(VK_UP) & 0x8001)
				myArrow = 0;
			if (GetAsyncKeyState(VK_DOWN) & 0x8001)
				myArrow = 1;
			if (GetAsyncKeyState(VK_LEFT) & 0x8001)
				myArrow = 2;
			if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
				myArrow = 3;

			if (myArrow < 5)
			{
				if (arrowList.back() == myArrow)
					arrowList.pop_back();
				else
					gameState = -1;

				if (arrowList.empty())
					gameState = 0;
			}
			system("cls");
		}

		switch (gameState)
		{
		case -1:
			life--;
			break;
		case 0:
			score += 10;
			break;
		default:
			break;
		}

		arrowList.clear();
		system("pause");
	}


#pragma endregion


#pragma region std::

	/*
	
	*/

#pragma endregion




}