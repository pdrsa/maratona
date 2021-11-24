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

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		vector<ll> v(n); for(ll &i: v) cin >> i;
		for(int i = 0; i < n-1; i++) seg[n+i]   = abs(v[i] - v[i+1]);
		for(int i = 0; i < n; i++) seg[i] = 0LL;
		for(int i = 2*n - 1; i < 3*n and i < MAX; i++) seg[i] = 0LL;
		build();

		int ans = 0;
		for(int i = 0; i < n - 1; i++){
			int l = 0, r = n - i - 1;
			while(l < r){
				int m = (l+r+1) / 2;
				if(query(i, i + m - 1) >= 2) l = m;
				else r = m - 1;
			}

			ans = max(ans, l);
		}
		cout << ans + 1 << endl;
	}
	exit(0);
}
