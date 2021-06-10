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
const ll MAX  = 1e5 + 10;
const ll MOD  = 1e9 + 7;

ll mod(ll x, ll N){
	return (x % N + N) % N;
}

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}


int main(){ _
	// #warning FILE IN
	freopen("lcm.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<ll> oc(MAX);
		vector<ll> t(MAX);
		while(n--){
			int a; cin >> a;
			oc[a]++;
		}

		for(ll i = 1; i < MAX; i++){
			ll sum = 0;
			
			// Sum of all multiples
			for(ll j = i; j < MAX; j += i){
				sum  += oc[j] * j;sum %= MOD;
			}
			
			// Summation of multiples times sum
			for(ll j = i; j < MAX; j += i){
				t[i] += ((oc[j] * j) % MOD) * sum;  t[i] %= MOD;
			}
			
		}
		
		ll ans = 0;

		// Inclusion Exclusion
		for(ll i = MAX - 1; i > 0; i--){
			for(ll j = 2 * i; j < MAX; j += i){
				t[i] -= t[j];
				t[i]  = mod(t[i], MOD);
			}
			
			// We've calculated multiplications, now we divide by GCD
			ans += t[i] * inv(i, MOD);
			ans = mod(ans, MOD);
		}

		cout << ans << endl;
	}
	exit(0);
}
