#pragma once
#include "Divice.h"

class Mouse : virtual public Divice
{
private:
	int sensity;

public:
	Mouse();
	~Mouse() = default;

	void OnDrag();
	
	int price;
};

