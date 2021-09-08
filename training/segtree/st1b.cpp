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

// Segtree

// Build  - O(n)
// Update - O(log n) <-- Update on leaf
// Query  - O(log n)

struct Segtree{
	int ROOT = 1;
	int id   = LINF; // Neutral element
	int sz;

	vector<ll> tree;
	
	// Operation
	ll op(ll a, ll b){ return min(a,b); };

	void build(vector<ll> v){
		sz = v.size();
		while(__builtin_popcount(sz) != 1){
			sz++;
			v.pb(id);
		}

		tree.resize(2 * sz);
		for(int i = 0; i < sz; i++)
			tree[sz + i] = v[i]; // Leaves
		for(int i = sz-1; i >= ROOT; i--)
			tree[i] = op(tree[2*i], tree[2*i+1]); // Segments
	}

	void update(int i, int x){
		tree[sz+i] = x;
		for(int j = (sz+i)/2; j >= ROOT; j /= 2)
			tree[j] = op(tree[j*2], tree[j*2+1]);
	}

	ll query(int node, int n_low, int n_high, int q_low, int q_high){		
		if(n_low >= q_low and n_high <= q_high) return tree[node]; // Inside
		if(n_high < q_low or  n_low  >  q_high) return id; // Neutral Element

		int mid  = (n_low + n_high)/2; // MId Point of Interval
		return op(query(node*2,   n_low, mid,    q_low, q_high),
			      query(node*2+1, mid+1, n_high, q_low, q_high)); // Join halves
	}

	// Friendly
	ll query(int low, int high){return query(ROOT, 0, sz-1, low, high);}
	void build(int size){ build(vector<ll>(size, id)); };
};


int32_t main(){ _
	int n, q; cin >> n >> q;
	vector<ll> v(n); for(ll &i: v) cin >> i;
	Segtree seg; seg.build(v);
	while(q--){
		int t, x, y; cin >> t >> x >> y;
		if(t == 1) seg.update(x, y);
		else cout << seg.query(x, y-1) << endl;
	}
	exit(0);
}
