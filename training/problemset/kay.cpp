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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 3e5 + 50;

vector<int> g[MAX];

set<pair<int, int>> f[MAX];

vector<int> sz(MAX, 1);
vector<int> cent(MAX);

int dfsSz(int x){ // Save sizes of subtrees
	for(int u: g[x]) sz[x] += dfsSz(u);
	return sz[x];
}

void add(int x, int u){
	if(f[u].size() > f[x].size()) f[x].swap(f[u]);
	for(auto i: f[u]) f[x].insert(i);
}

void dfs(int x){
	for(int u: g[x]){ // Merge children
		dfs(u);
		add(x, u);
		set<pair<int, int>>().swap(f[u]);
	}
	f[x].insert({sz[x], x}); // Insert myself

	// Find answer
	pair<int, int> center = {sz[x]/2, INF};
	auto ans = *f[x].upper_bound(center);

	cent[x] = ans.s;
}

int main(){ _
	int n, q; cin >> n >> q;
	for(int i = 1; i < n; i++){
		int pai; cin >> pai;
		pai--; g[pai].pb(i);
	}
	dfsSz(0);
	dfs(0);
	while(q--){
		int a; cin >> a;
		a--;
		cout << cent[a] + 1 << endl;
	}

	exit(0);
}
