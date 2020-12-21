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
const int MAX = 1e3 + 2;

// Heavy-Light Decomposition sem Update
//
// query de min do caminho
//
// Complexidades:
// build - O(n)
// query_path - O(log(n))

#define f first
#define s second


namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
	int men[MAX], seg[2*MAX];

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.f != p) {
			sobe[i.f] = i.s; pai[i.f] = k;
			h[i.f] = (i == g[k][0] ? h[k] : i.f);
			men[i.f] = (i == g[k][0] ? min(men[k], i.s) : i.s);
			build_hld(i.f, k, f); sz[k] += sz[i.f];

			if (sz[i.f] > sz[g[k][0].f] or g[k][0].f == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		for (int i = 0; i < t; i++) seg[i+t] = v[i];
		for (int i = t-1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}

	int query_path(int a, int b) {
		if (a == b) return INF;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] != h[b]) return min(men[a], query_path(pai[h[a]], b));
		int ans = INF, x = pos[b]+1+t, y = pos[a]+t;
		for (; x <= y; ++x/=2, --y/=2) ans = min({ans, seg[x], seg[y]});
		return ans;
	}

	int lca(int a, int b){
		if (a == b) return a;
		if (pos[a] < pos[b]) swap(a,b);
		
		return (h[a] == h[b] ? b : lca(b, pai[h[a]]));
	}
};

int main(){ _
	int tt; cin >> tt;
	for(int ttt = 1; ttt <= tt; ttt++){
		cout << "Case " << ttt << ":" << endl;
		int n; cin >> n;
		for(int i = 0; i < n; i++) hld::g[i].clear();
		for(int i = 0; i < n; i++){
			int z; cin >> z;
			while(z--){
				int aux; cin >> aux; aux--;
				hld::g[i].pb({aux, 1});
			}
		}

		hld::build();

		int q; cin >> q;
		while(q--){
			int a, b; cin >> a >> b; a--; b--;
			cout << hld::lca(a,b) + 1 << endl;
		}
	}
	exit(0);
}
