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
const int MAX = 2e5 + 10;

int n, MOD;
ll dp[MAX];
ll dpSum[MAX];

int32_t main(){ _
	cin >> n >> MOD;

	dp[1] = 1, dpSum[1] = 1;
	for(int i = 2; i <= n; i++){
		// cout << "Processando o " << i << endl;
		dp[i] = dpSum[i-1] % MOD;
		
		for(int j = 2; j <= i; j++){
			int t  = i/j;
			int la = i/t;
			// cout << "Vou para o " << t << " de ";
			// cout << (la - j + 1) << " maneiras!" << endl;
			dp[i] += (dp[t] * (la - j + 1)) % MOD;
			j = la;
		}

		dpSum[i] = (dpSum[i-1] + dp[i]) % MOD;
	}
	
	cout << dp[n] % MOD << endl;
	exit(0);
}
