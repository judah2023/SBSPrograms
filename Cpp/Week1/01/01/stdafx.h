#pragma once

int globalValue;

// 전역 변수
// 전역 static 변수
void Init()
{
	static int score = 0;
	score++;
	globalValue = 10;

	std::cout << "score : " << score << std::endl;
}
