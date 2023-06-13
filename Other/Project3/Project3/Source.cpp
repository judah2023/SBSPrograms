#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> nList;
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		nList.push(i + 1);

	int i = 0, temp;
	while (nList.size() > 1 && ++i > 0)
	{
		temp = nList.front();
		nList.pop();
		if (i % 2 == 0)
			nList.push(temp);
	}

	cout << nList.front() << endl;
	return 0;
}