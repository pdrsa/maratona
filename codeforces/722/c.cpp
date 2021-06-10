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
vector<vector<int>> g;
vector<vector<ll>> dp;
vector<ii> pv;

ll solve(int d, int i, int p){
	if(dp[d][i] != -1) return dp[d][i];
	
	ll a = 0;
	for(int u: g[i]){
		if(u == p) continue;

		if(d){
			a += max(abs(pv[i].s - pv[u].f) + solve(0, u, i),
			abs(pv[i].s - pv[u].s) + solve(1, u, i));
		}
		else{
			a += max(abs(pv[i].f - pv[u].f) + solve(0, u, i),
			abs(pv[i].f - pv[u].s) + solve(1, u, i));
		}
	}

	return dp[d][i] = a;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		dp = vector<vector<ll>> (2, vector<ll> (n, -1));
		g  = vector<vector<int>> (n);
		pv = vector<ii> (n);

		for(int i = 0; i < n; i++) cin >> pv[i].f >> pv[i].s;

		for(int i = 0; i < n-1; i++){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b); g[b].pb(a);
		}

		cout << max(solve(0, 0, 0), solve(1, 0, 0)) << endl;
	}

	exit(0);
}
