#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, temp;
	string word;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<int> nQueue(n + 1);
	size_t front = -1, back = -1;
	nQueue[n] = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		if (word == "push")
		{
			cin >> temp;
			nQueue[++back % n] = temp;
		}
		else if (word == "pop")
		{
			if (front == back)
				temp = nQueue[n];
			else
				temp = nQueue[++front % n];
			cout << temp << "\n";
		}
		else if (word == "size")
		{
			cout << (back - front) % n << "\n";
		}
		else if (word == "empty")
		{
			cout << (front == back) << "\n";
		}
		else if (word == "front")
		{
			if (front == back)
				temp = nQueue[n];
			else
				temp = nQueue[(front + 1) % n];
			cout << temp << "\n";
		}
		else if (word == "back")
		{
			if (front == back)
				temp = nQueue[n];
			else
				temp = nQueue[back];
			cout << temp << "\n";
		}
	}

	return 0;
}

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/