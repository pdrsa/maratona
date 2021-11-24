//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// JP - Not in Kansas Anymore

struct Segtree{
	int ROOT = 1;
	pair<ll, ll> id = {LINF, LINF}; // Neutral element
	int sz;

	vector<pair<ll, ll>> tree;
	vector<ll> lazy;
	
	// Operation
	pair<ll, ll> op(pair<ll, ll> a, pair<ll, ll> b){
		if(a.f < b.f) return a;
		if(b.f < a.f) return b;
		if(a.s > b.s) return a;
		return b;
	}
	// (Update operation is set to sum, change it in code if needed)

	void push(int node){ // Propagates Lazyness to Children
		tree[node*2].f += lazy[node]; tree[node*2+1].f += lazy[node];
		lazy[node*2]   += lazy[node]; lazy[node*2+1]   += lazy[node];
		lazy[node] = 0;
	}

	void build(vector<pair<ll, ll>> v){
		sz = v.size();
		while(__builtin_popcount(sz) != 1){
			sz++;
			v.pb(id); // This can be avoided
		}

		tree.resize(2 * sz);
		lazy.resize(2 * sz);
		for(int i = 0; i < sz; i++)
			tree[sz + i] = v[i]; // Leaves
		for(int i = sz-1; i >= ROOT; i--)
			tree[i] = op(tree[2*i], tree[2*i+1]); // Segments
	}

	void update(int node, int n_low, int n_high, int q_low, int q_high, ll v){		
		if(n_low >= q_low and n_high <= q_high){ // Leaf
			tree[node].f += v;
			lazy[node]   += v;
			return;
		} else if(n_high < q_low or  n_low  >  q_high) return; // Not modified

		push(node);
		int mid  = (n_low + n_high)/2; // MId Point of Interval
		update(node*2,   n_low, mid,    q_low, q_high, v);
		update(node*2+1, mid+1, n_high, q_low, q_high, v);

		tree[node] = op(tree[2*node], tree[2*node+1]); // Join halves
	}


	pair<ll, ll> query(int node, int n_low, int n_high, int q_low, int q_high){		
		if(n_low >= q_low and n_high <= q_high) return tree[node]; // Inside
		if(n_high < q_low or  n_low  >  q_high) return id; // Neutral Element
		
		push(node);
		int mid  = (n_low + n_high)/2; // Mid Point of Interval
		return op(query(node*2,   n_low, mid,    q_low, q_high),
			      query(node*2+1, mid+1, n_high, q_low, q_high)); // Join halves
	}

	// Friendly
	void update(int low, int high, ll v){update(ROOT, 0, sz-1, low, high, v);}
	pair<ll, ll> query(int low, int high){return query(ROOT, 0, sz-1, low, high);}
};


int32_t main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<int>> g(n);
		vector<ll> deg(n);

		vector<pair<ll, ll>> construct(n);
		for(int i = 0; i < n; i++)
			construct[i] = {i, i};
		
		while(m--){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b);
			construct[b].f--;
		}
		
		Segtree seg;
		seg.build(construct);
		for(int kkk = 0; kkk < n; kkk++){
			auto [degree, v] = seg.query(0, n);
			cout << v+1 << " ";
			seg.update(v+1, n, -1);
			for(int u: g[v]) seg.update(u, u, 1LL);
			seg.update(v, v, LINF);
		}
		cout << endl;
	}
	exit(0);
}
