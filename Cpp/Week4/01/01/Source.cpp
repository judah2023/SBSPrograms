#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <ctime>
#include <windows.h>

using namespace std;

enum COLORS
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKY_BLUE,
	DARK_RED,
	DARK_PURPLE,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKY_BLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
};

enum GameStatus
{
	G_FAILURE = -1,
	G_SUCCESS,
	G_NONE,

	MAX_LEVEL = 3,
	MAX_LIFE = 5,

	FRAME = 60
};

enum ArrowStatus
{
	AS_NONE = -1,
	AS_UP,
	AS_DOWN,
	AS_LEFT,
	AS_RIGHT
};

enum TableCode
{
	T_SIZE,
	T_EXP
};

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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
	array<array<int, MAX_LEVEL>, 2> table { 5, 7, 9, 250, 600, 1050 };
	vector<int> arrowList;
	
	int life = MAX_LIFE, level = 0, score = 0;
	int gameState, myArrow;

	size_t deltaTime = 1000 / FRAME; 
	double timer = 0;

	while (life && level < MAX_LEVEL)
	{
		for (int i = 0; i < table[T_SIZE][level]; i++)
			arrowList.push_back(rand() % 4);

		gameState = G_NONE;
		timer = 10 * FRAME;
		while (gameState == G_NONE)
		{
			system("cls");
			myArrow = AS_NONE;

			if (GetAsyncKeyState(VK_UP) & 0x0001)
			{
				myArrow = AS_UP;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x0001)
			{
				myArrow = AS_DOWN;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x0001)
			{
				myArrow = AS_LEFT;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
			{
				myArrow = AS_RIGHT;
			}


			cout << fixed;
			cout.precision(2);
			cout << "Level : " << level + 1 << "\t Time : " << timer / FRAME << endl;
			cout << "\nScore : " << score << "\t Life : " << life << endl;
			
			for (auto const& it : arrowList)
			{
				switch (it)
				{
				case 0:
					TextColor(RED);
					cout << "↑ ";
					break;
				case 1:
					TextColor(BLUE);
					cout << "↓ ";
					break;
				case 2:
					TextColor(YELLOW);
					cout << "← ";
					break;
				case 3:
					TextColor(GREEN);
					cout << "→ ";
					break;
				}
			}
			TextColor(WHITE);

			if (timer < 0)
			{
				gameState = G_FAILURE;
				cout << "\nTime Over...\n";
			}

			if (arrowList.empty())
			{
				gameState = G_SUCCESS;
				cout << "\nLine Clear!!!\n";
			}

			if (myArrow > AS_NONE)
			{
				if (arrowList.back() == myArrow)
					arrowList.pop_back();
				else
				{
					gameState = G_FAILURE;
					cout << "\nWrong...\n";
				}
			}


			Sleep(deltaTime);
			timer -= deltaTime / 2;
		}

		switch (gameState)
		{
		case G_FAILURE:
			life--;
			break;
		case G_SUCCESS:
			score += 10 * table[T_SIZE][level];
			break;
		default:
			break;
		}

		if (score >= table[T_EXP][level])
			level++;
		
		arrowList.clear();
		system("pause");
	}

	switch (gameState)
	{
	case G_FAILURE:
		cout << "GAME OVER...\n";
		cout << "\n Your Score : " << score << endl;
		break;
	case G_SUCCESS:
		cout << "GAME CLEAR!!! YOU ARE GENIUS!\n";
		cout << "\n Your Score : " << score << endl;
		break;
	default:
		break;
	}

#pragma endregion


#pragma region std::

	/*
	
	*/

#pragma endregion




}