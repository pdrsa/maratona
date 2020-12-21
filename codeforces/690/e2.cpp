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
const ll MOD  = 1e9 + 7;
const int MAX = 2e5 + 20;
vector<ll> facto(MAX);

ll inv(ll a, ll b = MOD) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll fact(ll x){
	return facto[x];
}

ll comb(ll x, ll y){
	if(x < y) return 0;
	if(x == y) return 1;

	ll ans = fact(x);
	
	ll div = (fact(x-y) * fact(y));
	div = div % MOD;
	
	return (ans * inv(div)) % MOD;
}

int main(){ _
	ll tt; cin >> tt;
	
	facto[0] = 1; facto[1] = 1;
	for(int i = 2; i < MAX; i++){
		facto[i] = (facto[i-1] * i) % MOD;
	}

	//cout << fact(tt) << endl;
	//exit(0);

	while(tt--){

		ll n, m, k; cin >> n >> m >> k;
		
		vector<ll> a(n); for(ll &i: a) cin >> i;
		
		sort(a.begin(), a.end());
		//for(auto i: a) cout << i << " ";
		//cout << endl;

		ll l = 0, r = 0;
		ll ans = 0;
		ll pastc = 0;

		while(r < n){
			ll old = l;
			while(l < n and r > 0 and a[l] == a[old]) l++;
			ans -= comb(pastc - (l - old), m);
			
			if(ans <= 0) ans += MOD;
			ans %= MOD;

			while(r < n and a[r] - a[l] <= k) r++;
			pastc = r-l;
			ans += comb(pastc, m);

			ans %= MOD;
		}

		cout << ans % MOD << endl;
	}
	exit(0);
}
