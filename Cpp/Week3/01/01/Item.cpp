#include "Item.h"

Item::Item()
{
	std::cout << "Item::Item() Constructor" << std::endl;
}

Item::Item(Item const& rhs)
{
}

Item::~Item()
{
	std::cout << "Item::~Item() Destructor" << std::endl;
}
