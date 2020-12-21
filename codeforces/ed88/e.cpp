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
const ll MOD  = 998244353;

ll fat[500001];
ll invfat[500001];

ll inv(ll a, ll b){
	if(1 < a) return b - inv(b % a, a) * b/a;
	else return 1;
}

ll nek(ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;

    ll result = ((fat[n]*invfat[k]) % MOD) * invfat[n-k];

    return result % MOD;
}

void build(){
	fat[0] = 1;
	invfat[0] = inv(fat[0],MOD);
	for (ll i = 1; i < 500001; i++){
		fat[i]    = (fat[i-1] * i) % MOD;
		invfat[i] = inv(fat[i], MOD);
	}
}

int main(){ _
	build();

	ll n , k; cin >> n >> k;
	
	if(k == 1){
		cout << n << endl;
		exit(0);
	}

	ll ans = 0;
	for(ll i = 1; i <= n and n/i >= k; i++){
		ll a = n/i;
		ans += nek(a-1, k-1);
		ans %= MOD;
	}

	cout << ans % MOD << endl;
	exit(0);
}
