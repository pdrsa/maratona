//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int n, m; cin >> n >> m;
    double c, p; cin >> c >> p;
    cout << fixed << setprecision(2);
    if(m * p >= c) cout << "0.00" << endl;
    else{
        double resto = (c - m*p);
        
        resto *= 100.0;
        resto = round(resto);
        resto /= 100.0;
        
        double pay = resto/(n-m);

        pay *= 100.0;
        pay =  round(pay);
        pay /= 100.0;

        if(pay * (n-m) < resto) cout << pay + 0.01 << endl;
        else cout << pay << endl;
        
    }
    exit(0);
}
