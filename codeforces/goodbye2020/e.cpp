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
const ll MOD  = 1e9+7;
const int BIT = 61;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		
		vector<vector<bool>> v(n, vector<bool> (BIT));
		vector<int> s(BIT);

		// Calculating a bitmask for each number and sums
		for(int j = 0; j < n; j++){
			ll a; cin >> a;
			for(int i = 0; i < 61; i++){
				v[j][i] = (a%2);
				s[i] += v[j][i];

				a >>= 1;
			}
		}

		ll ans = 0;	
		// Let's fix each j
		for(int j = 0; j < n; j++){
			ll sand = 0, sor = 0;
			for(int i = 0; i < BIT; i++){
				
				// And
				if(v[j][i]) sand += ((1LL << i) % MOD) * s[i];
				// Or
				sor += ((1LL << i) % MOD) * (v[j][i] ? n : s[i]);
				
				sor %= MOD; sand %= MOD;
			}

			// Update Answer
			ans += ((sand * sor) % MOD);
			ans %= MOD;
		}

		cout << ans << endl;
	}
	exit(0);
}
