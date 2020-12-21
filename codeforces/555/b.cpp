#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long int n;
    long long int a;
    int f[9];
    vector <int> digi;
    cin >> n;
    cin >> a;
    for (int i = 0; i < 9; i++)
        cin >> f[i];
    while(a > 0)
    {
        digi.push_back(a%10);
        a = a / 10;
    }

    reverse(digi.begin(), digi.end());

    int changed = 0;
    int changedAgain = 1;
    for (int i = 0; i < digi.size(); i++)
    {
        if (changed == 1 and changedAgain == 0)
            break;
        if (digi[i] < f[(digi[i])-1])
        {
            digi[i] = f[(digi[i])-1];
            changed = 1;
        }
        else
        {
            if (digi[i] != f[(digi[i])-1])
            {
                if (changed == 1)
                    changedAgain = 0;
            }
        }
    }

    for (int i = 0; i < digi.size(); i++)
        cout << digi[i];

    cout << endl;

   return 0;
}