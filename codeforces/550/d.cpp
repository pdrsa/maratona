#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int maior = 0, conta = 0, maxn;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    maxn = v[0];

    sort(v.begin(), v.end());
    

    for (int i = 0; i < n; i++)
    {
        if(v[i] == v[i+1])
        {
            conta++;
        }
        else
        {
            if(conta > maior)
            {
                maior = conta;
                conta = 0;
                maxn = v[i];
            }
        }
    }

    cout << (n-maior) << endl;

   return 0;
}