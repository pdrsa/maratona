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
const int MAX = 1e4;

struct Segtree{
	int ROOT = 1;
	ll  id   = 0; // Neutral element
	int sz;

	vector<ll> tree;
	vector<ll> lazy;

	// Operation
	ll op(ll a, ll b){ return a+b; };
	// (Update operation is set to sum, change it in code if needed)

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
		int mid  = (n_low + n_high)/2; // Mid Point of Interval
		return op(query(node*2,   n_low, mid,    q_low, q_high),
			      query(node*2+1, mid+1, n_high, q_low, q_high)); // Join halves
	}

	// Friendly
	void build(int size){ build(vector<ll>(size, id)); };
	void update(int low, int high, ll v){update(ROOT, 0, sz-1, low, high, v);}
	ll query(int low, int high){return query(ROOT, 0, sz-1, low, high);}
};

int32_t main(){ _
    // Reading
    int n; cin >> n;
    vector<pair<int, int>> c(n);
    vector<int> all;
    for(auto &[a, b]: c){
        cin >> b >> a;
        all.pb(a), all.pb(b);
    }
    sort(all.begin(), all.end());

    // Compression
	map<ll, ll> comp, uncomp;
    int aux = 0;
    for(int x: all){
        if(not comp.count(x)){
            comp[x] = aux;
            uncomp[aux] = x;
            aux++;
        }
    }
    for(auto &[a, b]: c)
        a = comp[a], b = comp[b];
    
    // Processing
    sort(c.begin(), c.end());
    Segtree seg;
    seg.build(MAX);
    
    vector<bool> vis(n);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        auto [b, a] = c[i];
        
        int x = 0;
        if(seg.query(a,a) >= seg.query(b, b)) x = b;
        else x = a;
        for(int j = 0; j < n; j++){
            auto [bb, aa] = c[j];
            if(aa <= x and bb >= x){
                vis[j] = true;
                seg.update(aa, bb, 1LL);
            }
        }
        ans.pb(x);
    }
    
    // Printing
    cout << ans.size() << endl;
    for(int x: ans) cout << uncomp[x] << " ";
    cout << endl;

    exit(0);
}
