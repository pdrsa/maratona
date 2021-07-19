//JP - Not in Kansas Anymore
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Centroid decomposition
// O(n log(n))

int n;
vector<vector<int>> g(MAX);

vector<int> subsize(MAX);
vector<bool> rem(MAX);

void dfs(int k, int prev) {
	subsize[k] = 1;
	for (int i : g[k])
		if (i != prev and !rem[i]) {
			dfs(i, k);
			subsize[k] += subsize[i];
		}
}

int centroid(int k, int prev, int size) {
	for (int i : g[k]) {
		if (rem[i] or i == prev) continue;
		if (subsize[i] > size / 2)
			return centroid(i, k, size);
	}

	// K = Centroid
	return k;
}

// Distance from centroid


vector<vector<ii>> dist(MAX);
void dfs_dist(int i, int cf, int prev = -1, int d = 1) {
	dist[cf].push_back({d, i});
	for (int j : g[i]) if (j != prev and !rem[j])
        dfs_dist(j, cf, i, d+1);
}


ll decomp(int k, int x) {
	ll ans = 0;

	dfs(k, k);

	// Find and get Centroid
	int c = centroid(k, k, subsize[k]);
	rem[c] = true;
	
	ord_set<ii> s;
	s.insert({0, c});
	// Computing
	for(int cf: g[c]) if(!rem[cf]){
		dist[cf].clear();
		dfs_dist(cf, cf);

		for(auto [d, v]: dist[cf])
			ans += s.order_of_key({x - d, INF});
		
		for(auto p: dist[cf]) s.insert(p);
	}
	
	// Recursion for subtrees
	for (int i : g[c]) if (!rem[i]) ans += decomp(i, x);

	return ans;
}

ll go(int x) {
	rem.assign(MAX, false);
	dist.assign(MAX, vector<ii>());
	subsize.assign(MAX, 1);

	return decomp(0, x);
	//for (int i = 0; i < n; i++) reverse(dist[i].begin(), dist[i].end());
}

int main(){ _
	// #warning FILE IN 
    freopen("awesome.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		for(auto &a: g) a.clear();
		int l, r; cin >> n >> l >> r;
		for(int i = 1; i < n; i++){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b), g[b].pb(a);
		}
		
		cout << go(n-1-l) -  go(n-1-r-1) << endl;
	}


	exit(0);
}
