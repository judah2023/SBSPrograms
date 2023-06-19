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
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/