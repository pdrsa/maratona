#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	
	int n;
	ll l; cin >> n >> l;

	n--;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	ll ans = LINF;
	for (int j = 1; j < n-1; j++) {
		int ii = lower_bound(v.begin(), v.end(), v[j]/2) - v.begin();
		int kk = lower_bound(v.begin(), v.end(), (v[j] + l)/2) - v.begin();
		
		int qt = 3;
		for (int i = max(ii-qt, 0); i < min(ii+qt, j); i++) {
			for (int k = max(kk-qt, j+1); k < min(kk+qt, n); k++) {
				ll maxi = max({v[i], v[j]-v[i], v[k]-v[j], l-v[k]});
				ll mini = min({v[i], v[j]-v[i], v[k]-v[j], l-v[k]});
				ans = min(ans, maxi-mini);
			}
		}
	}
	cout << ans << endl;

	exit(0);
}
