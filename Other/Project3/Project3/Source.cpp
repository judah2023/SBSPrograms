#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, k;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector<int> nList(n);
	for (int i = 0; i < n; i++)
		nList[i] = i + 1;

	size_t idx = 0;
	cout << "<";
	for (int i = n; i > 1; i--)
	{
		idx += (k - 1);
		idx %= i;
		cout << nList[idx] << ", ";
		nList.erase(nList.begin() + idx);
	}
	cout << nList[0] << ">";

	return 0;
}