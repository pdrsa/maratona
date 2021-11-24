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
const int MOD = 1e9+7;

int32_t main(){ _
	int tt; cin >> tt;
	for(int t = 0; t < tt; t++){
		int n; cin >> n;
		string s; cin >> s;
		vector<ll> dp(n+1);
		char last = s[0];
		int lastidx = 0;
		for(int i = 1; i < n; i++){
			dp[i] = dp[i-1];
			if(s[i] != last and s[i] != 'F' and last != 'F') dp[i] += lastidx + 1;
			if(s[i] == 'O') last = 'O';
			if(s[i] == 'X') last = 'X';
			if(s[i] != 'F') lastidx = i;
			
			dp[i] %= MOD;
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			ans += dp[i]; ans %= MOD;
		}
		cout << "Case #" << t+1 << ": " << ans % MOD << endl;
	}
	exit(0);
}
