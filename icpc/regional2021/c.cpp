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
const int MAX = 2e5 + 50;

ll MOD;

vector<ll> rem(MAX), alg(MAX), bEi(MAX);

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

int32_t main(){ _
	ll b, n; cin >> b >> n;
	MOD = b+1;
	
	bEi[0] = 1LL;
	for(int i = 1; i < MAX; i++) bEi[i] = (b * bEi[i-1]) % MOD;

	// MOD = 1e9 + 7;
	for(int i = 0; i < n; i++) cin >> alg[i];
	
	// Calculate Number
	rem[n] = 0;
	for(int i = n-1; i >= 0; i--){
		rem[i] = rem[i+1] + (alg[i] * (bEi[n-i-1] % MOD)) % MOD;
		rem[i] %= MOD;
	}

	ll bigNum = rem[0];
	if(bigNum % MOD == 0){
		cout << 0 << " " << 0 << endl;
		exit(0);
	}

	// Try for each
	for(int i = 0; i < n; i++){
		ll resto = (bigNum - (alg[i] * bEi[n-i-1] % MOD)) % MOD;
		resto %= MOD; resto += MOD; resto %= MOD;

		ll y = MOD - resto; // Quem eu quero
		ll x = y * inv(bEi[n-i-1], MOD);
		x %= MOD;
		if(alg[i] > x){
			cout << i+1 << " " << x << endl;
			exit(0);
		}
	}

	cout << -1 << " " << -1 << endl;
	exit(0);
}
