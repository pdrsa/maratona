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
vector<ll> dp(1e7, -1);

int mini;

ll solve(ll k){
	if(k <= n) return a[k-1];
	if(dp[k] != -1) return dp[k];

	ll ans = LINF;
	for(ll j = 1; j <= k/2; j++) 
		ans = min(ans, solve(j) + solve(k - j));
	
	return dp[k] = ans;
}

void recover(ll k){
	if(k <= n){
		cout << "End: " << k << endl;
		return;
	}
	ll ans = LINF;

	int print = -1;
	for(int j = 1; j <= k/2; j++){
		if(solve(j) + solve(k-j) < ans){
			print = j;
			ans = solve(j) + solve(k - j);
		}
	}
	
	cout << k << ": Best is " << print << " and " << k-print << endl;
	recover(print);
	recover(k - print);
}

int32_t main(){ //_
	int q; cin >> n >> q;
	a.resize(n); for(ll &i: a) cin >> i;
	while(q--){
		ll k; cin >> k;
		cout << solve(k) << endl;
		//recover(k);
	}
	exit(0);
}
