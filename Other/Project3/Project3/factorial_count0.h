#pragma once
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, cnt = 0;
    cin >> n;
    while (n % 5 == 0)
    {
        n /= 5;
        cnt += n;
    }
    cout << cnt << "\n";
    return 0;
}

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, cnt;
    cin >> n;
    for (int i = 5; i <= n; i+= 5)
    {
        temp = i;
        cnt = 0;
        while (temp % 5 == 0)
        {
            cnt++;
            temp /= 5;
        }
    }
    cout << cnt << "\n";
    return 0;
}
*/