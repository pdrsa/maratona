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
const int MAX = 4020;

map<int, vector<int>> g, give, receive;

map<int, bool> v;
map<int, int> obli;

void dfs(int x){
	v[x] = true;
	for(int u: g[x]) if(!v[u]) dfs(u);
}

int32_t main(){ _
	int n, m; cin >> n >> m;

	int ans = INF;
	for(int i = 1; i <= n; i++) obli[i] = 0;

	// Make Graph
	while(m--){
		int a, b; cin >> a >> b;
		g[-a].pb(b); g[-b].pb(a);
		if(a < 0 and b < 0) ans = 2;
		if(a == b){
			if(a < 0){
				ans = min(ans, 1);

				if(obli[a] == 1) ans = 0;
				else obli[a] = -1;
			} else{
				if(obli[a] == -1) ans = 0;
				else obli[a] = 1;
			}
		}
	}
	
	// Compact Graph
	for(int i = -n; i <= n; i++) if(i != 0){
		for(int j = -n; j <= n; j++) v[j] = false;
		dfs(i);
		for(int j = -n; j <= n; j++) if(v[j]) give[i].pb(j), receive[j].pb(i);
	}

	// Check for each x
	for(int i = 1; i <= n; i++){
		bool got = false;
		for(int j: give[i]) if(j == -i){
			got = true; ans = min(ans, 1);
			if(obli[i] == 1) ans = 0;
		}

		for(int j: receive[i]) if(j == -i){
			ans = min(ans, 1);
			if(got or obli[i] == -1) ans = 0;
		}

		bool cg = false, cr = false;
		for(int z: give[i])     if(z < 0) cg = true;
		for(int z: receive[-i]) if(z > 0) cr = true;

		if(cg and cr) ans = min(ans, 2);
		if(cg and cr and obli[i] == 1) ans = min(ans, 1);
	}

	cout << (ans == INF ? -1 : ans) << endl;
	exit(0);
}
