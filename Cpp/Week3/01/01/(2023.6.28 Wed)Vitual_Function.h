#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

#pragma region Template

/*

// �Լ��� Ŭ������ �ٽ� �ۼ����� �ʾƵ�
// ���� �ڷ������� ������ �� �ֵ��� �ϴ� ���

template <typename T>
void DataType(T value)
{
	cout << typeid(value).name() << " " << value << endl;
}

*/

#pragma endregion

#pragma region Specialization_Template

/*

// ���ø� �Լ��� ����ϸ鼭, Ư�� �ڷ����� ����
// �ٸ� �˰����� �����Ű�� ���� ���

template <typename T>
int DataSize(T data)
{
	return sizeof(data);
}

template<>
int DataSize(char const* data)
{
	return strlen(data) + 1;
}

*/

#pragma endregion

#pragma region Class_Template

/*

template <typename Key, typename Value>
class Dictionary
{
private:
	Key key;
	Value value;

public:
	Dictionary() = delete;
	Dictionary(Key key, Value value) : key(key), value(value) {}
	constexpr Key GetKey() const { return key; }
	constexpr Value GetValue() const { return value; }

	void ContainsKey() const
	{
		cout << key << endl;
	}

	void ContainsValue() const
	{
		cout << value << endl;
	}

	void PrintDictionary() const
	{
		cout << "[ " << key << ", " << value << " ]" << endl;
	}
};

*/

#pragma endregion

int main()
{
	// ���ø�
	/*
	DataType('A');
	DataType(10);
	DataType(10L);
	DataType(10LL);
	DataType(10U);
	DataType(10UL);
	DataType(10ULL);
	DataType(3.14f);
	DataType(4.75);
	*/

	// ���ø� Ư��ȭ
	/*
	int integer = 10;
	double decimal = 6.75;
	char const* content = "Hello World!!";

	cout << "integer size : " << DataSize(integer) << " Byte" << endl;
	cout << "decimal size : " << DataSize(decimal) << " Byte" << endl;
	cout << "content size : " << DataSize(content) << " Byte" << endl;
	*/

	// Ŭ���� ��Ǯ��
	/*
	Dictionary<char, int> dict1('A', 100);
	Dictionary<const char *, double> dict2("Table", 99.65);

	cout << "dict1 = ";
	dict1.PrintDictionary();
	cout << "dict2 = ";
	dict2.PrintDictionary();
	cout << endl;

	dict1.ContainsKey();
	dict1.ContainsValue();
	cout << endl;

	dict2.ContainsKey();
	dict2.ContainsValue();
	cout << endl;
	*/

	Item::Upgrade();
	Item::Upgrade();
	Item::Upgrade();

	return 0;
}