#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

char buffer[10000];

void ReadTextFile(unsigned int speed, const char* fileName)
{
	FILE* readPtr = nullptr;
	fopen_s(&readPtr, fileName, "r");	// <-
	if (readPtr == nullptr)
	{
		printf("ERROR : Failed to open file!!!\n\n");
		return;
	}

	(void)fread(buffer, 1, 10000, readPtr);	// 파일 전체 읽기

	int i = 0;
	while (buffer[i] != '\0')
	{
		printf("%c", buffer[i++]);
		fflush(stdout);
		Sleep(speed * 10);
	}

	(void)fclose(readPtr);

	memset(buffer, 0, 10000);
}
