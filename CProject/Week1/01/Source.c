#include <stdio.h>

void main()
{
#pragma region Quadrant
	int x = 5, y = 5;

	if (y != 0 && x > 0)
	{
		if (y > 0)
		{
			printf("1사분면\n");
		}
		else
		{
			printf("4사분면\n");
		}
	}
	else if (y != 0 && x < 0)
	{
		
		if (y > 0)
		{
			printf("2사분면\n");
		}
		else
		{
			printf("3사분면\n");
		}
	}
	else
	{
		if (x != 0)
		{
			printf("x축\n");
		}
		else if (y != 0)
		{
			printf("y축\n");
		}
		else
		{
			printf("원점\n");
		}
	}
#pragma endregion

}

// 네트워크 photon network, playfab