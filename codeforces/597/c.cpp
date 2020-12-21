#include <bits/stdc++.h>

using namespace std;

#define BIG 1000000007

int main()
{
    string s;
    cin >> s;
    long long int countU = 0, countN = 0;
    long long int total = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'u')
        {
            if (s[i-1] == 'u')
                countU++;
        }
        else if (countU > 0)
        {

        }

    }
    

    return 0;
}