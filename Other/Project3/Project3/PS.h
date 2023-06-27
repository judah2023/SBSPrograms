#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string temp;
	while (true)
	{
		getline(cin, temp);
		bool isValid = true;
		stack<char> stackPS;

		for (const auto& pch : temp)
		{
			if (pch == '(' || pch == '[')
				stackPS.push(pch);
			else if (pch == ')')
				if (!stackPS.empty() && stackPS.top() == '(')
				{
					stackPS.pop();
				}
				else
				{
					isValid = false;
					break;
				}
			else if (pch == ']')
				if (!stackPS.empty() && stackPS.top() == '[')
				{
					stackPS.pop();
				}
				else
				{
					isValid = false;
					break;
				}
		}

		if (isValid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

/*
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.
*/