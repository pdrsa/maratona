#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r, menor = 0, maior = 0, multiplicador = 1;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        if (i > n-l)
        {
            multiplicador = multiplicador * 2;
        }
        
        menor += multiplicador;
    }

    multiplicador = 1;

    for (int i = 0; i < n; i++)
    {
        
        maior += multiplicador;
        
        if (r > 1)
        {
            r--;
            multiplicador = multiplicador * 2;
        }
    }

    cout << menor << " " << maior;
    
    return 0;
}