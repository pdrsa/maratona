#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, par = 0, impar = 0;
    cin >> n;
    int chips[n];
    for (int i = 0; i < n; i++)
    {
        cin >> chips[i];
        
        if (chips[i] % 2 == 0)
        {
            par++;
        }
        
        else
        {
            impar++;
        }
    }

    if (par > impar)
    {
        cout << impar;
    }
    else
    {
        cout << par;
    }
    

    return 0;
}