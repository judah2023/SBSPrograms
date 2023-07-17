#pragma once
#include <iostream>
template<typename T>
class MyStack
{
	enum Constants { SIZE = 100 };

private:
	T* buffer;
	size_t size;

public:
	MyStack() : 
		buffer(new T[SIZE]), 
		size(0) 
	{}
	~MyStack() { delete[] buffer; }

	inline void Push(T&& data) 
	{ 
		if (IsFull())
			throw std::out_of_range("\n스택이 가득 차있습니다.");
			
		buffer[size++] = data;
	}

	void Pop() 
	{ 
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		size--;
	}

	T& Top() 
	{ 
		if (Empty()) 
			throw std::out_of_range("\n스택이 비어있습니다.");
		
		return buffer[size - 1]; 
	}

	size_t Size() { return size; }

	bool Empty() { return size == 0; }
	bool IsFull() { return size == SIZE; }

};