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
const ll MOD = 1e9+7;

int n, k;
ll pairChoose;

ll fpow(ll x, ll y, ll m) { // recursivo
	if (!y) return 1;
	ll ans = fpow(x*x%m, y/2, m);
	return y%2 ? x*ans%m : ans;
}

ll solve(ll i){
	if(i == 0) return 1;
	// Impar
	if(n % 2 == 1) return fpow((pairChoose + 1), i, MOD);
	// Par
	else{
		if(i == 1) return pairChoose+1;

		ll ans = fpow(fpow(2, n, MOD), i-1, MOD); // I win on i then whatever
		return (ans + (pairChoose * solve(i-1)) % MOD) % MOD; // Sum draws
	}
}

int main(){ _
	int tt; cin >> tt;
	
	while(tt--){
		cin >> n >> k;
		pairChoose = fpow(2, n-1, MOD);
		if(n % 2 == 0) pairChoose--;
		cout << solve(k) % MOD << endl;
	}

	exit(0);
}
