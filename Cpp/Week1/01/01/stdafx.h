#pragma once

int globalValue;

// ���� ����
// ���� static ����
void Init()
{
	static int score = 0;
	score++;
	globalValue = 10;

	std::cout << "score : " << score << std::endl;
}
