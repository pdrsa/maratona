//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5e6 + 10;
const int MOD = 1e9+7;
const int M = 5e6;

ll fat[MAX];
ll ifat[MAX];

ll dp[MAX];

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

// A escolhe B
ll choose(ll a, ll b){
	if(a < b) return 0;
	return fat[a] * ifat[b] % MOD * ifat[a-b] % MOD;
}

int32_t main(){ //_
	int tt; cin >> tt;
	
	// Fat
	fat[0] = 1;
	for(int i = 1; i < MAX; i++)
		fat[i] = fat[i-1] * i % MOD;

	// InvFat
	ifat[MAX-1] = inv(fat[MAX - 1], MOD);
	for(int i = MAX - 2; i >= 0; i--)
		ifat[i] = ifat[i+1]*(i+1) % MOD;

	// Answer
	dp[0] = 1;
	for(int i = 1; i < MAX; i++)
		dp[i] = (dp[i-1] + choose(M, i)) % MOD;

	// 2 ^ M
	ll x = 1;
	for(int i = 0; i < M; i++){
		x *= 2;
		x %= MOD;
	}
	// inv(2^M)
	ll ix = inv(x, MOD);

	while(tt--){
		int n; cin >> n;
		cout << (dp[M - n] * ix) % MOD << endl;
	}
	exit(0);
}
