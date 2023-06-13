#pragma once
#include <iostream>

// C	( ��� : printf(), �Է� : scanf())
// C++	( ��� : std::cin, �Է� : std::cout)

// ��Ʈ��
// �ð��� �帧�� ���� ���������� �߻��ϴ� �������� �帧
// �ü���� ���� ��Ʈ���� ������

void Function(const int& x)
{
	std::cout << "x�� �� : " << x << std::endl;
}

int main()
{
#pragma region Cpp_I/O

	/*

	char a = 'A';
	int b = 100;
	float c = 9.81f;

	// ( << : ���� ������ )
	// �ڽ��� ������ ���� ��ȯ�ϴ� ������

	// std::endl : ����
	std::cout << (int)a << " " << b << " " << c << std::endl;

	int data = 0;
	int data1 = 0;

	// ( >> : ���� ������ )
	// ���ۿ� ������ ����
	// ������ ������ ũ�⸸ŭ ���� ���� ������ �����ϴ� ������
	// NULL ���ڱ����� ���� ���� ������ �����ϴ� ������ (���ڿ��� ���)
	std::cin >> data >> data1;

	std::cout << "data�� �� : " << data << std::endl;
	std::cout << "data1�� �� : " << data1 << std::endl;

	*/

#pragma endregion

#pragma region Cpp_Dynamic_allocation

	/*

	// C
	// �Ҵ� : malloc()
	// ���� : free()

	// C++
	// �Ҵ� : new
	// ���� : delete

	int* ptr = new int(0);

	// new ��ü �����ڸ� ȣ���Ѵ�.
	// Ÿ�� �˻縦 �ϱ� ������ �ٸ� Ÿ������ ����� �� ����.

	// malloc �����ڰ� ȣ����� �ʴ´�.
	// Ÿ�� �˻縦 ���� �ʴ´�.

	*ptr = 100;

	std::cout << *ptr << std::endl;
	std::cout << std::endl;

	delete ptr;

	ptr = new int[3] { 100, 200, 300 };
	for (int i = 0; i < 3; i++)
	{
		std::cout << ptr[i] << ' ';
	}
	std::cout << std::endl;
	delete[] ptr;

	*/

#pragma endregion

#pragma region Reference

	/*

	// � ������ �޸� ������ �� �ٸ� �̸�

	int value = 10;

	// ������ ����
	// & : ������ ���� ��ȣ
	int& other = value;
	int& other1 = value;

	std::cout << "value�� �� : " << value << std::endl;
	std::cout << "other�� �� : " << other << std::endl;

	other = 300;
	other1 = 25;
	Function(value);

	std::cout << "value�� �� : " << value << std::endl;
	std::cout << "other�� �� : " << other << std::endl;

	*/

#pragma endregion

	return 0;
}

// Socket ���
// Ŭ���̾�Ʈ�� ������ �ﰢ������ ���

// HTTP ���
// Ŭ���̾�Ʈ�� ������ ���� �ΰ� ���