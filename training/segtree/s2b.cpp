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

// JP - Not in Kansas Anymore

// Segtree with Lazy Propagation

// Build  - O(n)
// Update - O(log n) <-- Update on range _ Update is operation
// Query  - O(log n)

struct Segtree{
	int ROOT = 1;
	ll  id   = LINF; // Neutral element
	int sz;

	vector<ll> tree;
	vector<ll> lazy;
	
	// Operation
	ll op(ll a, ll b){ return min(a, b);};

	void push(int node){ // Propagates Lazyness to Children
		tree[node*2] += lazy[node]; tree[node*2+1] += lazy[node];
		lazy[node*2] += lazy[node]; lazy[node*2+1] += lazy[node];
		lazy[node] = 0;
	}

	void build(vector<ll> v){
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
			tree[node] += v;
			lazy[node] += v;
			return;
		} else if(n_high < q_low or  n_low  >  q_high) return; // Not modified
		
		push(node);
		int mid  = (n_low + n_high)/2; // MId Point of Interval
		update(node*2,   n_low, mid,    q_low, q_high, v);
		update(node*2+1, mid+1, n_high, q_low, q_high, v);

		tree[node] = op(tree[2*node], tree[2*node+1]); // Join halves
	}


	ll query(int node, int n_low, int n_high, int q_low, int q_high){		
		if(n_low >= q_low and n_high <= q_high) return tree[node]; // Inside
		if(n_high < q_low or  n_low  >  q_high) return id; // Neutral Element
		
		push(node);
		int mid  = (n_low + n_high)/2; // MId Point of Interval
		return op(query(node*2,   n_low, mid,    q_low, q_high),
			      query(node*2+1, mid+1, n_high, q_low, q_high)); // Join halves
	}

	// Friendly
	void build(int size){ build(vector<ll>(size)); };
	void update(int low, int high, ll v){update(ROOT, 0, sz-1, low, high, v);}
	ll query(int low, int high){return query(ROOT, 0, sz-1, low, high);}
};


int32_t main(){ _
	int n, q; cin >> n >> q;
	// vector<ll> a(n); for(ll &i: a) cin >> i;
	Segtree seg; seg.build(n);
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int l, r, v; cin >> l >> r >> v;
			seg.update(l, r-1, v);
		}else{
			int l, r; cin >> l >> r;
			cout << seg.query(l, r-1) << endl;
		}
	}
	exit(0);
}
