#include <iostream>

using namespace std;

#pragma region Class

/*

// 사용자 정의 데이터 유형
// 속성과 함수가 포함됨
// 클래스를 통해 객체를 생성하여 접근하고 사용 할 수 있는 집합체

struct Monster
{
	// 여러개의 변수를 하나로 묶어 사용자 정의 자료형으로 사용
	// 원칙적으로 함수는 묶을수는 없음
};

class Player
{
	// 속성 -> 변수
	// 기능 -> 함수

	// 접근 제한자
	// 클래스 내부의 포함되어 있는 속성에
	// 제한 범위를 설정하는 지정자

	// 공개 (public)
	// 어디서든지 접근할 수 있는 접근 제한자
public:
	Player()
	: hp(100), data(0), name(""), transformX(0)
	{
		std::cout << "Player() 실행" << std::endl;
	}

	~Player() { cout << "~Player() 실행" << endl; }

	void Information()
	{
		std::cout << "캐릭터 정보" << std::endl;
	}

	void Attack()
	{
		std::cout << "공격!!!!" << std::endl;
	}

	const char* name;
	int data;

	// 비공개 (private)
	// 클래스 내부에서만 속성에 접근 할 수 있게 만드는 제한자
	// 접근 제한자를 설정하지 않으면 private로 설정됨
private:
	int hp;

	// 보호 (protected)
	// 클래스 내부와 상속된 클래스 내부에서만 속성에 접근 할 수 있게 만드는 제한자
protected:
	float transformX;
};

class Job : public Player
{
public:
	void Select()
	{
		transformX = 100.0f;
	}
};

*/

#pragma endregion

int main()
{
	//Player player1;
	//Player player2;
	//Player player3;

	// // player.hp = 10;
	//player1.data = 0x12345678;

	//player1.name = "Bard";
	//player1.Information();

	// std::cout << "player1의 크기 : " << sizeof(player1) << std::endl;
	// std::cout << "player2의 크기 : " << sizeof(player2) << std::endl;
	// std::cout << "player3의 크기 : " << sizeof(player3) << std::endl;

	// Player* ptrPlayer = new Player();
	
	// ptrPlayer->data = 63;
	// ptrPlayer->Information();
	
	// delete ptrPlayer;
	// ptrPlayer = nullptr;
	
	// if (ptrPlayer == nullptr)
	// {
	// 	cout << "메모리가 해제되었습니다." << endl;
	// 	ptrPlayer = new Player();
	// }
	
	return 0;
}