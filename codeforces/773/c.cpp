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
	int tt; cin >> tt;
	while(tt--){
		ll n, x; cin >> n >> x;
		map<ll, int> m;
		for(int i = 0; i < n; i++){
			ll a; cin >> a;
			m[a]++;
		}
		ll ans = 0;
		for(auto [k, v]: m){
			if(v == 0) continue;
			if(!m.count(k*x)) m[k*x] = 0;
			
			if(m[k*x] >= v) m[k*x] -= v;
			else{
				ans += v - m[k*x];
				m[k*x] = 0;
			}
			m[k] = 0;
		}
		cout << ans << endl;
	}
	exit(0);
}
