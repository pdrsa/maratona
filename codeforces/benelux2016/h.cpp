//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

map<ll, ll> dp;

ll b;
ll maximumVal;

ll solve(ll k){
	if(k < b) return k;
	if(dp.count(k)) return dp[k];

	ll ans = LINF;
	for(ll i = 2; i <= k and i <= b; i++) if(k % i == 0){
		ll nextK  = k/i;
		ll nextDp = solve(nextK);
		if(nextDp > maximumVal) continue;

		ans = min(ans, solve(nextK) * b + i);
	}
	
	return dp[k] = ans;
}

int main(){ _
	ll n; cin >> b >> n;
	maximumVal = (1LL << 62)/b;
	cout << solve(n) << endl;

	exit(0);
}
