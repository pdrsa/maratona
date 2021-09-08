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
const int MOD = 1e9+7;

vector<ll> dp;

ll fib(ll x){
	if(x <= 1) return 1;
	if(dp[x] != -1) return dp[x];

	return dp[x] = (fib(x-1) + fib(x-2)) % MOD;
}

int main(){ _
	ll n; cin >> n;
	dp.assign(n+1, -1);
	int tt; cin >> tt;
	while(tt--){
		int t; cin >> t;
		cout << fib(t) << endl;
	}
	exit(0);
}
