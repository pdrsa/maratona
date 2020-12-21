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
int n, m;
vector<vector<int>> g;
vector<int> dp;

int bfs(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];

	int ans = 0;
	for(auto u: g[i]){
		ans = max(bfs(u)+1, ans);
	}
	return dp[i] = ans;
}

int main(){ _
	cin >> n >> m;
	g = vector<vector<int>>(n);
	dp = vector<int>(n, -1);
	while(m--){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b);
	}
	for(int i = 0; i < n; i++) bfs(i);

	int ans = 0;
	for(int i: dp) ans = max(i,ans);

	cout << ans << endl;
	exit(0);
}
