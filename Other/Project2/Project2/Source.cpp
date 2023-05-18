#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int days = ceil((V - A) / (double)(A - B)) + 1;

	cout << days << endl;
	return 0;
}