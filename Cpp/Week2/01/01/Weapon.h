#pragma once
class Weapon
{
protected:
	int attack;
public:
	Weapon();
	virtual ~Weapon();

	virtual void Stat();
	void Attack();
};

