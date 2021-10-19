// Código de Bernardo Amorim

// Declara com tamanho - Segtree(n)
// Update em índice- O(log n)
// Query  - O(log n)

struct Segtree {
	int n;
	vector<int> seg;
	
	// Build com tamanho
	Segtree(int n_) : n(n_), seg(2 * n_, 0) {}
	// Build com vetor
	Segtree (const vector<int>& v) : n(v.size()), seg(2 * v.size()) {
   		for (int i = 0; i < n; i++) seg[n + i] = v[i];
   		for (int i = n - 1; i >= 1; i--) seg[i] = seg[2 * i] + seg[2 * i + 1];
	}

	int query(int l, int r) {
		int ret = 0;
		for (l += n, r += n; l <= r; ++l /= 2, --r /= 2) {
			if (l % 2 == 1) ret += seg[l];
			if (r % 2 == 0) ret += seg[r];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2 * p] + seg[2 * p + 1];
	}
};
 
