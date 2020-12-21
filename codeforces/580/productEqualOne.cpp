#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, multTotal = 1;
    long long int coins = 0;

    cin >> n;
    
    int vn[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vn[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (vn[i] == 0)
        {
            coins += 1;
            multTotal = 0;
        }

        else if (vn[i] < 0)
        {
            coins += ((0 - vn[i]) - 1);
            vn[i] = -1;
            multTotal = multTotal * (-1);
        }

        else
        {
            coins += (vn[i] - 1);
            vn[i] = 1;
        }

    }

    if (multTotal == -1)
    {
        coins = coins + 2;
    }

    cout << coins;

    return 0;
}