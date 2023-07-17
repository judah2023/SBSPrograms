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
			throw std::out_of_range("\n������ ���� ���ֽ��ϴ�.");
			
		buffer[size++] = data;
	}

	void Pop() 
	{ 
		if (Empty())
			throw std::out_of_range("\n������ ����ֽ��ϴ�.");

		size--;
	}

	T& Top() 
	{ 
		if (Empty()) 
			throw std::out_of_range("\n������ ����ֽ��ϴ�.");
		
		return buffer[size - 1]; 
	}

	size_t Size() { return size; }

	bool Empty() { return size == 0; }
	bool IsFull() { return size == SIZE; }

};