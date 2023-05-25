#include <stdio.h>
#include <string.h>

int StrLength(const char * string)
{
	int cnt = -1;
	while (string[++cnt] != '\0');

	return cnt;
}

int main()
{
#pragma region String_Functions
	// strlen : 문자열 길이 함수

	// strcpy : 문자열 복사 함수

	// strcat : 문자열 연결 함수
	char content1[20] = { "Hello" };
	char spacing[2] = " ";
	char content2[10] = { "Update" };

	printf("strlen(content1) : %llu\n", strlen(content1));
	printf("StrLength(content1) : %d\n", StrLength(content1));

	strcat_s(content1, spacing);
	strcat_s(content1, content2);

	printf("%s\n", content1);




#pragma endregion

	return 0;
}