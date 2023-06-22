#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	virtual void Stat();
	void Attack();
};


class LongS : public Sword
{
public:
	virtual void Stat();
	void Attack();
};