#include <iostream>
#include <algorithm>
using namespace std;

void SortList(int *list, int first, int last)
{
	if (first < last)
	{
		int i = -1;
		int pivot = last;
		for (int j = 0; j < pivot; j++)
		{
			if (list[j] < list[pivot])
				swap(list[++i], list[j]);
		}
		swap(list[++i], list[pivot]);

		SortList(list, first, i - 1);
		SortList(list, i + 1, last);
	}
}

int FindElement(int* list, int first, int last, int element)
{
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (element == list[mid])
		{
			return mid;
		}
		else
		{
			if (element < list[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int nList[100000];

int main()
{
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nList[i];

	SortList(nList, 0, n - 1);
	
	cin >> n;
	int idx;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		idx = FindElement(nList, 0, n - 1, input);
		if (idx == -1)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}

	return 0;
}