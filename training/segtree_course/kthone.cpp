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
const int MAX = 1e5 + 2;

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

bool bb(int i, int k){
	if(seg::query(i,i) >= k) return true;
	return false;
}

int main(){ _
	int n, m; cin >> n >> m;
	int v[n];
	int a; cin >> v[0];
	for(int i = 1; i < n; i++){
		cin >> a; v[i] = v[i-1] + a;
	}
	seg::build(n, v);

	while(m--){
		int op; cin >> op;
		if(op == 1){
			int i; cin >> i;
			if((i == 0 and seg::query(i,i)) or (seg::query(i,i) > seg::query(i-1, i-1)))
				seg::update(i, n-1, -1);
			else
				seg::update(i, n-1, 1);
		}
		else{
			int k; cin >> k; k++;
			int l = 0, r = n-1;
			while(l < r){
				int mid = (l+r)/2;
				if(bb(mid,k)) r = mid;
				else l = mid+1;
			}
			cout << l << endl;
		}
	}

	exit(0);
}
