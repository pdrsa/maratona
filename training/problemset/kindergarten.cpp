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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6 + 50;

ll dp[MAX];

int main(){ _
	int n; cin >> n;
	vector<ll> g(n); for(ll &i: g) cin >> i;
	dp[0] = 0;
	ll bestMini = 0 - g[0], bestMaxi = 0 + g[0];
	for(int i = 1; i < n; i++){
		dp[i]    = max({dp[i-1], bestMini + g[i], bestMaxi - g[i]});
		bestMini = max(bestMini, dp[i-1] - g[i]);
		bestMaxi = max(bestMaxi, dp[i-1] + g[i]);
	}
	
	cout << dp[n-1] << endl;
	exit(0);
}
