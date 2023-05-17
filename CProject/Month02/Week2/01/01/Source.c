#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>


int main()
{
#pragma region File_I/O

	/*
	FILE* filePtr = NULL;

	// fopen("파일의 이름.확장자", 파일모드)
	// fopen_s(파일 구조체 포인터의 주소, "파일의 이름.확장자", 파일모드)
	
	// 파일 모드
	// w : 쓰기
	// r : 읽기
	
	// 텍스트 파일을 (w)쓰기 모드로 열어준다
	errno_t err = fopen_s(&filePtr, "DB.txt", "w");
	if (err)
	{
		printf("ERROR : Failed to Open File!!!\n\n");
		return -1;
	}
	else
	{
		printf("=======Success to open file.=======\n");
	}

	fputs("ID : \n", filePtr);
	fputs("Password : \n", filePtr);

	// 파일 포인터 닫기
	fclose(filePtr);

	*/

	

	// 파일 읽기
	// fread(저장할 버퍼 주소, 한번에 읽어 들일 바이트 수, 총 읽어 들일 바이트 수, 파일 구조체 포인터)
	// fread_s(저장할 버퍼 주소, 버퍼의 크기, 한번에 읽어 들일 바이트 수, 총 읽어 들일 바이트 수, 파일 구조체 포인터)
	while (1)
	{
		FILE* readPtr = NULL;
		char buffer[100 * 100] = { 0 };

		errno_t err = fopen_s(&readPtr, "box.txt", "r");
		if (err)
		{
			printf("ERROR : Failed to Open File!!!\n\n");
			return -1;
		}
		else
		{
			printf("=======Success to open file.=======\n\n");
		}

		fread_s(buffer, 100 * 100, 1, 100 * 100, readPtr);
		printf("%s\n", buffer);

		fclose(readPtr);

		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
		Sleep(17);
		system("cls");
	}
	
#pragma endregion

	return 0;
}