#pragma once
#include "Divice.h"

class Keyboard : virtual public Divice
{
private:
	char character;

public:
	Keyboard();

	void Input(char character);

	int price;
};

