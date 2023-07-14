#pragma once
template<typename T>
class MyVector
{
private:
	T* container;
	size_t size;
	size_t capacity;
public:
	MyVector() : container(nullptr), size(0), capacity(0) {};
	explicit MyVector(size_t const size) : container(new T[size]), size(size), capacity(size) {};
	MyVector(MyVector<T> const& copy);
	~MyVector()
	{
		if (container != nullptr)
			delete[] container;
	}

	T& operator[](int idx)
	{
		return container[idx];
	}

	T& at(int idx)
	{
		try
		{
			if (idx < 0 || idx >= size)
				throw std::out_of_range("OUT OF RANGE!");

			return container[idx];
		}
		catch (const std::exception& error)
		{
			std::cout << "MyVector<" << typeid(T).name() << "> ERROR : " << error.what() << std::endl;
		}
	}

	T Front() { return container[0]; }
	T Back() { return container[size - 1]; }

	size_t Size() { return size; }
	size_t Capacity() { return capacity; }

	void Clear() { size = 0; }

	void PushBack(T const& data);
	void PopBack();

};

#include "MyVector.hpp"
template<typename T>
inline MyVector<T>::MyVector(MyVector<T> const& copy) : container(new T[copy.capacity]), size(copy.size), capacity(copy.capacity)
{
	for (size_t i = 0; i < copy.size; i++)
		container[i] = copy.container[i];
}

template<typename T>
inline void MyVector<T>::PushBack(T const& data)
{
	if (size == capacity)
	{
		size_t newCapacity = (size_t)(capacity * 1.5 >= 2 ? capacity * 1.5 : capacity + 1);

		T* newContainer = new T[newCapacity];
		for (size_t i = 0; i < size; i++)
			newContainer[i] = container[i];

		delete[] container;
		container = newContainer;
		capacity = newCapacity;
	}

	container[size++] = data;
}

template<typename T>
inline void MyVector<T>::PopBack()
{
	if (size > 0)
		size--;
}
