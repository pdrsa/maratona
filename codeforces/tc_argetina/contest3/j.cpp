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

ll exp(ll a, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll e) {
    return exp(e, MOD - 2);
}

int main(){ _
	ll n, m, c; cin >> n >> m >> c;
	ll sq = exp(c, (n * n)); // Number of different squares
	ll ans = 0;

	// We're gonna use Burnside's Lemma to get average of Symmetries
	for(ll i = 1; i <= m; i++){
		// Nº of Symmetries for each transformation is (sq^sim)
		ll sim = __gcd(i, m); // sim is the gcd of n of rotations and m
		ans += exp(sq, sim);
		ans %= MOD;
	}
	
	// Divide by m
	ans *= inv(m);
	ans %= MOD;

	cout << ans << endl;
	exit(0);
}
