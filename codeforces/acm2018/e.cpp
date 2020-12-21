#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9+7;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<ll> a(n); for(ll &i:a) cin >> i;
		ll ans = a[0]-1;
		ll aux = a[0];
		for(int i = 1; i < n; i++){
			ans *= a[i]; ans %= MOD;
			ans += (a[i]-1) * aux;
			ans %= MOD;
			aux *= a[i];
			aux %= MOD;
		}

		cout << ans << endl;
	}
	exit(0);
}
