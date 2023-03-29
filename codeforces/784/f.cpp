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
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<ll> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];
        map<ll, ll> pref, suf;
        int pr = 0, su = 0;
        for(int i = 0; i < n; i++){
            pr += c[i];
            pref[pr] = i;
        }
        for(int i = n-1; i >= 0; i--){
            su += c[i];
            suf[su] = i;
        }

        ll ans = 0;
        for(auto [eat, pos]: pref)
            if(suf.count(eat))
                if(suf[eat] > pos)
                    ans = max(ans, pos + 1 + n - suf[eat]);
        cout << ans << endl;
    }
	exit(0);
}
