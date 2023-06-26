#include <iostream>
#include "Marine.h"
#include "Ghost.h"

using namespace std;

void Recovery(Unit * unit)
{
	unit->SetHP(200);
}

int main()
{
	// 업 캐스팅
	Marine marine;
	Ghost ghost;

	// Unit* uPtr = &marine;
	// uPtr->Skill();

	// uPtr = &ghost;
	// uPtr->Skill();
	cout << "마린의 현재 체력 : " << marine.GetHP() << endl;
	cout << "고스트의 현재 체력 : " << ghost.GetHP() << endl;

	cout << "========Before========" << endl;
	Recovery(&marine);
	Recovery(&ghost);
	cout << "========After ========" << endl;

	cout << "마린의 현재 체력 : " << marine.GetHP() << endl;
	cout << "고스트의 현재 체력 : " << ghost.GetHP() << endl;

	return 0;
}