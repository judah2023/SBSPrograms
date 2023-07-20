#pragma once
#include <iostream>
template<typename Key>
class MyQueue
{
	enum Constants { SIZE = 100 };

private:
	Key* buffer;
	size_t front;
	size_t rear;


public:
	MyQueue() :
		buffer(new Key[SIZE]),
		front(0),
		rear(0)
	{}
	~MyQueue() { delete[] buffer; }

	inline void Push(Key&& data)
	{
		if (IsFull())
			throw std::out_of_range("\n스택이 가득 차있습니다.");

		buffer[rear++] = data;
	}

	void Pop()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		front++;
	}

	Key& Front()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		return buffer[front];
	}

	Key& Back()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		return buffer[rear - 1];
	}

	size_t Size() { return rear - front; }

	bool Empty() { return rear == front; }
	bool IsFull() { return rear - front == SIZE; }

};