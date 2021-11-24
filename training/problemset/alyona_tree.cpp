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

const int MAX = 2e5 + 50;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};


namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		seg::update(pos[a], pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}

// ___________________________________________________________________________

ll  b[MAX][32]; // b[i][j] = distancia do i para seu (2^j)ésimo ancestral
int p[MAX][32]; // p[i][j] = (2^j)ésimo ancestral de i

int bit_floor(ll x){ // Biggest pow of 2 smaller than x
	for(int i = 1; i < 32; i++){
		if((1LL << i) > x) return i-1;
	}
	return 31;
}

ll dist(int v, ll d){ // Distancia do v para seu d-ésimo ancestral
	if(d == 0)  return 0LL;
	if(v == -1) return INF;

	int    pw = bit_floor(d); // Greatest possible x given that 2^x <= d
	
	return b[v][pw] + dist(p[v][pw], d - (1LL << pw));
}

int anc(int v, ll d){
	if(d == 0) return v;

	int pw = bit_floor(d);
	return anc(p[v][pw], d - (1LL << pw));
}

int main(){ _
	int n; cin >> n;
	vector<int> v(n); for(int &i: v) cin >> i;
	
	p[0][0] = 0; b[0][0] = INF;
	for(int i = 1; i < n; i++){
		int a; cin >> a; a--;
		hld::g[a].pb(i); hld::g[i].pb(a);
		p[i][0] = a; 
		cin >> b[i][0];
	}
	hld::build();
	
	for(int j = 1; j < 32; j++) // Calculating binary lifting
		for(int i = 0; i < n; i++){
			p[i][j] = p[p[i][j-1]][j-1];
			b[i][j] = b[i][j-1] + b[p[i][j-1]][j-1];
		}
	
	for(int i = 1; i < n; i++){
		int left = 0, right = 2e5 + 50;
		while(left < right){
			int mid = (left + right + 1)/2;
			if(dist(i, mid) <= v[i]) left = mid;
			else right = mid-1;
		}
		// cout << "\nO " << i+1 << " sobe " << left << " caras!\n";
		int parent = anc(i, left);
		// cout << "Chegou no " << parent+1 << "\n";
		hld::update_path(i, parent, 1);
		hld::update_path(i, i, -1);
	}

	for(int i = 0; i < n; i++){
		cout << hld::query_path(i, i) << " ";
	} cout << endl;

	exit(0);
}
