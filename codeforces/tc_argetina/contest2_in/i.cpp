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

int m;

int sum(vector<int> &x, int mask){
	int ans = 0;
	for(int i = 0; i < x.size(); i++)
		if((1 << i) & mask)
			ans += x[i], ans %= m;
	
	return ans % m;
}

int main(){ _
	int n; cin >> n >> m;
	vector<int> v(n); for(int &i: v) cin >> i;
	
	vector<int> a, b;
	for(int i = 0; i < n/2; i++) a.pb(v[i]);
	for(int i = n/2; i < n; i++) b.pb(v[i]);
	
	vector<int> suma, sumb;
	for(int mask = 0; mask < (1 << a.size()); mask++)
		suma.pb(sum(a, mask));

	for(int mask = 0; mask < (1 << b.size()); mask++)
		sumb.pb(sum(b, mask));
	
	int ans = 0;
	sort(sumb.begin(), sumb.end());
	sort(suma.begin(), suma.end());
	for(int i: sumb) ans = max(ans, i);
	for(int i: suma) ans = max(ans, i);

	for(int i: suma){
		int idx = lower_bound(sumb.begin(), sumb.end(), (m - i - 1)) - sumb.begin();
		if(idx >= sumb.size()) continue;

		else ans = max(ans, (i + sumb[idx]));
	}

	cout << ans << endl;
	exit(0);
}
