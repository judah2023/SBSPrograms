#include <iostream>
using namespace std;

int main()
{
	char strings[5][16] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cin.getline(strings[i], 16);
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (strings[j][i] != '\0')
			{
				cout << strings[j][i];
			}
		}
	}
	
	return 0;
}

