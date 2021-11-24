//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 5e18;

int n;
vector<ll> a;
vector<ll> dp(10110, LINF);

int mini;

ll solve(ll k){
	if(k <= n) return a[k-1];
	if(k < 10110 and dp[k] != LINF) return dp[k];

	ll d = max(0LL, k - n*n);
	ll fAns = LINF;
	for(ll i = 1; i <= n; i++){
		ll e = d / i;
		ll gul = e * a[i-1];

		ll rem = k - (e*i);
		if(rem > n*n + n) assert("JOAO BURRO");
		fAns = min(fAns, solve(rem) + gul);
	}

	return fAns;
}

int32_t main(){ _
	int q; cin >> n >> q;
	a.resize(n); for(ll &i: a) cin >> i;
	
	for(int i = 1; i < n*n + n; i++){
		if(i <= n) dp[i] = a[i - 1];
		else{
			for(int j = 1; j <= i/2; j++)
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	
	while(q--){
		ll k; cin >> k;
		cout << solve(k) << endl;
	}
	exit(0);
}
