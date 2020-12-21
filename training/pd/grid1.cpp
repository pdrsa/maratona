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
const ll MOD = 1e9+7;

int n, m;
vector<vector<bool>> g;
vector<vector<ll>> dp;

ll solve(int i, int j){
	if(i == n-1 and j == m-1) return 1;
	if(i >= n or j >= m) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int a = (i + 1 < n and g[i+1][j]);
	int b = (j + 1 < m and g[i][j+1]);

	if(a) a = solve(i+1, j);
	if(b) b = solve(i, j+1);

	return dp[i][j] = ((a % MOD) + (b % MOD)) % MOD;
}

int main(){ _
	cin >> n >> m;
	g = vector<vector<bool>> (n, vector<bool>(m));
	dp = vector<vector<ll>> (n, vector<ll>(m, -1));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) g[i][j] = (s[j] == '.');
	}
	
	cout << solve(0,0) << endl;
	exit(0);
}
