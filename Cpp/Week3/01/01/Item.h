#pragma once
#include <iostream>
#include <memory>

class Item
{
public:
	std::weak_ptr<Item> ptr;

	Item();
	Item(Item const& rhs);
	~Item();
};

