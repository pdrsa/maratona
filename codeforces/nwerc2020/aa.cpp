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
int n;
vector<ll> a;
vector<ll> dp(400, -1);

int mini;

ll solve(ll k){
	if(k <= n) return a[k-1];
	if(k < 400 and dp[k] != -1) return dp[k];
	ll d = max(0LL, k - 2*n);
	
	if(k < 400){
		ll ans = LINF;
		for(int j = 1; j <= k/2; j++)
			ans = min(ans, solve(j) + solve(k - j));
		return dp[k] = ans;
	}

	ll fAns = LINF;
	for(int i = 1; i <= n; i++){
		ll e = d / i;
		ll gul = e * a[i-1];
		ll rem = k - (e*i);
		ll ans = LINF;
		
		if(dp[rem] != -1) ans = dp[rem];
		else ans = solve(rem);
		fAns = min(fAns, ans + gul);
	}

	if(k < 400) dp[k] = fAns;
	return fAns;
}

int32_t main(){ _
	int q; cin >> n >> q;
	a.resize(n); for(ll &i: a) cin >> i;
	while(q--){
		ll k; cin >> k;
		cout << solve(k) << endl;
	}
	exit(0);
}
