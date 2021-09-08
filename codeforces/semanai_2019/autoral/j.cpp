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

int32_t main(){ _
	int n;
	ll s; 
	cin >> n >> s;  n--;
	vector<ll> c(n); for(ll &i : c) cin >> i;

	ll ans = LINF;
	for(int i = 1; i < n-1; i++){
		int left = lower_bound(c.begin(), c.end(),
		c[i]/2) - c.begin();

		int right = lower_bound(c.begin(), c.end(),
		(c[i] + s)/2) - c.begin();

		for(int l = max(0, left-1); l < min(i, left+1); l++)
			for(int r = max(i+1, right-1); r < min(n, right+1); r++)
				ans = min(ans,
				max({c[l], c[i]-c[l], c[r] - c[i], s - c[r]}) -
				min({c[l], c[i]-c[l], c[r] - c[i], s - c[r]}));
	}

	cout << ans << endl;
	exit(0);
}
