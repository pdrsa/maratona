//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll direction(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> origin) {
  return ((a.f-origin.f) * (b.s-origin.s)) - ((a.s-origin.s) * (b.f-origin.f));
}

int32_t main(){ _
	int n; cin >> n;
	vector<pair<ll, ll>> p(n); for(auto &[x, y]: p) cin >> x >> y;
	ll ans = LINF;
	for(int i = 0; i < n; i++)
		ans = min(ans, direction(p[i], p[(i+1) % n], p[(i+2) % n]));
	cout << ans << endl;
	exit(0);
}
