#pragma once
#include <deque>
template<typename T>
class MyStack2
{
private:
	std::deque<T> buffer;

public:
	MyStack2() = default;
	~MyStack2() = default;

	void Push(T&& data) { buffer.push_back(data); }
	void Pop() { buffer.pop_back(); }

	T& Top() { return buffer.back(); }

	size_t Size() { return buffer.size(); }

	bool Empty() { return buffer.empty(); }
};