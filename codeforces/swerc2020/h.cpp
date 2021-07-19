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

const int MAX = 3e4+10, UPD = 2e5+10, LOG = 20;
const int MAXS = 4*MAX+UPD*LOG;

namespace perseg {
	ll seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n, *v;

	ll build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	ll query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = seg[lp]+x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int main(){ _
	int n; cin >> n;
	perseg::build(n+1);
	cin.ignore();
	vector<int> di(n+5);

	for(int a = 1; a <= n; a++){
		string s; getline(cin, s);
		char c;
		stringstream ss(s);
		di[a] = di[a-1];
		while(ss >> c){
			// cout << c << endl;
			if(c == '+'){
				int x; ss >> x;
				di[a] = perseg::update(x, 1);
			}
			if(c == '-'){
				int x; ss >> x;
				di[a] = perseg::update(x, -1);
			}
		}
	}
	
	int ans = 0;
	for(int a = 0; a < n; a++){
		int d; cin >> d;
		ans += perseg::query(ans, n+1, di[d]);
		ans %= n;
	}
	cout << ans << endl;

	exit(0);
}
