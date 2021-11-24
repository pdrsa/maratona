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
	ll a, b; cin >> a >> b;
	ll ans = 0;
	for(ll x = 1; x <= int(1e6 + 10); x++){
		ll start = (a % x ? a - (a % x) + x: a);
		for(ll i = start; i <= b; i += x){
			if(i/x > x) ans += (i/x) + x;
			else if(i/x == x) ans += x;
		}
	}
	cout << ans << endl;
	exit(0);
}
