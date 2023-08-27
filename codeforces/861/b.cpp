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
        int n, m; cin >> n >> m;
        vector<vector<ll>> cols(m);
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                int x; cin >> x;
                cols[i].pb(x);
            }
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            sort(cols[i].begin(), cols[i].end());
            ll s = 0;
            for(int j = 0; j < n; j++){
                ans += cols[i][j] * ll(j) - s;
                s += cols[i][j];
            }
        }
        cout << ans << endl;
	}
    exit(0);
}
