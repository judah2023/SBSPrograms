#pragma once
class Weapon
{
protected:
	int attack;
	const int price;
	int& b;
	float criticalHit;
public:
	Weapon();
	Weapon(int attack, int price, float criticalHit);
	virtual ~Weapon();

	virtual void Stat();
	virtual void Attack();
};

