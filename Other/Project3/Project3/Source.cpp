#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> listPS;
	string temp;
	while (getline(cin, temp))
	{
		if (temp == "")
			break;

		listPS.push_back(temp);
	}

	int cntSmall, cntBig;
	for (const auto &it: listPS)
	{
		cntSmall = cntBig = 0;
		for (const auto& pch : it)
		{
			if (pch == '(')
				++cntSmall;
			else if (pch == '[')
				++cntBig;
			else if (pch == ')')
				if (cntSmall > 0)
				{
					--cntSmall;
				}
				else
				{
					cntSmall = -1;
					break;
				}
			else if (pch == ']')
				if (cntBig > 0)
				{
					--cntBig;
				}
				else
				{
					cntBig = -1;
					break;
				}
		}
		
		if (cntSmall == 0 && cntBig == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}