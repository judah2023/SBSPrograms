#include <iostream>

using namespace std;

unsigned bags[5001] = { -1, -1, -1, 1, -1, 1, 0 };

unsigned getBagAmount(int n)
{
    if (bags[n] != 0)
        return bags[n];

    auto l = getBagAmount(n - 3);
    auto r = getBagAmount(n - 5);

    if (l == r && r == -1)
    {
        bags[n] = -1;
    }
    else
    {
        if (l < r)
            bags[n] = l + 1;
        else
            bags[n] = r + 1;
    }

    return bags[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp = -1;

    cin >> n;
    cout << (int)getBagAmount(n) << endl;

    return 0;
}