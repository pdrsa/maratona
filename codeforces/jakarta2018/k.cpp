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
const int MAX = 1e6 + 50;

set<int> g[MAX];
set<int> og[MAX];
vector<bool> v(MAX);

map<int, int> dict;

vector<tuple<int, int, int>> ans;
int sz;

set<int> delDel[MAX];
void makeTree(int x, int pai){
	v[x] = true;
	for(int u: og[x]) if(!delDel[x].count(u)){
		if(!v[u]){
			g[x].insert(u), g[u].insert(x);
			makeTree(u, x);
		} else if(pai != u){
			delDel[u].insert(x);
			g[x].insert(sz), g[sz].insert(x);
			dict[sz] = u;
			sz++;
		}
	}
}

set<int> del[MAX];
void dfs(int x, int pai){
	v[x] = true;
	for(int u: g[x]) if(!v[u] and !del[x].count(u)) dfs(u, x);

	vector<int> children;
	for(int u: g[x])
		if(u != pai and !del[x].count(u))
			children.pb(u);
	int n = children.size();
	
	if(n){
		for(int i = 0; i < n; i += 2)
			if(i+1 < n)
				ans.emplace_back(dict[children[i]], dict[x], dict[children[i+1]]);
		if(pai >= 0 and n%2 == 1){
			ans.emplace_back(dict[children.back()], dict[x], dict[pai]);
			del[pai].insert(x);
		}
	}
}


int32_t main(){ _
	int n, m; cin >> n >> m;
	for(int l = 0; l < m; l++){
		int a, b; cin >> a >> b;
		a--, b--;
		og[a].insert(b), og[b].insert(a);
	}
	
	sz = n;
	for(int i = 0; i < n; i++){
		dict[i] = i;
		if(!v[i])
			makeTree(i, -1);
	}
	
	v.assign(MAX, false);
	for(int i = 0; i < sz; i++) if(!v[i]) dfs(i, -1);

	cout << ans.size() << endl;
	for(auto [x, y, z]: ans) cout << x+1 << " " << y+1 << " " << z+1 << endl;
	exit(0);
}
