#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int i, j, k;
	int gap = 0;

	cin >> N >> M;
	int* arr1 = new int[N];
	int* arr2 = new int[N] {0};

	for (int a = 0; a < N; a++)
	{
		arr1[a] = a + 1;
	}

	for (size_t b = 0; b < M; b++)
	{
		cin >> i >> j >> k;
		gap = k - i;

		int nextNumber;
		for (int c = i; c < j; c++)
		{
			nextNumber = c - gap;
			if (nextNumber < i)
			{
				nextNumber += (j - i);
			}
			arr2[nextNumber] = arr1[c];
		}

		for (int c = i; c < j; c++)
		{
			arr1[c] = arr2[c];
		}
	}

	for (int a = 0; a < N; a++)
	{
		cout << arr1[a] << " ";
	}
	
	delete[]arr1;
	delete[]arr2;
	return 0;
}

/*
10 5
1 6 4
3 9 8
2 10 5
1 3 3
2 6 2
1 4 6 2 3 7 10 5 8 9
*/