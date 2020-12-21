#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main (void){
    ll a, b, f;
    cin >> a >> b;
    a = min(a, b);
    f = 1;
    for (int i = 1; i <= a; i++){
        f = f*i;
    }
    cout << f << endl;
    return 0;
}