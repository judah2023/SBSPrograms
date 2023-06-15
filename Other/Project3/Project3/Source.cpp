#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<string> listPS(n);
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		listPS[i] = temp;
	}

	int cnt;
	for (const auto &it: listPS)
	{
		cnt = 0;
		for (const auto& pch : it)
		{
			if (pch == '(')
				++cnt;
			else if (pch == ')')
				if (cnt > 0)
				{
					--cnt;
				}
				else
				{
					cnt = -1;
					break;
				}
		}
		
		if (cnt == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}