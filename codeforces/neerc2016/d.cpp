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


vector<ll> sol(ll m){
  if(m == 0) return vector<ll>();
  else if(m == 1) return vector<ll>(1,1);

  else if(m % 2 == 0){
    vector<ll> p = sol(m/2);
	for(ll &x: p) x *= 2;
	return p;
  }

  else{
    ll t = 3;
    while(3 * t <= m) t *= 3;
    vector<ll> p = sol(m - t);
	p.push_back(t);
    return p;
  }

}

int32_t main(){ _
	freopen("distribution.in",  "r",stdin);
	freopen("distribution.out", "w",stdout);
	int tt; cin >> tt;
	while(tt--){
		ll a; cin >> a;
		auto ans = sol(a);
		cout << ans.size() << endl;
		for(ll x: ans) cout << x << " ";
		cout << endl;
	}
	exit(0);
}
