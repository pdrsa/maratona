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
    int t; cin >> t;
    while(t--){
	    ll n, c, d; cin >> n >> c >> d;
        vector<ll> a(n);
        for(ll &i: a) cin >> i;
        sort(a.begin(), a.end());
        ll ans = n * c + d;
        ll dupli = 0;
        int s = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1 and a[i] == a[i+1]){
                dupli++; continue;
            }
            ll cost = 0;
            // Duplicates
            cost += dupli * c;
            // Fill Gaps
            cost += (a[i] - 1 - s) * d;
            // Remove After
            cost += (n-i-1) * c;
            // Insert
            s++;
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
    exit(0);
}
