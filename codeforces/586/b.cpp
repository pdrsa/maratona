#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    long long int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    long long int actual = 0;
    long long int ans[n];
    int ctlaco = 0;

    for (int i = 0; i < n; i++)
    {
        ctlaco = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (ctlaco == 0)
                    actual = matrix[i][j];
                else
                {
                    actual = __gcd(actual, matrix[i][j]);
                }
                ctlaco++;
            }
        }
        ans[i] = actual;
    }

    int cter = 0;
    int bla;
    long long int menor;

    for (int i = 0; i < n; i++)
    {
        cter = 0;
        menor = 1000000000;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                bla = (ans[i] * ans[j] / matrix[i][j]);
                if (bla < menor)
                    menor = bla;
            }
        }
        ans[i] = ans[i] / bla;
    }
     
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

   return 0;
}