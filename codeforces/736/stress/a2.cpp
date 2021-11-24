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

const int MAX = 200100;

ll seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = __gcd(seg[2*i], seg[2*i+1]);
}

ll query(int a, int b) {
	ll ret = 0LL;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = __gcd(ret, seg[a]);
		if (b % 2 == 0) ret = __gcd(ret, seg[b]);
	}
	return ret;
}

void update(int p, int x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = __gcd(seg[2*p], seg[2*p+1]);
}

int32_t main(){ //_
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		vector<ll> v(n); for(ll &i: v) cin >> i;
		for(int i = 0; i < n-1; i++) seg[n+i]   = abs(v[i] - v[i+1]);
		for(int i = 0; i < n; i++) seg[i] = 0LL;
		for(int i = 2*n - 1; i < 3*n and i < MAX; i++) seg[i] = 0LL;

		build();
		int l = 0, r = n - 1;
		while(l < r){
			int m = (l+r+1)/2;
			bool ok = false;
			for(int i = 0; i < n-m; i++)
				if(query(i, i + m - 1) >= 2) ok = true;
			if(ok) l = m;
			else r   = m - 1;
		}
		cout << l + 1 << endl;
	}
	exit(0);
}
