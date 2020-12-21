#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 10000000000000005;
 
ll fexp(ll x, ll y) {
	ll r = x;
    for(ll i = 0; i < y; i++)
		r = r*x;
	return r;
}
 
int main() { _
    cout << fexp(2,3) << endl;
    ll val;
    vector<vector<ll>> v(61);
    FOR(i,3,61) {
        val = 0;
 
        int j = 1;
        while(val <= MAX) {
            val += fexp(j,i-1);
            if(val < (ll) 0 or val > MAX) {
                cout << "j: " << j << " val: " << val << endl;
                break;
            }
            v[i].pb(val);
            j++;
        }
 
        cout << i << ": " << v[i].back() << endl;
        //else cout << false << endl;
        //cout << j << endl;
    }
 
    ll x; cin >> x;
    ll d = -1, s = -1;
    FOR(i,3,61) {
        auto it = lower_bound(v[i].begin(), v[i].end(), x);
        if(*it == x) {
            d = i;
            s = (it-v[i].begin()) + 1;
            break;
        }
    }
 
    if(d == -1) cout << "impossible" << endl;
    else cout << d << " " << s << endl;
 
    return 0;
}
