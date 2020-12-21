#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    int n;
    int menor = 101;
    ll total = 0;
    cin >> n;
    int meat[n][2];
    for (int i = 0; i < n; i++){
        cin >> meat[i][0] >> meat[i][1];
    }
    for (int i = 0; i < n; i++){
        if (meat[i][1] < menor)
            menor = meat[i][1];
        total = total + (meat[i][0] * menor);
    }

    cout << total;

   return 0;
}