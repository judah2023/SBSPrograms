#include <stdio.h>

void main()
{
#pragma region FormatSpecifier
	/*
	char	cCharacter	= 'B';
	int		nData		= 100;
	float	fDecimal	= 9.95111111111111111111f;

	// 출력하기 위한 자료형의 정보를
	// 명시적으로 지정해주는 것입니다.

	// printf(nData);	(X)
	
	// "%c"	: 문자 (char		형)
	// "%d"	: 정수 (int		형)
	// "%f"	: 실수 (float	형)

	// 서식과 변수의 형태가 일치하지 않으면
	// 원하는 값이 출력되지 않습니다. (형식 지정자마다 데이터의 해석방법이 다름)
	// printf("character의 값 : %f\n", cCharacter); (X)

	// float 형은 소수점 이하 6자리까지만 표기함
	// (유효 자리수가 6자리까지이다.)

	// 서식 지정자의 순서는 왼쪽에서부터 시작


	printf("character의 값	: %c\n", cCharacter);
	printf("data의 값		: %d\n", nData);
	printf("decimal의 값		: %f\n\n", fDecimal);

	printf("data : %d, decimal : %f\n", nData, fDecimal);
	*/
#pragma endregion

#pragma region Bit
	// 데이터를 나타내는 최소의 단위이며, 
	// 0 또는 1의 조합으로 논리 계산을 수행하는 단위입니다.

	// bit가 8개 모이면 1 Byte가 된다.

	// 비트 연산자
	// 비트 단위로 논리 연산을 수행하기 위해 사용하는 연산자
	char num1 = 10;		// 0000 1010
	char num2 = 15;		// 0000 1111
	char num3 = 128;	// 1111 1111

	// AND(&) 
	// 두개의 피연산자(1비트) 모두 1 이면 1 을 반환하는 연산자.
	printf("num1 AND num2		= %04d\n", num1 & num2);
	
	// OR(|) 
	// 두개의 피연산자(1비트) 모두 0 이면 0 을 반환하는 연산자.
	printf("num1 OR  num2		= %04d\n", num1 | num2);
	
	// XOR(^)
	// 두개의 피연산자(1비트) 값이 다르면 1 을 반환하는 연산자.
	printf("num1 XOR num2		= %04d\n", num1 ^ num2);

	// NOT(~)
	// 비트를 반전 시키는 연산자 (0->1,	1->0)
	printf("NOT num1, NOT num2	= %04d, %04d\n", ~num1, ~num2);

	// 첫 번째(혹은 마지막) 비트는 부호를 나타내며, 
	// 첫 번째 비트에 1이 있다면 값은 음수가 됩니다.
	printf("num3의 값 : %d\n", num3);

#pragma endregion

}

// 네트워크 photon network playfab