#pragma once

#include <iostream>

using namespace std;

int main()
{
	int nInput;
	cin >> nInput;
	for (int i = 1 - nInput; i < nInput; i++)
	{
		int spaceCount;
		if (i < 0)	spaceCount = -1 * i;
		else		spaceCount = i;

		for (size_t j = 0; j < 2 * nInput - spaceCount - 1; j++)
		{
			if (j < spaceCount)	cout << " ";
			else				cout << "*";
		}
		cout << endl;
	}

	return 0;
}