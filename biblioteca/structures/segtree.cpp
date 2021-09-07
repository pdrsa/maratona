// JP - Not in Kansas Anymore

// Segtree

// Build  - O(n)
// Update - O(log n) <-- Update on leaf
// Query  - O(log n)

struct Segtree{
	int ROOT = 1;
	int id   = 0; // Neutral element
	int sz;

	vector<ll> tree;
	
	// Operation
	ll op(ll a, ll b){ return a+b; };

	void build(vector<int> v){
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
	void build(int size){ build(vector<int>(size, id)); };
};
