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
const int MAX = 1e3 + 10;

ll dp[MAX][MAX];
vector<int> cost(MAX);
int n, k;

ll solve(int i, int j){
	if(i >= k) return 0;

	
	if(dp[i][j] != -1) return dp[i][j];

	ll ans = 0;
	for(int t = j; t < n; t++) ans = max(ans, solve(i+1, t) + cost[t]);

	return dp[i][j] = ans;
}

int main(){ _
	cin >> n >> k;

	for(int i = 0; i < n; i++) cin >> cost[i];

	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) dp[i][j] = -1;

	cout << solve(0, 0) << endl;
	exit(0);
}
