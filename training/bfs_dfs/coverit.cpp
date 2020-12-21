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
vector<int> d;


void dfs(int x){
	for(int z: g[x]){
		if(d[z] == -1){
			d[z] = d[x] + 1;
			dfs(z);
		}
	}
}


int main(){ _
	int tt; cin >> tt;
	while(tt--){
		
		int n; cin >> n;
		g = vector<vector<int>>(n);
		d = vector<int>(n, -1);

		int m; cin >> m;
		while(m--){
			int a; cin >> a;
			int b; cin >> b;
			a--;b--;
			g[a].pb(b); g[b].pb(a);
		}
		
		d[0] = 1;
		dfs(0);

		vector<vector<int>> par(2);

		for(int i = 0; i < n; i++){
			if(d[i] % 2 == 0) par[0].pb(i);
			else par[1].pb(i);
		}
		
		vector<int> ans;
		if(par[0].size() < par[1].size()) ans = par[0];
		else ans = par[1];

		cout << ans.size() << endl;
		for(int i:ans) cout << i+1 << " ";

		
		cout << endl;
	}
	exit(0);
}
