#pragma once


#pragma region VariableRule
	// 1. ���� ����� �� ����.
	// int int = 100;			(X)
	//
	// 2. ���ڷ� ������ �� ����.
	// int hp1 = 100;			(O)
	// int 1hp = 100;			(X)
	//
	// 3. ��ҹ��ڸ� �����Ѵ�.
	// int attack = 26;
	// int Attack = 27;
	// printf("%d %d", attack, Attack);		// OUTPUT : 26 27
	//
	// 4. ������ ���Ե� �� ����.
	// int count Down = 200;	(X)
	// int countDown = 200;	(O)
	// int count_down = 200;	(O)
	//
	// 5. Ư����ȣ�� $, _ �� ��밡���ϴ�.
	//int $any = 100;			(O)
	//int _any = 200;			(O)
#pragma endregion

#pragma region InitVariable
	// ���ʷ� ������ ���� �������ִ� �����Դϴ�.
	// unsigned int exp = 100;	// ������ ����

#pragma endregion

#pragma region Literal
	// ���α׷��� ����Ǵ� ���� 
	// �� �̻� ���� ������ �� ���� �޸� ����
	// const int literalInt = 0;
	// const float pi = 3.141592f;
	// pi = 6.29184; ����� ����Ǿ��� ������ ������ �� �����ϴ�.

	// �ɺ��� ��� : �޸� ������ ������ �ִ� ���
	// ���ͷ� ��� : �޸� ������ ������ ���� ���� ���
#pragma endregion
