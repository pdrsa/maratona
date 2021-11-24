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
const int MAX = 5e5 + 50;

vector<int> g[MAX];

vector<int> c(MAX, -1);
vector<int> p(MAX);
vector<int> sz(MAX);
set<int> s[MAX];
vector<int> mem[MAX];

int find(int x){
	return p[x] = (x == p[x] ? x : find(p[x]));
}

bool merge(int x, int y){
	if(find(x) == find(y)) if(c[x] != c[y]) return false;

	if(sz[x] < sz[y]) swap(x, y);

	bool rev = false;

	if(c[x] == -1 or c[y] == -1){
		if(c[x] != -1) c[y] = (1 - c[x]);
		else c[x] = 0, c[y] = 1;
	}

	if(c[x] == c[y]) rev = true;

	sz[find(y)] += sz[find(y)];
	p[find(y)] = p[find(x)];
	for(int u: mem[y]){
		mem[x].pb(u);
		if(rev) c[u] = (1 - c[u]);
	}

	return true;
}

int32_t main(){ _
	int n, m; cin >> n >> m;

	vector<pair<int, int>> ab;
	vector<int> w;
	vector<tuple<int, int, int>> edg;
	
	for(int i = 0; i < MAX; i++) p[i] = i;

	while(m--){
		int a, b, wi; cin >> a >> b >> wi;
		a--, b--;
		ab.pb({a, b});
		w.pb(wi);
	}
	
	vector<int> vv = w;
	vector<int> ov = w;

	sort(ov.begin(), ov.end());
	ov.resize(unique(ov.begin(), ov.end()) - ov.begin());
	for (int& i : w)
		i = lower_bound(ov.begin(), ov.end(), i) - ov.begin();
	
	for(int i = 0; i < int(w.size()); i++) edg.pb({w[i], ab[i].first, ab[i].second});
	sort(edg.rbegin(), edg.rend());

	int prev = -1;
	int ans = 0;

	bool tt = false;
	bool err = false;
	for(int i = 0; i < int(edg.size()); i++){
		auto [ww, a, b] = edg[i];
		s[ww].insert(a), s[ww].insert(b);

		if(ww != prev){
			if(err) break;
			tt = true;
			prev = ww;
		}
		
		if(tt){
			if(s[ww].size() >= 4){
				ans++; tt = false;
			}
		}
		if(!merge(a, b)) err = true;
	}

	sort(vv.rbegin(), vv.rend());
	int last = -1;

	cout << ans << endl;

	exit(0);
}
