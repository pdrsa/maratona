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

ll dp[2020][2020];
vector<bool> r(2020);
vector<ll> u(2020, INF);
int destino;

ll solve(int i, int p){
	if(dp[i][p] != -1) return dp[i][p];
	if(i == destino) return 0;

	ll a = LINF, b = LINF, c = LINF;

	if(!r[i])     a = solve(i+1, 2010) + 0;
	if(p != 2010) b = solve(i+1, p) + u[p];
	if(u[i] != INF and (p==2010 or u[i] < u[p])) c = solve(i+1, i) + u[i];

	return dp[i][p] = min({a,b,c});
}

int main(){ _
	int n, m; cin >> destino >> n >> m;
	while(n--){
		int a, b; cin >> a >> b;
		for(int i = a; i < b; i++) r[i] = true;
	}
	
	while(m--){
		int x, p; cin >> x >> p;
		if(p < u[x]) u[x] = p;
	}
	
	memset(dp, -1, sizeof dp);
	ll ans = solve(0,2010);
	cout << (ans == LINF ? -1 : ans) << endl;
	exit(0);
}
