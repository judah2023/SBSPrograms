#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword();
	~Sword();

	void Stat() override;
	void Attack() override;
};