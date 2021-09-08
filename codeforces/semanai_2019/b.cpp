#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll ans = (n % 4 == 1 or n % 4 == 2);
		for (ll p = 2, ct = 1; ct < 60; p *= 2, ct++) {
			ll here = n / p;
			if (here % 2 == 0) continue;
			else if (n % 2 == 0) ans += (1ll << ct);
		}

		cout << ans << endl;
	}

	exit(0);
}
