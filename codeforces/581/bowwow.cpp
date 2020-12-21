#include <bits/stdc++.h>

using namespace std;

int main()
{
    int counter = 0;
    int flag = -1;
    string time;
    cin >> time;

    for (int i = 0; i < time.length(); i++)
    {
        if (time[i] == '1')
        {
            flag = 0;
        }
    }

    cout << (time.length()/2) + flag;

    return 0;
}