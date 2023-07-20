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
	std::vector<std::pair<Key,Value>> container;
	std::vector<State> stateList;
	size_t size;
	size_t capacity;

	size_t HashFunction(Key key)
	{
		return 0;
	}

public:
	UnorderedMap() : size(0), capacity(1024)
	{
		container.resize(capacity);
		stateList.resize(capacity, State::NONE);
	}

	~UnorderedMap() = default;

	void Insert(Key key, Value value)
	{
		if (size >= capacity / 2)
		{
			capacity <<= 1;
			container.resize(capacity);
			stateList.resize(capacity);
		}

		size_t idx = HashFunction(key);
		container[idx] = std::make_pair(key, value);
		stateList[idx] = State::VISITED;
		size++;
	}

	void Delete(Key key)
	{
		size_t idx = HashFunction(key);
		if (stateList[idx] == State::VISITED)
		{
			stateList[idx] = State::DELETED;
			size--;
		}
	}

	std::pair<Key, Value>* Find(Key key)
	{
		size_t idx = HashFunction(key);
		if (container[idx].first == key && stateList[idx] == State::VISITED)
			return (container.data() + idx);

		return nullptr;
	}

	Value& operator[](Key key)
	{
		size_t idx = HashFunction(key);
		if (stateList[idx] != State::VISITED)
			Insert(key, 0);

		return container[idx].second;
	}
};
