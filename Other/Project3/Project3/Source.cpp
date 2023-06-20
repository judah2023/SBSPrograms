#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nCount[10001] = { 0 };

    int n, temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ++nCount[temp];
    }

    for (int i = 0; i < 10001; i++)
        for (int j = 0; j < nCount[i]; j++)
            cout << i << "\n";
    
    return 0;
}