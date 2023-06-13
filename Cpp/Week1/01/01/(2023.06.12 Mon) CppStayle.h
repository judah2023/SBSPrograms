#pragma once
#include <iostream>

// C	( 출력 : printf(), 입력 : scanf())
// C++	( 출력 : std::cin, 입력 : std::cout)

// 스트림
// 시간의 흐름에 따라 연속적으로 발생하는 데이터의 흐름
// 운영체제에 의해 스트림이 생성됨

void Function(const int& x)
{
	std::cout << "x의 값 : " << x << std::endl;
}

int main()
{
#pragma region Cpp_I/O

	/*

	char a = 'A';
	int b = 100;
	float c = 9.81f;

	// ( << : 삽입 연산자 )
	// 자신이 참조한 값을 반환하는 연산자

	// std::endl : 개행
	std::cout << (int)a << " " << b << " " << c << std::endl;

	int data = 0;
	int data1 = 0;

	// ( >> : 추출 연산자 )
	// 버퍼에 저장한 다음
	// 지정된 형식의 크기만큼 버퍼 안의 내용을 전달하는 연산자
	// NULL 문자까지만 버퍼 안의 내용을 전달하는 연산자 (문자열의 경우)
	std::cin >> data >> data1;

	std::cout << "data의 값 : " << data << std::endl;
	std::cout << "data1의 값 : " << data1 << std::endl;

	*/

#pragma endregion

#pragma region Cpp_Dynamic_allocation

	/*

	// C
	// 할당 : malloc()
	// 해제 : free()

	// C++
	// 할당 : new
	// 해제 : delete

	int* ptr = new int(0);

	// new 객체 생성자를 호출한다.
	// 타입 검사를 하기 때문에 다른 타입으로 사용할 수 없다.

	// malloc 생성자가 호출되지 않는다.
	// 타입 검사를 하지 않는다.

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

	// 어떤 변수의 메모리 공간의 또 다른 이름

	int value = 10;

	// 참조자 선언
	// & : 참조차 선언 기호
	int& other = value;
	int& other1 = value;

	std::cout << "value의 값 : " << value << std::endl;
	std::cout << "other의 값 : " << other << std::endl;

	other = 300;
	other1 = 25;
	Function(value);

	std::cout << "value의 값 : " << value << std::endl;
	std::cout << "other의 값 : " << other << std::endl;

	*/

#pragma endregion

	return 0;
}

// Socket 통신
// 클라이언트와 서버가 즉각적으로 통신

// HTTP 통신
// 클라이언트와 서버가 텀을 두고 통신