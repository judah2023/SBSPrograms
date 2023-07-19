#pragma once
#include <vector>
template<typename Key, typename Value>
class UnorderedMap
{
	enum class State
	{
		NONE,
		VISITED,
		DELETED
	};

private:
	vector<pair<Key,Value>> container;
	vector<pair<Key, int>> hashKey;
	size_t size;
	size_t capacity;

	
public:

};

