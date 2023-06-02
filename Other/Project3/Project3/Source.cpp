#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    a = b = c = 1;
    while (a == 0 && a == b && b == c)
    {
        cin >> a >> b >> c;

        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);

        if (a * a + b * b == c * c)
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}