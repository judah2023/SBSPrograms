#include "Item.h"

void Item::Upgrade()
{
	int x = 0;
	std::cout << "Upgrade! : " << itemCode++ << std::endl;
}

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
