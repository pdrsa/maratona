//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef int ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void fail(){
	cout << "NO" << endl;
	exit(0);
}

vector<ll> p;
vector<int> sz;

ll find(ll x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

bool uni(ll x, ll y){
	x = find(x), y = find(y);
	if(x == y) return false;

	if(sz[x] > sz[y]) swap(x, y);
	p[x] = y;
	
	return true;
}

vector<ii> g[2010]; // Vizinho, peso
vector<ll> d;

ll original[2010][2010];
ll dis[2010][2010];
tuple<ll, ll, ll> ed[2010 * 2010];

void dfs(int x){
	for(auto [u, dist]: g[x]) if(d[u] == -1){
		d[u] = d[x]+dist;
		dfs(u);
	}
}

int main(){ _
	int n; cin >> n;
	
	// Vector of Edges
	int idx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll di; cin >> di;
			original[i][j] = di;
			if(i != j and di == 0) fail();
			if(i == j and di != 0) fail();
			ed[idx] = make_tuple(di, i, j);
			idx++;
		}
	}
	
	sz.assign(n, 1);
	p.resize(n);
	iota(p.begin(), p.end(), 0);

	sort(ed, ed + idx);
	// Construct MST
	for(int i = 0; i < n*n; i++){
		auto [di, a, b] = ed[i];
		if(uni(a, b)) g[a].pb({b, di}), g[b].pb({a, di});
	}

	// Check distances
	for(int v = 0; v < n; v++){
		d.assign(n, -1);
		d[v] = 0LL;
		dfs(v);
		for(int i = 0; i < n; i++) dis[v][i] = d[i];
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dis[i][j] != original[i][j]) fail();
	
	cout << "YES" << endl;
	exit(0);
}
