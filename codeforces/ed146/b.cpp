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

int32_t main(){ //_
    int tt; cin >> tt;
    while(tt--){
        ll a, b; cin >> a >> b;

        ll best = LINF;
        for(ll p = 1; p*p < 2 * (a + b) + 1000; p++){
            ll cost = p - 1;
            cost += (a/p) + (b/p);
            if(a % p != 0) cost++;
            if(b % p != 0) cost++;
            best = min(best, cost);
        }
        cout << best << endl;
    }
	exit(0);
}
