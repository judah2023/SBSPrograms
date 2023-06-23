#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword();
	~Sword() override;
	virtual void Stat();
	void Attack();
};
