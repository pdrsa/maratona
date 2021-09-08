//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define int ll

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9+7;

int n, k;
vector<int> fat(2e5 + 10);

ll mod(ll a, ll b){
	return (b + (a%b)) % b;
}

ll fpow(ll x, ll y, ll m) { // recursivo
	if (!y) return 1;
	ll ans = fpow(x*x%m, y/2, m);
	return y%2 ? x*ans%m : ans;
}

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll pairChoose;

ll comb(int c, int r){
	if(r == c or r == 0) return 1;
	if(r > c) return 0;

	return mod((fat[c] * inv(mod((fat[r] * fat[(c-r)]), MOD), MOD)), MOD);
}

ll solve(ll i){
	if(i == 0) return 1;
	

	// Impar
	if(n % 2 == 1) return mod(fpow((pairChoose+1), i, MOD), MOD);

	// Par
	else{
		ll ans = mod(fpow(fpow(2, n, MOD), i-1, MOD), MOD);
		if(i == 1) return mod((ans + pairChoose), MOD);
		return mod(ans + mod((pairChoose * solve(i-1)), MOD), MOD);
	}
}

int32_t main(){ _
	int tt; cin >> tt;
	
	while(tt--){
		cin >> n >> k;
		fat[0] = 1;
		for(int i = 1; i < int(2e5+5); i++) fat[i] = mod((fat[i-1] * i), MOD);
		
		// Calculate pairChoose
		pairChoose = 1; // 1 =  Não escolhe nada
		for(int i = 2; i < n; i += 2){
			pairChoose += comb(n, i);
			pairChoose = mod(pairChoose, MOD);
		}
		// pairChoose %= MOD;
		// cout << pairChoose << endl;

		cout << mod(solve(k), MOD) << endl;
	}

	exit(0);
}

