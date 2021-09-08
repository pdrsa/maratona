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
const int MOD = 1e9+7;


int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, m, k, w; cin >> n >> m >> k >> w;
		vector<ll> ca(n); for(ll &i: ca) cin >> i;
		vector<ll> cb(m); for(ll &i: cb) cin >> i;

		
		vector<ll> pa(w+1), pb(w+1);
		pa[0] = 1, pb[0] = 1;

		for(int i = 0; i < n; i++)
			for(int j = w - ca[i]; j >= 0; j--)
				pa[j+ca[i]] = (pa[j + ca[i]] + pa[j]) % MOD;
		
		
		for(int i = 0; i < m; i++)
			for(int j = w - cb[i]; j >= 0; j--)
				pb[j+cb[i]] = (pb[j+cb[i]] + pb[j]) % MOD;
	
		ll ans = 0;

		for(int i = 0; i <= w; i++){
			if(abs(i - (w-i)) <= k)
				ans += (pa[i] * pb[w-i]) % MOD;

			ans %= MOD;
		}

		cout << ans % MOD << endl;
	}
	exit(0);
}
