#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    cin >> z;
    for (; z > 0; z--)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a,b) == 1)
            cout << "finite\n";
        else
            cout << "infinite\n";
    }
    return 0;
}