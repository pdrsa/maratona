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

int n, k, x;
vector<vector<vector<ll>>> dp;
vector<ll> v;

ll solve(int i, int g, int prev){
	if(g == x and (n - (prev-1)) > k) return -LINF;

	if(i == n or g == x) return 0;
	if(dp[i][g][prev] != -1) return dp[i][g][prev];
	
	ll a = solve(i+1, g+1, i+1) + v[i];
	if(i - (prev-1) >= k) return dp[i][g][prev] = a;

	return dp[i][g][prev] = max(solve(i+1, g, prev), a);
}

int main(){ _
	cin >> n >> k >> x;

	v.resize(n); for(ll &i: v) cin >> i;
	dp.assign(n+10, vector<vector<ll>> (n+10, vector<ll> (n+10, -1)));

	ll ans = solve(0, 0, 0);

	cout << (ans < 0 ? -1 : ans) << endl;
	exit(0);
}
