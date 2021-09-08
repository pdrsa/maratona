#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

ll inv(ll a, ll b = MOD) {
	return a > 1 ? b - inv(b%a, a) * b / a : 1;
}

const int MAX = 5e6+10;

ll fat[MAX];
ll ifat[MAX];

ll choose(int a, int b) {
	return fat[a] * ifat[b] % MOD * ifat[a-b] % MOD;
}

int main(){ _
	int t; cin >> t;
	fat[0] = 1;
	for (int i = 1; i<MAX; i++) fat[i] = i * fat[i-1] % MOD;
	ifat[MAX-1] = inv(fat[MAX-1]);
	for (int i = MAX-2; i+1; i--) ifat[i] = ifat[i+1]*(i+1) % MOD;

	vector<ll> p2(MAX);
	p2[0] = 1;
	for (int i = 1; i < MAX; i++) p2[i] = p2[i-1] * 2 % MOD;

	int x = 5e6;
	ll ix = inv(p2[x]);
	vector<int> v(x+1);		
	ll ans = 0;
	for (int i = 0; i <= x; i++) {
		ans += choose(x, i) * ix % MOD;
		ans %= MOD;

		v[i] = ans;
	}


	while (t--){
		int k; cin >> k;

		cout << v[x-k] << endl;
	}

	exit(0);
}
