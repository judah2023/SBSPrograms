#include <iostream>
#include <algorithm>
using namespace std;

int arrA[1000001];

int main()
{
	int sizeN, sizeM, inputA;
	cin >> sizeN;
	for (int i = 0; i < sizeN; i++)
	{
		cin >> inputA;
		arrA[i] = inputA;
	}

	cin >> sizeM;
	for (int i = 0; i < sizeM; i++)
	{
		cin >> inputA;
	}



	return 0;
}