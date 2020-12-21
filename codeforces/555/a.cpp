#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long int n;
    cin >> n;
    long long int num = 10;
    if (n < 10)
    {
        cout << "9";
        return 0;
    }
    while (n >= 10)
    {
        num += 9 - (n%10);
        n = n / 10;
    }

    cout << num;


   return 0;
}