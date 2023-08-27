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

ll calc(ll n, ll a, ll b){
    if(n <= a) return 1;
    n = n - a;
    return (n + (a-b-1)) / (a-b) + 1;
}

ll calc_max(ll n, ll a, ll b){
    if(n == 0) return 0;

    return (a-b) * (n-1) + a;
}

int32_t main(){ _
    int tt; cin >> tt;
    while(tt--){
        int q; cin >> q;
        ll l = 0, r = LINF;
        while(q--){
        int t; cin >> t;
        if(t == 1){
            ll a, b, n; cin >> a >> b >> n;
            
            ll nl = calc_max(n-1, a, b) + 1;
            ll nr = calc_max(n, a, b);

            if(nl > r or nr < l) cout << 0 << " ";
            else{
                cout << 1 << " ";
                l = max(l, nl);
                r = min(r, nr);
            }
        }
        else{
            ll a, b; cin >> a >> b;
            // cout << a << " " << b << " = " << calc(l, a, b) << " : " << calc(r, a, b) << endl;
            if(calc(l, a, b) == calc(r, a, b)) cout << calc(l, a, b) << " ";
            else cout << -1 << " ";
        }
        }
        cout << endl;
    }
    exit(0);
}
